using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace HesapMakinesi
{
    public partial class Calculator : System.Web.UI.Page
    {
        static string islem;
        static double sayi1,sayi2;

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack) TextBox.Text = "0";// başlangıçta ekrana sıfır yazdıralım.
        }

        // 1 rakamının bulunduğu buttonun click olayı
        protected void Button1_Click(object sender, EventArgs e)
        {
            if (TextBox.Text == "0")
                TextBox.Text = "";
            TextBox.Text += "7";
        }
        // 2 rakamının bulunduğu buttonun click olayı
        protected void Button2_Click(object sender, EventArgs e)
        {
            if (TextBox.Text == "0")
                TextBox.Text = "";
            TextBox.Text += "8";
        }
        // 3 rakamının bulunduğu buttonun click olayı
        protected void Button3_Click(object sender, EventArgs e)
        {
            if (TextBox.Text == "0")
                TextBox.Text = "";
            TextBox.Text += "9";
        }

        // 4 rakamının bulunduğu buttonun click olayı
        protected void Button5_Click(object sender, EventArgs e)
        {
            if (TextBox.Text == "0")
                TextBox.Text = "";
            TextBox.Text += "4";
        }
        // 5 rakamının bulunduğu buttonun click olayı
        protected void Button6_Click(object sender, EventArgs e)
        {
            if (TextBox.Text == "0")
                TextBox.Text = "";
            TextBox.Text += "5";
        }
        // 6 rakamının bulunduğu buttonun click olayı
        protected void Button7_Click(object sender, EventArgs e)
        {
            if (TextBox.Text == "0")
                TextBox.Text = "";
            TextBox.Text += "6";
        }

        // 1 rakamının bulunduğu buttonun click olayı
        protected void Button9_Click(object sender, EventArgs e)
        {
            if (TextBox.Text == "0")
                TextBox.Text = "";
            TextBox.Text += "1";
        }
        // 2 rakamının bulunduğu buttonun click olayı
        protected void Button10_Click(object sender, EventArgs e)
        {
            if (TextBox.Text == "0")
                TextBox.Text = "";
            TextBox.Text += "2";
        }

        // 3 rakamının bulunduğu buttonun click olayı
        protected void Button11_Click(object sender, EventArgs e)
        {
            if (TextBox.Text == "0")
                TextBox.Text = "";
            TextBox.Text += "3";
        }
        // 0 rakamının bulunduğu buttonun click olayı
        protected void Button13_Click(object sender, EventArgs e)
        {
            if (TextBox.Text == "0") 
                TextBox.Text = "0";
            else TextBox.Text += "0";
        }

 
        // toplama buttonun click olayı
        protected void Button14_Click(object sender, EventArgs e)
        {
            islem = "+";
            sayi1 = Convert.ToDouble(TextBox.Text);
            TextBox.Text += "+";
        }
     
        // çıkarma buttonun click olayı
        protected void Button12_Click(object sender, EventArgs e)
        {
            islem = "-";
            sayi1 = Convert.ToDouble(TextBox.Text);
            TextBox.Text += "-";
        }

        // çarpma buttonun click olayı
        protected void Button8_Click(object sender, EventArgs e)
        {
            islem = "*";
            sayi1 = Convert.ToDouble(TextBox.Text);
            TextBox.Text += "*";
        }
        // bölme buttonun click olayı
        protected void Button4_Click(object sender, EventArgs e)
        {
            islem = "/";
            sayi1 = Convert.ToDouble(TextBox.Text);
            TextBox.Text += "/";
        }

        // eşittir buttonun click olayı
        protected void Button16_Click(object sender, EventArgs e)
        {
            string veri = TextBox.Text;
            string sayi ="";

            for (int i =0 ; i < veri.Length ; i++)
            {
                if (veri[i].ToString() == islem)
                {
                    for (int j = i+1; j < veri.Length ; j++)
                    {
                        sayi += veri[j];
                    }
                }
            }


            sayi2 = Convert.ToDouble(sayi);
            TextBox.Text = Convert.ToString(hesapla());

        }

        public double hesapla()
        {
            double sonuc=0;

            if (islem == "+")
                sonuc = sayi1 + sayi2;

            else if (islem == "-")
                sonuc = sayi1 - sayi2;

            else if (islem == "*")
                sonuc = sayi1 * sayi2;

            else if (islem == "/")
                sonuc = sayi1 / sayi2;

            else
                sonuc = 0;

            return sonuc;

        }


            // ekran temizleme (CLC)
            protected void Button15_Click(object sender, EventArgs e)
        {
            
            TextBox.Text = "0";
            
           
        }
    }
}
