using System;
using System.Windows;

namespace Ejercicio8
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            // Cargar opciones de propina en el ComboBox
            comboPropina.Items.Add("10%");
            comboPropina.Items.Add("15%");
            comboPropina.Items.Add("20%");
            comboPropina.SelectedIndex = 0; // por defecto 10%
        }

        private void btnCalcular_Click(object sender, RoutedEventArgs e)
        {
            if (double.TryParse(txtMonto.Text, out double monto))
            {
                // Obtener el porcentaje elegido
                string seleccionado = comboPropina.SelectedItem.ToString().Replace("%", "");
                double porcentaje = double.Parse(seleccionado) / 100.0;

                // Calcular propina y total
                double propina = monto * porcentaje;
                double total = monto + propina;

                lblResultado.Content = $"Propina: {propina:F2} | Total: {total:F2}";
            }
            else
            {
                MessageBox.Show("Ingrese un monto válido.");
            }
        }
    }
}
