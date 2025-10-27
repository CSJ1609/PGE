# 📝 Tarea 7 - PGE (Caja de Herramientas Segura — .NET MAUI)

## 📌Objetivo
Trabajo práctico en .NET MAUI para practicar manejo de excepciones, validación de entradas y registro de errores en archivo local.
Se amplía la aplicación base para incorporar cuatro módulos: Calculadora Segura, Gestor de Archivos, Login Simulado y Panel de Excepciones.

## 🚀 Funcionalidades implementadas
 **🔢Calculadora Segura v2**
- Operaciones: suma, resta, multiplicación, división, potencia y raíz cuadrada.
- Validación de entradas numéricas.
- Manejo de errores con try/catch y lanzamiento de excepciones (throw).
- Excepciones controladas:
- DivideByZeroException
- ArgumentOutOfRangeException
- FormatException
- Registro de errores y operaciones en log.txt.
  
**📂 Gestor de Archivos v2**
- Apertura de archivos con FilePicker.
- Duplicado de archivos con validación de nombre y confirmación de sobrescritura.
- Actualización de información del archivo: nombre, tamaño y fecha.
- Manejo de excepciones de E/S:
**FileNotFoundException**,
**UnauthorizedAccessException**,
**IOException**.

**🔐 Login Simulado v2**
- Control de intentos de inicio de sesión con bloqueo tras tres fallos.
- Simulación de errores de red y de tiempo:
  - **HttpRequestException**
  - **TaskCanceledException**
- Registro de eventos de login en el log:
  - **success**
  - **credencial incorrecta**
  - **bloqueo**
  - **timeout / red**

**⚙️ Panel de Excepciones v2**
- Simulación de errores comunes:
  - **NullReferenceException**
  - **IndexOutOfRangeException**
- Ejemplos seguros con validaciones y guard clauses.
- Registro de simulaciones en el archivo log.txt.

## 💡 Interacción con GPT
Ejemplo de prompt utilizado:
> “Quiero hacer una caja de herramientas segura en .NET MAUI que maneje excepciones, valide datos y registre errores en un archivo. ¿Podés darme un ejemplo completo con try/catch y mensajes seguros?”

**Respuesta:** 
El asistente mostró ejemplos con try/catch, ArgumentOutOfRangeException, validaciones en Entry y cómo guardar logs con File.AppendAllTextAsync.

**Adaptaciones realizadas:**
- Cambié nombres y diseño de los controles.
- Agregué validaciones personalizadas y mensajes más claros.
- Incorporé el registro local de errores y bloqueos en el login.
- Integré las cuatro partes del trabajo en una sola aplicación funcional.

---
