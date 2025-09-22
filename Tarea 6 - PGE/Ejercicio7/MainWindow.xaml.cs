using System;
using System.Windows;

namespace Ejercicio7
{
    public partial class MainWindow : Window
    {
        private int numeroSecreto;
        private Random random = new Random();

        public MainWindow()
        {
            InitializeComponent();
            ReiniciarJuego();
        }

        private void ReiniciarJuego()
        {
            numeroSecreto = random.Next(1, 101); // número entre 1 y 100
            lblMensaje.Content = "Ingresa un número del 1 al 100";
            txtIntento.Clear();
        }

        private void btnAdivinar_Click(object sender, RoutedEventArgs e)
        {
            if (int.TryParse(txtIntento.Text, out int intento))
            {
                if (intento < numeroSecreto)
                {
                    lblMensaje.Content = "El número secreto es mayor.";
                }
                else if (intento > numeroSecreto)
                {
                    lblMensaje.Content = "El número secreto es menor.";
                }
                else
                {
                    lblMensaje.Content = $"¡Correcto! El número era {numeroSecreto}";
                }
            }
            else
            {
                MessageBox.Show("Por favor, ingresa un número válido.");
            }
        }

        private void btnReiniciar_Click(object sender, RoutedEventArgs e)
        {
            ReiniciarJuego();
        }
    }
}
