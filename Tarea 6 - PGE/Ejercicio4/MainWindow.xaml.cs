using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace Ejercicio4
{
    public partial class MainWindow : Window
    {
        // Diccionario con las ventas por mes
        private Dictionary<string, int> ventasMensuales = new Dictionary<string, int>()
        {
            {"Enero", 120},
            {"Febrero", 80},
            {"Marzo", 150},
            {"Abril", 90},
            {"Mayo", 200},
            {"Junio", 170},
        };

        public MainWindow()
        {
            InitializeComponent();

            // Llenar ComboBox y ListBox
            foreach (var mes in ventasMensuales.Keys)
            {
                comboBox.Items.Add(mes);
                listBox.Items.Add($"{mes}: {ventasMensuales[mes]} ventas");
            }
        }

        // Evento del botón
        private void button_Click(object sender, RoutedEventArgs e)
        {
            if (comboBox.SelectedItem == null) return;

            string mesSeleccionado = comboBox.SelectedItem.ToString();
            int valor = ventasMensuales[mesSeleccionado];

            DibujarGrafico(mesSeleccionado, valor);
        }

        private void DibujarGrafico(string mes, int valor)
        {
            // Limpiar el Canvas antes de redibujar
            Canvas canvas = (Canvas)this.FindName("canvas");
            canvas.Children.Clear();

            // Escala para la altura de la barra
            double maxAltura = canvas.Height - 20;
            double altura = (valor / 200.0) * maxAltura; // suponemos que el máximo es 200

            // Dibujar la barra
            Rectangle barra = new Rectangle
            {
                Width = 80,
                Height = altura,
                Fill = Brushes.Orange
            };

            Canvas.SetLeft(barra, 50);
            Canvas.SetBottom(barra, 10);
            canvas.Children.Add(barra);

            // Etiqueta del mes
            TextBlock label = new TextBlock
            {
                Text = $"{mes} ({valor})",
                FontSize = 16
            };
            Canvas.SetLeft(label, 50);
            Canvas.SetTop(label, 10);
            canvas.Children.Add(label);
        }
    }
}
