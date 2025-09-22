using System;
using System.Collections.Generic;
using System.Windows;

namespace Ejercicio10
{
    public partial class MainWindow : Window
    {
        private Dictionary<string, double> unidades = new Dictionary<string, double>()
        {
            // Longitud (base = metro)
            {"Metros", 1},
            {"Kilómetros", 1000},
            {"Centímetros", 0.01},
            {"Milímetros", 0.001},

            // Peso (base = gramo)
            {"Gramos", 1},
            {"Kilogramos", 1000},
            {"Miligramos", 0.001}
        };

        public MainWindow()
        {
            InitializeComponent();

            // Cargar unidades en los ComboBox
            foreach (var unidad in unidades.Keys)
            {
                comboBoxOrigen.Items.Add(unidad);
                comboBoxDestino.Items.Add(unidad);
            }

            comboBoxOrigen.SelectedIndex = 0;
            comboBoxDestino.SelectedIndex = 1;
        }

        private void btnConvertir_Click(object sender, RoutedEventArgs e)
        {
            if (!double.TryParse(textBoxValor.Text, out double valor))
            {
                MessageBox.Show("Por favor, ingrese un número válido.", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }

            if (comboBoxOrigen.SelectedItem == null || comboBoxDestino.SelectedItem == null)
            {
                MessageBox.Show("Seleccione unidades de origen y destino.", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }

            string origen = comboBoxOrigen.SelectedItem.ToString();
            string destino = comboBoxDestino.SelectedItem.ToString();

            // Conversión
            double valorEnBase = valor * unidades[origen];
            double resultado = valorEnBase / unidades[destino];

            textBlockResultado.Text = $"{valor} {origen} = {resultado} {destino}";
        }
    }
}
