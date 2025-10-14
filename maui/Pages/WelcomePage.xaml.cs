using System;
using Microsoft.Maui.Controls;

namespace CyberSpeechApp.Pages;

public partial class WelcomePage : ContentPage
{
    public WelcomePage()
    {
        InitializeComponent();
    }

    private async void OnStartTapped(object? sender, EventArgs e)
    {
        // Navigate to Accessibility choice page
        await Shell.Current.GoToAsync(Routes.Accessibility);
    }
}
