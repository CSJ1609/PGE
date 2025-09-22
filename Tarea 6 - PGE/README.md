# 📝 Tarea 6 - PGE (Ejercicios en WPF)

## 📌 Objetivo
El objetivo de esta tarea fue **desarrollar ejercicios en WPF (Windows Presentation Foundation)**, practicando la creación de interfaces gráficas con **XAML**, el manejo de **eventos**, y la separación entre interfaz y lógica de negocio.  
WPF introduce un modelo más moderno respecto a WinForms y Win32, con soporte para **data binding**, **estilos** y **layouts flexibles**.

## 📂 Contenido
La carpeta incluye ejercicios que exploran:
- Definición de interfaces en **XAML**.  
- Manejo de eventos en C# (ej.: `Click`, `TextChanged`).  
- Uso de **layouts dinámicos** (Grid, StackPanel, DockPanel).  
- Aplicación de **estilos y plantillas**.  
- Ejemplos de **binding de datos** entre controles y variables.  

## 🛠️ Archivos principales
- `MainWindow.xaml` → interfaz principal declarada en XAML.  
- `MainWindow.xaml.cs` → código asociado para manejar eventos.  
- Archivos de recursos adicionales (si corresponden).  
- `.csproj` del proyecto WPF.  

## 🚀 Cómo compilar / ejecutar
1. Abrir el proyecto en **Visual Studio**.  
2. Asegurarse de que esté seleccionada la configuración de **WPF App (.NET Framework o .NET Core, según corresponda)**.  
3. Compilar y ejecutar con `F5`.  

El proyecto abrirá una ventana principal (`MainWindow`) con los ejercicios implementados.

## 💡 Interacción con GPT/Copilot
Durante el desarrollo se consultaron los siguientes puntos:
- **Prompt ejemplo:**  
  *“¿Cómo hago un binding en WPF entre un TextBox y un Label para que muestren el mismo texto en tiempo real?”*  
- **Respuesta recibida:**  
  Código de ejemplo con `{Binding}` y `INotifyPropertyChanged`.  
- **Adaptaciones realizadas:**  
  - Se usaron bindings simples en XAML.  
  - Se probaron eventos directos (`TextChanged`) para entender la diferencia con el modelo de binding.  
- **Aprendizajes:**  
  - Diferencias entre manejar eventos directamente vs. usar data binding.  
  - Ventajas de XAML para separar la interfaz de la lógica.  
  - Introducción al patrón **MVVM**, aunque en los ejercicios solo se exploraron bases.  

## 🎯 Conclusiones
Los ejercicios permitieron ver cómo **WPF** ofrece un modelo más moderno y flexible frente a WinForms:  
- Interfaces más adaptables gracias a los layouts.  
- Uso de XAML para separar presentación y lógica.  
- Data binding como herramienta poderosa para reducir código repetitivo.  

Esto marca un paso importante en la evolución de las tecnologías de interfaces en .NET.
