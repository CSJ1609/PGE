using System.Collections.Specialized;
using System.Windows.Forms;

namespace UISteam
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void toolStripMenuItem7_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            // vacío (no hace nada)
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Enter) // si presiona Enter
            {
                string texto = textBox1.Text.Trim();

                if (texto.Contains("CSGO", StringComparison.OrdinalIgnoreCase))
                {
                    MessageBox.Show($"Juego no instalado: {texto}", "Resultado de búsqueda",
                                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else if (texto.Contains("warframe", StringComparison.OrdinalIgnoreCase))
                {
                    MessageBox.Show($"Juego Instalado: {texto}", "Resultado de búsqueda",
                                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    MessageBox.Show($"No se encontró el juego: {texto}", "Resultado de búsqueda",
                                    MessageBoxButtons.OK);
                }

                e.Handled = true; // consume el Enter
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            flowLayoutPanel3.BackgroundImage = Image.FromFile(@"C:\Users\User\Documents\PGE\Tarea 5 - PGE\UISteam\Properties\Resources\warframe.png");
            flowLayoutPanel3.BackgroundImageLayout = ImageLayout.Stretch;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            flowLayoutPanel3.BackgroundImage = Image.FromFile(@"C:\Users\User\Documents\PGE\Tarea 5 - PGE\UISteam\Properties\Resources\csgo.png");
            flowLayoutPanel3.BackgroundImageLayout = ImageLayout.Stretch;
        }

        private void flowLayoutPanel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
