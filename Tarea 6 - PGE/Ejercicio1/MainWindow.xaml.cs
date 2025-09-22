using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Ejercicio1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            try{
                double celsius = double.Parse(textBox.Text);

                double fahrenheit = (celsius * 9 / 5) + 32;

                textBox_Copiar.Text = fahrenheit.ToString("F2") + "F";
            }
            catch (FormatException)
            { 
                MessageBox.Show("Por favor ingrese un número válido en Celsius.",
                                "Error de formato", MessageBoxButton.OK, MessageBoxImage.Error);
            
            }
        }
 
    }
}