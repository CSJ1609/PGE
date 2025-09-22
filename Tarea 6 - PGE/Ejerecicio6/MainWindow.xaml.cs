using System;
using System.Collections.Generic;
using System.Windows;

namespace Ejerecicio6
{
    public partial class MainWindow : Window
    {
        // Diccionario de tasas de conversión (ejemplo simple a USD)
        private Dictionary<string, double> tasas = new Dictionary<string, double>()
        {
            {"USD", 1.0},
            {"EUR", 0.92},
            {"ARS", 950.0},
            {"BRL", 5.2}
        };

        public MainWindow()
        {
            InitializeComponent();

            // Configurar ComboBox origen y destino (cuando los agregues en el XAML)
            comboOrigen.ItemsSource = tasas.Keys;
            comboDestino.ItemsSource = tasas.Keys;

            comboOrigen.SelectedIndex = 0;
            comboDestino.SelectedIndex = 1;
        }

        private void btnConvertir_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                double monto = double.Parse(txtMonto.Text);
                string origen = comboOrigen.SelectedItem.ToString();
                string destino = comboDestino.SelectedItem.ToString();

                // Convertir a USD primero y luego a la moneda destino
                double montoUSD = monto / tasas[origen];
                double convertido = montoUSD * tasas[destino];

                lblResultado.Text = $"{monto} {origen} = {convertido:F2} {destino}";
            }
            catch (Exception)
            {
                MessageBox.Show("Ingrese un valor válido en el monto.");
            }
        }
    }
}
