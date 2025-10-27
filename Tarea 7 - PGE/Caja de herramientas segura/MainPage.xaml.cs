namespace Caja_de_herramientas_segura;

public partial class MainPage : ContentPage
{
    readonly string logPath;
    string? currentFilePath;

    int failedAttempts = 0;
    const int maxFailedAttempts = 3;
    const int lockSeconds = 15;

    public MainPage()
    {
        InitializeComponent();
        logPath = Path.Combine(FileSystem.AppDataDirectory, "log.txt");
    }

    // Utilidades
    private double LeerNumero(Entry entry)
    {
        if (entry == null) throw new ArgumentNullException(nameof(entry));
        if (string.IsNullOrWhiteSpace(entry.Text)) throw new ArgumentException("Debe ingresar un numero.", nameof(entry));
        if (!double.TryParse(entry.Text, out double valor)) throw new FormatException("El valor ingresado no es numerico.");
        return valor;
    }

    private async Task MostrarResultado(double valor)
    {
        // Actualiza UI y registra
        LblResultado.Text = $"Resultado: {valor}";
        await File.AppendAllTextAsync(logPath, $"{DateTime.Now}: Operacion exitosa → {valor}{Environment.NewLine}");
    }

    private async Task ManejarError(Exception ex)
    {
        // Mensaje seguro al usuario y log completo
        LblResultado.Text = $"Error: {ex.Message}";
        await File.AppendAllTextAsync(logPath, $"{DateTime.Now}: ERROR → {ex}{Environment.NewLine}");
    }

    // Calculadora
    private async void OnSumaClicked(object sender, EventArgs e)
    {
        try
        {
            double a = LeerNumero(EntryNumero1);
            double b = LeerNumero(EntryNumero2);
            await MostrarResultado(a + b);
        }
        catch (Exception ex)
        {
            await ManejarError(ex);
        }
    }

    private async void OnRestaClicked(object sender, EventArgs e)
    {
        try
        {
            double a = LeerNumero(EntryNumero1);
            double b = LeerNumero(EntryNumero2);
            await MostrarResultado(a - b);
        }
        catch (Exception ex)
        {
            await ManejarError(ex);
        }
    }

    private async void OnMultiplicaClicked(object sender, EventArgs e)
    {
        try
        {
            double a = LeerNumero(EntryNumero1);
            double b = LeerNumero(EntryNumero2);
            await MostrarResultado(a * b);
        }
        catch (Exception ex)
        {
            await ManejarError(ex);
        }
    }

    private async void OnDivideClicked(object sender, EventArgs e)
    {
        try
        {
            double a = LeerNumero(EntryNumero1);
            double b = LeerNumero(EntryNumero2);
            if (b == 0) throw new DivideByZeroException("No se puede dividir por cero.");
            await MostrarResultado(a / b);
        }
        catch (Exception ex)
        {
            await ManejarError(ex);
        }
    }

    private async void OnPotenciaClicked(object sender, EventArgs e)
    {
        try
        {
            double a = LeerNumero(EntryNumero1);
            double b = LeerNumero(EntryNumero2);
            await MostrarResultado(Math.Pow(a, b));
        }
        catch (Exception ex)
        {
            await ManejarError(ex);
        }
    }

    private async void OnRaizClicked(object sender, EventArgs e)
    {
        try
        {
            double a = LeerNumero(EntryNumero1);
            if (a < 0) throw new ArgumentOutOfRangeException(nameof(a), "No se puede calcular la raiz de un numero negativo.");
            await MostrarResultado(Math.Sqrt(a));
        }
        catch (Exception ex)
        {
            await ManejarError(ex);
        }
    }

    // Gestor de archivos
    private async void OnAbrirArchivoClicked(object sender, EventArgs e)
    {
        try
        {
            var result = await FilePicker.PickAsync(new PickOptions { PickerTitle = "Selecciona un archivo" });
            if (result == null) return;

            string pickedPath = result.FullPath ?? string.Empty;
            if (string.IsNullOrEmpty(pickedPath))
            {
                string localName = Path.GetFileName(result.FileName) ?? $"picked_{Guid.NewGuid():N}";
                string localPath = Path.Combine(FileSystem.AppDataDirectory, localName);
                using (var source = await result.OpenReadAsync())
                using (var dest = File.Create(localPath))
                {
                    await source.CopyToAsync(dest);
                    await dest.FlushAsync();
                }
                pickedPath = localPath;
            }

            currentFilePath = pickedPath;
            BtnDuplicar.IsEnabled = true;
            UpdateFileInfo(currentFilePath);
            await File.AppendAllTextAsync(logPath, $"{DateTime.Now}: Archivo abierto → {currentFilePath}{Environment.NewLine}");
            LblResultado.Text = "Archivo cargado correctamente.";
        }
        catch (FileNotFoundException fnf) { await ManejarError(fnf); }
        catch (UnauthorizedAccessException uaEx) { await ManejarError(uaEx); }
        catch (IOException ioEx) { await ManejarError(ioEx); }
        catch (Exception ex) { await ManejarError(ex); }
    }

    private async void OnDuplicarClicked(object sender, EventArgs e)
    {
        if (string.IsNullOrEmpty(currentFilePath) || !File.Exists(currentFilePath))
        {
            LblResultado.Text = "No hay archivo activo para duplicar.";
            return;
        }

        try
        {
            string defaultName = Path.GetFileNameWithoutExtension(currentFilePath) + "_copia" + Path.GetExtension(currentFilePath);
            string nuevoNombre = await DisplayPromptAsync("Duplicar", "Nombre nuevo para el archivo (sin ruta):", initialValue: defaultName);
            if (string.IsNullOrWhiteSpace(nuevoNombre))
            {
                LblResultado.Text = "Operacion cancelada.";
                return;
            }

            nuevoNombre = Path.GetFileName(nuevoNombre);
            string destDir = Path.GetDirectoryName(currentFilePath) ?? FileSystem.AppDataDirectory;
            string destino = Path.Combine(destDir, nuevoNombre);

            if (File.Exists(destino))
            {
                bool sobre = await DisplayAlert("Sobrescribir", "El archivo destino ya existe. ¿Sobrescribir?", "Si", "No");
                if (!sobre)
                {
                    LblResultado.Text = "Operacion cancelada (no sobrescrito).";
                    return;
                }
            }

            using (var source = File.OpenRead(currentFilePath))
            using (var dest = File.Create(destino))
            {
                await source.CopyToAsync(dest);
                await dest.FlushAsync();
            }

            UpdateFileInfo(currentFilePath);
            await File.AppendAllTextAsync(logPath, $"{DateTime.Now}: Archivo duplicado → {destino}{Environment.NewLine}");
            LblResultado.Text = $"Archivo duplicado en: {destino}";
        }
        catch (FileNotFoundException fnf) { await ManejarError(fnf); }
        catch (UnauthorizedAccessException una) { await ManejarError(una); }
        catch (IOException ioEx) { await ManejarError(ioEx); }
        catch (Exception ex) { await ManejarError(ex); }
    }

    private void UpdateFileInfo(string path)
    {
        try
        {
            if (string.IsNullOrEmpty(path) || !File.Exists(path))
            {
                LblArchivoActual.Text = "(ninguno)";
                LblTamano.Text = "-";
                LblModificado.Text = "-";
                return;
            }

            var fi = new FileInfo(path);
            LblArchivoActual.Text = path;
            LblTamano.Text = fi.Length.ToString();
            LblModificado.Text = fi.LastWriteTime.ToString("g");
        }
        catch
        {
            LblArchivoActual.Text = path ?? "(ninguno)";
            LblTamano.Text = "-";
            LblModificado.Text = "-";
        }
    }

    // Login simulado
    private async void OnLoginClicked(object sender, EventArgs e)
    {
        string user = EntryUsuario.Text?.Trim() ?? string.Empty;
        string pass = EntryPassword.Text ?? string.Empty;

        if (string.IsNullOrEmpty(user) || string.IsNullOrEmpty(pass))
        {
            LblLoginStatus.Text = "Estado: Debes completar usuario y contrasena.";
            await LogLoginEvent(user, "validation");
            return;
        }

        try
        {
            LblLoginStatus.Text = "Estado: Intentando...";
            bool ok = await SimulateLoginAsync(user, pass);

            if (ok)
            {
                LblLoginStatus.Text = "Estado: Login correcto.";
                failedAttempts = 0;
                LblIntentos.Text = $"Intentos fallidos: {failedAttempts}";
                await LogLoginEvent(user, "success");
            }
            else
            {
                failedAttempts++;
                LblIntentos.Text = $"Intentos fallidos: {failedAttempts}";
                await LogLoginEvent(user, "credencial");
                LblLoginStatus.Text = "Estado: Usuario/contrasena incorrectos.";

                if (failedAttempts >= maxFailedAttempts)
                {
                    BtnLogin.IsEnabled = false;
                    LblLoginStatus.Text = $"Estado: Bloqueado {lockSeconds}s tras {failedAttempts} fallos.";
                    await LogLoginEvent(user, "bloqueo");
                    await Task.Delay(lockSeconds * 1000);
                    failedAttempts = 0;
                    BtnLogin.IsEnabled = true;
                    LblLoginStatus.Text = "Estado: Puedes intentar de nuevo.";
                    LblIntentos.Text = $"Intentos fallidos: {failedAttempts}";
                }
            }
        }
        catch (TaskCanceledException)
        {
            LblLoginStatus.Text = "Estado: Espera unos segundos e intentalo de nuevo.";
            await LogLoginEvent(user, "timeout");
        }
        catch (HttpRequestException)
        {
            LblLoginStatus.Text = "Estado: No pudimos comunicarnos con el servicio.";
            await LogLoginEvent(user, "red");
        }
        catch (Exception ex)
        {
            LblLoginStatus.Text = $"Estado: Error inesperado: {ex.Message}";
            await LogLoginEvent(user, "otro");
        }
    }

    private async Task<bool> SimulateLoginAsync(string user, string pass)
    {
        await Task.Delay(500);
        if (user.Equals("timeout", StringComparison.OrdinalIgnoreCase)) throw new TaskCanceledException("Simulated timeout");
        if (user.Equals("net", StringComparison.OrdinalIgnoreCase)) throw new HttpRequestException("Simulated network error");
        if (user == "user" && pass == "pass") return true;
        return false;
    }

    private async Task LogLoginEvent(string user, string tipo)
    {
        string entry = $"{DateTime.Now:O}: Login | Usuario='{user}' | Tipo='{tipo}'{Environment.NewLine}";
        await File.AppendAllTextAsync(logPath, entry);
    }

    // Panel de excepciones
    private async void OnSimulateNullRefClicked(object sender, EventArgs e)
    {
        try
        {
            string? s = null;
            int len = s!.Length; // forzar NullReferenceException
            await Task.CompletedTask;
        }
        catch (NullReferenceException nre)
        {
            await ManejarError(nre);
            await File.AppendAllTextAsync(logPath, $"{DateTime.Now}: Excepcion NullReferenceException simulada{Environment.NewLine}");
        }
        catch (Exception ex) { await ManejarError(ex); }
    }

    private async void OnFixNullRefClicked(object sender, EventArgs e)
    {
        string? s = null;
        if (s == null)
        {
            LblResultado.Text = "Ejemplo seguro: variable null detectada y abortada (guard clause).";
            await File.AppendAllTextAsync(logPath, $"{DateTime.Now}: Ejemplo seguro NullReference aplicado{Environment.NewLine}");
            return;
        }
        int len = s.Length;
        LblResultado.Text = $"Ejemplo seguro: longitud {len}";
        await File.AppendAllTextAsync(logPath, $"{DateTime.Now}: Ejemplo seguro NullReference ejecutado{Environment.NewLine}");
    }

    private async void OnSimulateIndexOutClicked(object sender, EventArgs e)
    {
        try
        {
            int[] arr = new int[] { 1, 2, 3 };
            int val = arr[5]; // indice fuera de rango
            await Task.CompletedTask;
        }
        catch (IndexOutOfRangeException iore)
        {
            await ManejarError(iore);
            await File.AppendAllTextAsync(logPath, $"{DateTime.Now}: Excepcion IndexOutOfRangeException simulada{Environment.NewLine}");
        }
        catch (Exception ex) { await ManejarError(ex); }
    }

    private async void OnFixIndexOutClicked(object sender, EventArgs e)
    {
        int[] arr = new int[] { 1, 2, 3 };
        int index = 5;
        if (index < 0 || index >= arr.Length)
        {
            LblResultado.Text = "Ejemplo seguro: indice invalido detectado y evitado.";
            await File.AppendAllTextAsync(logPath, $"{DateTime.Now}: Ejemplo seguro IndexOutOfRange aplicado{Environment.NewLine}");
            return;
        }
        int val = arr[index];
        LblResultado.Text = $"Ejemplo seguro: valor {val}";
        await File.AppendAllTextAsync(logPath, $"{DateTime.Now}: Ejemplo seguro IndexOutOfRange ejecutado{Environment.NewLine}");
    }
}
