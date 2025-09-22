using Microsoft.Win32;
using System;
using System.IO;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Ejercicio5
{
    public partial class MainWindow : Window
    {
        // Ahora nullable para evitar la advertencia
        private BitmapImage? imagenOriginal;

        public MainWindow()
        {
            InitializeComponent();
        }

        // Cargar imagen
        private void btnCargar_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Filter = "Archivos de imagen|*.jpg;*.png;*.bmp";

            if (dlg.ShowDialog() == true)
            {
                imagenOriginal = new BitmapImage(new Uri(dlg.FileName));
                imgPreview.Source = imagenOriginal;
            }
        }

        // Cambiar tamaño con el slider
        private void sliderTamaño_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if (imgPreview != null)
            {
                imgPreview.LayoutTransform = new ScaleTransform(sliderTamaño.Value, sliderTamaño.Value);
            }
        }

        // Cambiar brillo con el slider (simulado con Opacity)
        private void sliderBrillo_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if (imgPreview != null)
            {
                // El valor del slider va de 0.5 a 2, lo normalizamos entre 0 y 1
                double brillo = sliderBrillo.Value / 2.0;
                imgPreview.Opacity = brillo;
            }
        }

        // Aplicar cambios (en este caso ya se aplican en tiempo real)
        private void btnAplicar_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Cambios aplicados.");
        }

        // Guardar imagen procesada
        private void btnGuardar_Click(object sender, RoutedEventArgs e)
        {
            if (imgPreview.Source != null)
            {
                SaveFileDialog dlg = new SaveFileDialog();
                dlg.Filter = "PNG|*.png";

                if (dlg.ShowDialog() == true)
                {
                    var encoder = new PngBitmapEncoder();
                    encoder.Frames.Add(BitmapFrame.Create((BitmapSource)imgPreview.Source));

                    using (FileStream fs = new FileStream(dlg.FileName, FileMode.Create))
                    {
                        encoder.Save(fs);
                    }

                    MessageBox.Show("Imagen guardada correctamente.");
                }
            }
        }
    }
}

