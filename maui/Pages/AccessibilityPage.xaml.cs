using System;
using Microsoft.Maui.Controls;

namespace CyberSpeechApp.Pages;

public partial class AccessibilityPage : ContentPage
{
    public AccessibilityPage()
    {
        InitializeComponent();
    }

    private async void OnNoDisability(object? sender, EventArgs e)
    {
        await Shell.Current.GoToAsync(Routes.MainProgramming);
    }

    private async void OnVisual(object? sender, EventArgs e)
    {
        await Shell.Current.GoToAsync(Routes.VisualMode);
    }

    private async void OnAuditory(object? sender, EventArgs e)
    {
        await Shell.Current.GoToAsync(Routes.AuditoryMode);
    }
}
