# UI inicial para .NET MAUI (CyberSpeech)

Este directorio contiene las páginas XAML y clases parciales listas para copiar dentro de tu proyecto .NET MAUI.

## Páginas incluidas
- `WelcomePage`: pantalla inicial con tu logo y botón/tap para continuar.
- `AccessibilityPage`: opciones de accesibilidad (ninguna, visual, auditiva/voz).
- `MainProgrammingPage`: placeholder para la interfaz de programación.
- `VisualModePage` y `AuditoryModePage`: placeholders para modos inclusivos.
- `Helpers/Routes.cs`: constantes de rutas para navegación con `Shell`.

## Cómo integrarlo en tu proyecto MAUI
1. Copia la carpeta `Pages` y `Helpers` a tu proyecto (mismo `namespace` o ajusta el `namespace`).
2. Agrega la imagen del logo en `Resources/Images/cyberspeech.png` dentro de tu proyecto. Coloca aquí el archivo que te entrego (`maui/Resources/Images/cyberspeech.png`).
3. En `AppShell.xaml.cs`, registra las rutas:

```csharp
Routing.RegisterRoute(Routes.Accessibility, typeof(Pages.AccessibilityPage));
Routing.RegisterRoute(Routes.MainProgramming, typeof(Pages.MainProgrammingPage));
Routing.RegisterRoute(Routes.VisualMode, typeof(Pages.VisualModePage));
Routing.RegisterRoute(Routes.AuditoryMode, typeof(Pages.AuditoryModePage));
```

4. Establece `WelcomePage` como página principal:

```csharp
public App()
{
    InitializeComponent();
    MainPage = new AppShell
    {
        Items =
        {
            new ShellContent
            {
                ContentTemplate = new DataTemplate(typeof(Pages.WelcomePage))
            }
        }
    };
}
```

O si prefieres navegar manualmente, podrías usar `MainPage = new NavigationPage(new Pages.WelcomePage());`.

5. Asegúrate de incluir el `namespace` correcto en XAML/CS si tu proyecto no es `CyberSpeechApp`.

## Recursos
- Copia tu logo a `Resources/Images/cyberspeech.png`. MAUI lo generará para todas las plataformas.

## Notas de accesibilidad iniciales
- La `WelcomePage` permite tocar cualquier lugar de la pantalla para continuar.
- Se añadieron descripciones semánticas para lectores de pantalla.
- Los botones tienen alto contraste. Ajusta colores según tu diseño.
