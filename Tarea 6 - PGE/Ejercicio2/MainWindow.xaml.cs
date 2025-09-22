using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Shapes;

namespace Ejercicio2
{
    public partial class MainWindow : Window
    {
        private bool isDrawing = false;
        private Point previousPoint;
        private Brush selectedBrush = Brushes.Black;
        private double brushThickness = 2;

        public MainWindow()
        {
            InitializeComponent();

            // Cargar colores en el ComboBox
            comboBox.Items.Add("Negro");
            comboBox.Items.Add("Rojo");
            comboBox.Items.Add("Verde");
            comboBox.Items.Add("Azul");
            comboBox.Items.Add("Amarillo");

            comboBox.SelectedIndex = 0; // valor por defecto
            comboBox.SelectionChanged += ComboBox_SelectionChanged;

            // Configurar slider de grosor
            slider.Minimum = 1;
            slider.Maximum = 20;
            slider.Value = 2;
            slider.ValueChanged += Slider_ValueChanged;

            // Eventos del canvas
            dibujoCanvas.MouseDown += Canvas_MouseDown;
            dibujoCanvas.MouseMove += Canvas_MouseMove;
            dibujoCanvas.MouseUp += Canvas_MouseUp;
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            switch (comboBox.SelectedItem.ToString())
            {
                case "Rojo": selectedBrush = Brushes.Red; break;
                case "Verde": selectedBrush = Brushes.Green; break;
                case "Azul": selectedBrush = Brushes.Blue; break;
                case "Amarillo": selectedBrush = Brushes.Yellow; break;
                default: selectedBrush = Brushes.Black; break;
            }
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            brushThickness = slider.Value;
        }

        private void Canvas_MouseDown(object sender, MouseButtonEventArgs e)
        {
            isDrawing = true;
            previousPoint = e.GetPosition(dibujoCanvas);
        }

        private void Canvas_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDrawing)
            {
                Point currentPoint = e.GetPosition(dibujoCanvas);

                Line line = new Line
                {
                    Stroke = selectedBrush,
                    StrokeThickness = brushThickness,
                    X1 = previousPoint.X,
                    Y1 = previousPoint.Y,
                    X2 = currentPoint.X,
                    Y2 = currentPoint.Y
                };

                dibujoCanvas.Children.Add(line);
                previousPoint = currentPoint;
            }
        }

        private void Canvas_MouseUp(object sender, MouseButtonEventArgs e)
        {
            isDrawing = false;
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            // Borra todos los elementos dibujados en el Canvas
            dibujoCanvas.Children.Clear();
        }

    }
}
