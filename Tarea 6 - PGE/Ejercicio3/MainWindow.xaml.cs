using System;
using System.Collections.ObjectModel;
using System.Windows;
using System.Windows.Controls;

namespace Ejercicio3
{
    public partial class MainWindow : Window
    {
        // Colección enlazada al DataGrid
        private ObservableCollection<Gasto> gastos = new ObservableCollection<Gasto>();

        public MainWindow()
        {
            InitializeComponent();

            // Cargar opciones en el ComboBox
            comboBox.Items.Add("USD");
            comboBox.Items.Add("EUR");
            comboBox.Items.Add("ARS");
            comboBox.SelectedIndex = 0;

            // Enlazar DataGrid a la colección de gastos
            dataGrid.ItemsSource = gastos;

            // Asignar eventos a los botones
            button.Click += button_Click;   // Agregar gasto
            button1.Click += button1_Click; // Conversión
        }

        // Agregar gasto a la lista
        private void button_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrWhiteSpace(textBox.Text) || string.IsNullOrWhiteSpace(textBox_Copiar.Text))
            {
                MessageBox.Show("Complete la descripción y el valor del gasto.");
                return;
            }

            if (!double.TryParse(textBox_Copiar.Text, out double valor))
            {
                MessageBox.Show("Ingrese un número válido en el campo de gasto.");
                return;
            }

            string moneda = comboBox.SelectedItem?.ToString() ?? "ARS";

            gastos.Add(new Gasto
            {
                Descripcion = textBox.Text,
                Valor = valor,
                Moneda = moneda
            });

            // Limpiar inputs
            textBox.Clear();
            textBox_Copiar.Clear();
        }

        // Calcular total convertido
        private void button1_Click(object sender, RoutedEventArgs e)
        {
            if (comboBox.SelectedItem == null) return;

            string monedaDestino = comboBox.SelectedItem.ToString();

            double totalLocal = 0;
            foreach (var g in gastos)
                totalLocal += g.Valor;

            // Tasas de conversión (ejemplo fijo)
            double tasa = 1;
            switch (monedaDestino)
            {
                case "USD": tasa = 0.0012; break;
                case "EUR": tasa = 0.0011; break;
                case "ARS": tasa = 1; break;
            }

            double totalConvertido = totalLocal * tasa;
            textBox1.Text = $"{totalConvertido:F2} {monedaDestino}";
        }
    }

    // Clase para los registros de gasto
    public class Gasto
    {
        public string Descripcion { get; set; }
        public double Valor { get; set; }
        public string Moneda { get; set; }
    }
}
