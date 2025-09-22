using System;

namespace CajaHerramientasSegura;

public partial class MainPage : ContentPage
{
    public MainPage()
    {
        InitializeComponent();
    }

    private void OnSquareRootClicked(object sender, EventArgs e)
    {
        try
        {
            if (!double.TryParse(NumberEntry.Text, out double num))
                throw new FormatException("Debe ingresar un número válido.");

            if (num < 0)
                throw new ArgumentOutOfRangeException(nameof(num), "No se puede calcular la raíz de un número negativo.");

            double result = Math.Sqrt(num);
            ResultLabel.Text = $"Raíz cuadrada: {result}";
        }
        catch (Exception ex)
        {
            LogError(ex);
            ResultLabel.Text = $"Error: {ex.Message}";
        }
    }

    private void OnPowerClicked(object sender, EventArgs e)
    {
        try
        {
            if (!double.TryParse(NumberEntry.Text, out double num))
                throw new FormatException("Debe ingresar un número válido.");

            double result = Math.Pow(num, 2);
            ResultLabel.Text = $"Potencia (n^2): {result}";
        }
        catch (Exception ex)
        {
            LogError(ex);
            ResultLabel.Text = $"Error: {ex.Message}";
        }
    }

    private void LogError(Exception ex)
    {
        try
        {
            string logPath = Path.Combine(FileSystem.AppDataDirectory, "errors.log");
            File.AppendAllText(logPath, $"{DateTime.Now}: {ex}\n");
        }
        catch
        {
            // Silenciar para no romper la app
        }
    }
}

