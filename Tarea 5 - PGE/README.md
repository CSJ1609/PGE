# 📝 Tarea 5 - PGE (Interfaz adaptada a WinForms)

## 📌 Objetivo
El objetivo de esta tarea fue **adaptar la interfaz gráfica desarrollada en la Tarea 3 (Win32 API)** a **WinForms en C#**.  
El ejercicio buscó comparar el enfoque de programación manual en Win32 con las herramientas de alto nivel que ofrece WinForms para crear GUIs de manera más rápida y estructurada.

## 📂 Contenido
Esta carpeta contiene el proyecto en **C# con WinForms**, donde se replicaron las funcionalidades principales de la interfaz hecha en Win32:
- Creación de ventanas y controles (botones, cuadros de texto, menús).
- Manejo de **eventos** mediante el modelo de delegados y handlers (`Click`, `TextChanged`, etc.).
- Comparación entre el **bucle de mensajes manual** de Win32 y el **modelo de eventos automático** en WinForms.

## 🛠️ Archivos principales
- `Form1.cs` → código principal de la ventana adaptada.  
- `Form1.Designer.cs` → código generado automáticamente para la interfaz.  
- `Program.cs` → punto de entrada de la aplicación.  
- `ProyectoWinForms.csproj` → archivo de proyecto de Visual Studio.

## 🚀 Cómo compilar / ejecutar
1. Abrir el archivo `.sln` o `.csproj` en **Visual Studio**.  
2. Seleccionar configuración **Debug** o **Release**.  
3. Compilar y ejecutar con `F5`.  

WinForms se encarga del ciclo de vida de la ventana y del manejo de eventos, simplificando el trabajo que en Win32 se hacía manualmente.

## 💡 Interacción con GPT/Copilot
Durante la migración se consultaron temas como:
- **Prompt ejemplo:**  
  *“¿Cómo creo un botón en WinForms que muestre un mensaje al hacer clic?”*  
- **Respuesta recibida:**  
  Uso de `Button` con un `Click` handler en C#.  
- **Adaptaciones realizadas:**  
  - Replicar los nombres y funcionalidades de los controles de la versión Win32.  
  - Organizar el diseño de la ventana usando el diseñador visual y ajustes en código.  
- **Aprendizajes:**  
  - WinForms automatiza gran parte de la gestión de ventanas y mensajes.  
  - Los eventos se gestionan mediante **delegados**, lo que resulta más claro y mantenible.  
  - Comparar la verbosidad de Win32 con la facilidad de WinForms ayuda a entender la evolución de las APIs de Windows.

## 🎯 Conclusiones
La tarea permitió comprender las ventajas de trabajar con **WinForms** frente a Win32:  
- Menor complejidad en el manejo de eventos.  
- Mayor rapidez en la construcción de interfaces.  
- Posibilidad de reutilizar código estructurado en C#.  

Al mismo tiempo, permitió ver cómo los conceptos de eventos y controles siguen siendo los mismos, pero con una capa de abstracción más amigable.
