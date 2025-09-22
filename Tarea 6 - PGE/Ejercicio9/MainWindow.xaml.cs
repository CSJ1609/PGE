using Microsoft.Win32;
using System.IO;
using System.Windows;

namespace Ejercicio9
{
    public partial class MainWindow : Window
    {
        private double tamañoFuente = 16;

        public MainWindow()
        {
            InitializeComponent();
        }

        // Cargar archivo
        private void btnCargar_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Filter = "Archivos de texto|*.txt";

            if (dlg.ShowDialog() == true)
            {
                string contenido = File.ReadAllText(dlg.FileName);
                txtContenido.Text = contenido;
            }
        }

        // Aumentar tamaño de letra
        private void btnAumentar_Click(object sender, RoutedEventArgs e)
        {
            tamañoFuente += 2;
            txtContenido.FontSize = tamañoFuente;
        }

        // Disminuir tamaño de letra
        private void btnDisminuir_Click(object sender, RoutedEventArgs e)
        {
            if (tamañoFuente > 8)
            {
                tamañoFuente -= 2;
                txtContenido.FontSize = tamañoFuente;
            }
        }
    }
}
