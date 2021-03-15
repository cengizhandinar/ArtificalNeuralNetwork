#pragma once
namespace ArtNeuNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class SLML : public System::Windows::Forms::Form
	{
	public:	SLML(void)
	{
		InitializeComponent();
	}

		  // Doğru çizmek için kullanılan ağırlık dizisi
		  double* w;																		
		  int* Classes;
		  // Normalizasyon işlemi gerçekleştirilmiş mi?
		  int varX = 0;																
		  double* fNet;
		  // Toplam class
		  int Total = 0;																
		  Colors* color;																
		  double* Error;																
		  double* sgnNet;															
		  Samples* sample;														
		  double* tempNet;															
		  double* fNetDer;															
		  int dimension = 0;															
		  double* desiredValue;											    
		  float xMin, xMax, yMin, yMax;
		  // Classların düzleme uyarlanmış noktalarının tutulduğu değerler
		  double x_after = 0, y_after = 0;
		  // Classların düzleme uyarlanmamış noktalarının tutulduğu değerler
		  double x_before = 0, y_before = 0;                        
		  int half_width = 0, half_height = 0;
		
	private: System::Windows::Forms::ListBox^ listValue;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnNormalize;
	private: System::Windows::Forms::ComboBox^ cbClass;
	private: System::Windows::Forms::TextBox^ txtClassNumber;
		
	protected: ~SLML()
	{
		if (components)
		{
			delete components;
		}
	}
		
	private: System::Windows::Forms::PictureBox^ picMain;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ operationsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ btnRandom;
	private: System::Windows::Forms::ToolStripMenuItem^ btnDiscreteSM;
	private: System::Windows::Forms::ToolStripMenuItem^ btnContinuousSM;
	private: System::Windows::Forms::Label^ lblCycle;
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->picMain = (gcnew System::Windows::Forms::PictureBox());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->operationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnRandom = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnDiscreteSM = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnContinuousSM = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->lblTotal = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->lblCycle = (gcnew System::Windows::Forms::Label());
			   this->listValue = (gcnew System::Windows::Forms::ListBox());
			   this->btnBack = (gcnew System::Windows::Forms::Button());
			   this->btnClear = (gcnew System::Windows::Forms::Button());
			   this->btnNormalize = (gcnew System::Windows::Forms::Button());
			   this->cbClass = (gcnew System::Windows::Forms::ComboBox());
			   this->txtClassNumber = (gcnew System::Windows::Forms::TextBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMain))->BeginInit();
			   this->menuStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // picMain
			   // 
			   this->picMain->BackColor = System::Drawing::Color::Thistle;
			   this->picMain->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->picMain->Location = System::Drawing::Point(12, 38);
			   this->picMain->Name = L"picMain";
			   this->picMain->Size = System::Drawing::Size(639, 570);
			   this->picMain->TabIndex = 9;
			   this->picMain->TabStop = false;
			   this->picMain->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SLML::picMain_Paint);
			   this->picMain->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SLML::picMain_MouseClick);
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->operationsToolStripMenuItem });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1091, 26);
			   this->menuStrip1->TabIndex = 10;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // operationsToolStripMenuItem
			   // 
			   this->operationsToolStripMenuItem->BackColor = System::Drawing::Color::Linen;
			   this->operationsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->btnRandom,
					   this->btnDiscreteSM, this->btnContinuousSM
			   });
			   this->operationsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->operationsToolStripMenuItem->ForeColor = System::Drawing::Color::Indigo;
			   this->operationsToolStripMenuItem->Name = L"operationsToolStripMenuItem";
			   this->operationsToolStripMenuItem->Size = System::Drawing::Size(99, 22);
			   this->operationsToolStripMenuItem->Text = L"Operations";
			   // 
			   // btnRandom
			   // 
			   this->btnRandom->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnRandom->Name = L"btnRandom";
			   this->btnRandom->Size = System::Drawing::Size(186, 22);
			   this->btnRandom->Text = L"Random Initiate";
			   this->btnRandom->Click += gcnew System::EventHandler(this, &SLML::btnRandom_Click);
			   // 
			   // btnDiscreteSM
			   // 
			   this->btnDiscreteSM->ForeColor = System::Drawing::Color::Green;
			   this->btnDiscreteSM->Name = L"btnDiscreteSM";
			   this->btnDiscreteSM->Size = System::Drawing::Size(186, 22);
			   this->btnDiscreteSM->Text = L"Discrete";
			   this->btnDiscreteSM->Click += gcnew System::EventHandler(this, &SLML::btnDiscreteSM_Click);
			   // 
			   // btnContinuousSM
			   // 
			   this->btnContinuousSM->ForeColor = System::Drawing::Color::Green;
			   this->btnContinuousSM->Name = L"btnContinuousSM";
			   this->btnContinuousSM->Size = System::Drawing::Size(186, 22);
			   this->btnContinuousSM->Text = L"Continuous";
			   this->btnContinuousSM->Click += gcnew System::EventHandler(this, &SLML::btnContinuousSM_Click);
			   // 
			   // lblTotal
			   // 
			   this->lblTotal->AutoSize = true;
			   this->lblTotal->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->lblTotal->Location = System::Drawing::Point(665, 279);
			   this->lblTotal->Name = L"lblTotal";
			   this->lblTotal->Size = System::Drawing::Size(43, 18);
			   this->lblTotal->TabIndex = 14;
			   this->lblTotal->Text = L"Total";
			   this->lblTotal->Visible = false;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->label1->Location = System::Drawing::Point(723, 38);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(152, 18);
			   this->label1->TabIndex = 11;
			   this->label1->Text = L"Write Class Number:";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->label2->Location = System::Drawing::Point(744, 98);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(100, 18);
			   this->label2->TabIndex = 11;
			   this->label2->Text = L"Select Class:";
			   // 
			   // lblCycle
			   // 
			   this->lblCycle->AutoSize = true;
			   this->lblCycle->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->lblCycle->Location = System::Drawing::Point(665, 236);
			   this->lblCycle->Name = L"lblCycle";
			   this->lblCycle->Size = System::Drawing::Size(47, 18);
			   this->lblCycle->TabIndex = 14;
			   this->lblCycle->Text = L"Cycle";
			   this->lblCycle->Visible = false;
			   // 
			   // listValue
			   // 
			   this->listValue->BackColor = System::Drawing::Color::White;
			   this->listValue->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
			   this->listValue->ForeColor = System::Drawing::Color::SteelBlue;
			   this->listValue->FormattingEnabled = true;
			   this->listValue->ItemHeight = 14;
			   this->listValue->Location = System::Drawing::Point(940, 61);
			   this->listValue->Name = L"listValue";
			   this->listValue->SelectionMode = System::Windows::Forms::SelectionMode::None;
			   this->listValue->Size = System::Drawing::Size(141, 550);
			   this->listValue->TabIndex = 20;
			   // 
			   // btnBack
			   // 
			   this->btnBack->BackColor = System::Drawing::Color::Linen;
			   this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnBack->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->btnBack->Location = System::Drawing::Point(797, 579);
			   this->btnBack->Name = L"btnBack";
			   this->btnBack->Size = System::Drawing::Size(127, 31);
			   this->btnBack->TabIndex = 21;
			   this->btnBack->Text = L"Geri Dön";
			   this->btnBack->UseVisualStyleBackColor = false;
			   this->btnBack->Click += gcnew System::EventHandler(this, &SLML::btnBack_Click);
			   // 
			   // btnClear
			   // 
			   this->btnClear->BackColor = System::Drawing::Color::Linen;
			   this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnClear->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->btnClear->Location = System::Drawing::Point(668, 579);
			   this->btnClear->Name = L"btnClear";
			   this->btnClear->Size = System::Drawing::Size(127, 31);
			   this->btnClear->TabIndex = 22;
			   this->btnClear->Text = L"Temizle";
			   this->btnClear->UseVisualStyleBackColor = false;
			   this->btnClear->Click += gcnew System::EventHandler(this, &SLML::btnClear_Click);
			   // 
			   // btnNormalize
			   // 
			   this->btnNormalize->BackColor = System::Drawing::Color::LightBlue;
			   this->btnNormalize->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnNormalize->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->btnNormalize->Location = System::Drawing::Point(668, 542);
			   this->btnNormalize->Name = L"btnNormalize";
			   this->btnNormalize->Size = System::Drawing::Size(256, 31);
			   this->btnNormalize->TabIndex = 23;
			   this->btnNormalize->Text = L"Normalizasyon Gerçekleştir";
			   this->btnNormalize->UseVisualStyleBackColor = false;
			   this->btnNormalize->Click += gcnew System::EventHandler(this, &SLML::btnNormalize_Click);
			   // 
			   // cbClass
			   // 
			   this->cbClass->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cbClass->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->cbClass->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.25F));
			   this->cbClass->IntegralHeight = false;
			   this->cbClass->ItemHeight = 17;
			   this->cbClass->Location = System::Drawing::Point(668, 125);
			   this->cbClass->Name = L"cbClass";
			   this->cbClass->Size = System::Drawing::Size(266, 25);
			   this->cbClass->TabIndex = 24;
			   // 
			   // txtClassNumber
			   // 
			   this->txtClassNumber->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.25F));
			   this->txtClassNumber->Location = System::Drawing::Point(668, 61);
			   this->txtClassNumber->Multiline = true;
			   this->txtClassNumber->Name = L"txtClassNumber";
			   this->txtClassNumber->Size = System::Drawing::Size(266, 29);
			   this->txtClassNumber->TabIndex = 25;
			   this->txtClassNumber->TextChanged += gcnew System::EventHandler(this, &SLML::txtClassNumber_TextChanged);
			   // 
			   // SLML
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Thistle;
			   this->ClientSize = System::Drawing::Size(1091, 633);
			   this->Controls->Add(this->txtClassNumber);
			   this->Controls->Add(this->cbClass);
			   this->Controls->Add(this->btnBack);
			   this->Controls->Add(this->btnClear);
			   this->Controls->Add(this->btnNormalize);
			   this->Controls->Add(this->listValue);
			   this->Controls->Add(this->picMain);
			   this->Controls->Add(this->menuStrip1);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->lblCycle);
			   this->Controls->Add(this->lblTotal);
			   this->Controls->Add(this->label1);
			   this->Name = L"SLML";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Single Layer Multi Level";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMain))->EndInit();
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   /// <summary>
		   /// Textbox a girilen sayı kadar Class oluşturur. 
		   /// Oluşturulan her class a 0 dan başlayarak değer verilir. Örn Class[0]=0
		   /// </summary>
		   Void setClasses(int count)
		   {
			   Classes = new int[count];

			   for (int i = 0; i < count; i++) Classes[i] = i;
		   }

		   /// <summary>
		   /// Textbox a yazılan sayı kadar comboboxa ilgili sınıfları ekler
		   /// </summary>
		   /// <param name="sender"></param>
		   /// <param name="e"></param>
		   Void txtClassNumber_TextChanged(System::Object^ sender, System::EventArgs^ e)
		   {
			   cbClass->Items->Clear();

			   if (txtClassNumber->Text == "0")
			   {
				   MessageBox::Show("Lutfen pozitif bir tamsayi giriniz!", "Uyari", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   return;
			   }
			   if (txtClassNumber->Text == "")
			   {
				   dimension = 0;
				   return;
			   }

			   dimension = Convert::ToInt32(txtClassNumber->Text);

			   /// <summary>
			   /// Girilen sayı kadar combobox a sırasıyla Class ları ekler.
			   /// </summary>
			   for (int i = 1; i <= dimension; i++)
				   cbClass->Items->Add("Class" + i);

			   /// <summary>
			   /// Class sayısı kadar random renk oluşturulur ve aynı renkler başka yerlerde kullanmak için color struct yapısına aktarılır.
			   /// </summary>
			   int r, g, b;
			   Random^ rnd = gcnew Random();
			   color = new Colors[dimension];
			   for (int i = 0; i < dimension; i++)
			   {
				   r = rnd->Next(255);
				   g = rnd->Next(255);
				   b = rnd->Next(255);
				   color[i].r = r;
				   color[i].g = g;
				   color[i].b = b;
			   }

			   /// <summary>
			   /// Classları oluşturması için fonksiyona Class sayısı gönderilir.
			   /// </summary>
			   setClasses(dimension);
		   }
		
		   /// <summary>
		   /// Koordinat düzleminin çizilmesi
		   /// </summary>
		   Void picMain_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		   {
			   // for Coordinate Plane
			   Pen^ pen = gcnew Pen(Color::Black, 3.0f);
			   // genişliğin yarısı
			   half_width = (int)(picMain->Width / 2);
			   // yüksekliğin yarısı
			   half_height = (int)(picMain->Height / 2);						  

			   e->Graphics->DrawLine(pen, half_width, 0, half_width, picMain->Height);
			   e->Graphics->DrawLine(pen, 0, half_height, picMain->Width, half_height);
		   }

		   /// <summary>
		   /// Rastgele doğru çizilmesi
		   /// </summary>
		   Void btnRandom_Click(System::Object^ sender, System::EventArgs^ e)	
		   {
			   if (!dimension) { MessageBox::Show("Lutfen sinif sayisi ve ornekleri belirtiniz!", "Uyari", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }
			   if (!Total) { MessageBox::Show("Lutfen sinif sayisi ve ornekleri belirtiniz!", "Uyari", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }

			   w = new double[dimension];
			   srand(time(0));

			   for (int i = 0; i < dimension * 3; i++) 
				   w[i] = ((double)rand() / (RAND_MAX));

			   for (int i = 0; i < dimension; i++)
			   {
				   // Renk belirlemek için struct ta oluşturulmuş renkleri kullanırız
				   Pen^ pen = gcnew Pen(Color::FromArgb(color[i].r, color[i].g, color[i].b),3.0);
				   xMin = -half_width;
				   xMax = half_width;
				   yMin = YPoint(xMin, w, i);
				   yMax = YPoint(xMax, w, i);
				   picMain->CreateGraphics()->DrawLine(pen, (float)0, half_height - yMin, half_width + xMax, half_height - yMax);
			   }
		   }

		   /// <summary>
		   /// Classlar belirlenir ve nokta olarak gösterilir \n
		   /// Her bir örnek için 4 adet değer tanımlandı ve bu alana karşılık düşen değerler verildi
		   /// </summary>
		   Void picMain_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		   {
			   picMain->Focus();
			   //Comboboxtan class ları seçerken sayısını kullanacağımız için sayının hanesine göre string yapıyı ayırmak için kullanılır
			   int sIndex = 0;
			   //Comboboxtan class ları seçerken sayısını kullanacağımız için sayının hanesine göre string yapıyı ayırmak için kullanılır
			   int numberCharecter = 0;           
			   int X = e->X;
			   int Y = e->Y;
			   x_before = X;
			   y_before = Y;

			   x_after = (double)(x_before - half_width);
			   y_after = (double)(half_height - y_before);

			   if (cbClass->SelectedItem->ToString()->Length == 7) { sIndex = cbClass->SelectedItem->ToString()->Length - 2; numberCharecter = 2; }
			   else if (cbClass->SelectedItem->ToString()->Length == 8 ) { sIndex = cbClass->SelectedItem->ToString()->Length - 3; numberCharecter = 3; }
			   else { sIndex = cbClass->SelectedItem->ToString()->Length - 1; numberCharecter = 1; }


			   if (cbClass->SelectedIndex != -1)
			   {
				   SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(
					   color[cbClass->SelectedIndex].r, color[cbClass->SelectedIndex].g, color[cbClass->SelectedIndex].b));
				   if (cbClass->SelectedIndex + 1 == Convert::ToInt32(cbClass->SelectedItem->ToString()->Substring(sIndex, numberCharecter)))
				   {
					   if (Total == 0) {
						   Total++;
						   sample = new Samples[1];
						   sample[0].X = x_after;
						   sample[0].Y = y_after;
						   sample[0].Class = Classes[cbClass->SelectedIndex];
						   sample[0].Const = ConstNum;
					   }
					   else
					   {
						   Total++;
						   Samples* temp;
						   temp = sample;
						   sample = new Samples[Total];
						   for (int i = 0; i < Total - 1; i++) {
							   sample[i].X = temp[i].X;
							   sample[i].Y = temp[i].Y;
							   sample[i].Class = temp[i].Class;
							   sample[i].Const = ConstNum;
						   }
						   sample[Total - 1].X = x_after;
						   sample[Total - 1].Y = y_after;
						   sample[Total - 1].Class = Classes[cbClass->SelectedIndex];
						   sample[Total - 1].Const = ConstNum;
						   delete temp;
					   }
					   picMain->CreateGraphics()->FillEllipse(brush, x_before - 5, y_before, 8, 8);
				   }

				   // Classların yapıda tutulduğu konumların değerini yazar.
				   listValue->Items->Clear();
				   for (int i = 0; i < Total; i++)
				   {
					   listValue->Items->Add("Sample: " + i);
					   listValue->Items->Add("X: " + sample[i].X);
					   listValue->Items->Add("Y: " + sample[i].Y);
					   listValue->Items->Add("Class: " + sample[i].Class);
					   listValue->Items->Add("Const: " + sample[i].Const);
					   listValue->Items->Add("---------------------------");
				   }
				   lblTotal->Visible = true;
				   lblTotal->Text = "Samples Total: " + Convert::ToString(Total);
			   }
			   else
				   MessageBox::Show("Lutfen bir sınıf turu seciniz!", "Uyarı", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }

		   /// <summary>
		   /// Tek katmanlı çok seviyeli ayrık öğrenmeyi gerçekleştiren algoritma
		   /// </summary>		                                                             
		   Void btnDiscreteSM_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (!w) { MessageBox::Show("Baslangıc dogrusu belirtilmemis!", "Uyari", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }

			   // class sayısını kontrol etmek için
			   int k = 0;
			   // örnek sayısını kontrol etmek için
			   int i = 0;
			   // hata değerini kontrol etmek için
			   int Error = 1;																	  
			   float omega = 0;															   
			   // Hata sayısı kaç döngüde sıfırdan küçük olacak 
			   int cycleNumber = 0;
			   // 'sgnNet' value in the formula 
			   sgnNet = new double[dimension];
			   // 'net' value in the formula 
			   tempNet = new double[dimension];
			   // class ları birbirinden ayırmak için belirlenen beklenen değer dizisi
			   desiredValue = new double[dimension];				   

			   while (Error > 0)
			   {
				   i = 0;
				   Error = 0;
				   cycleNumber++;
				   while (i < Total)
				   {	
					   /// <summary>
					   /// Ağırlıkların güncellenebilmesi için gerekli olan değerler belirlenir
					   /// </summary>
					   for (k = 0; k < dimension; k++)
					   {
						   // Her bir örnek için beklenen değerler belirlenir.
						   if (sample[i].Class == k) desiredValue[k] = 1;
						   else desiredValue[k] = -1;
						   // net değeri hesaplanır
						   // net = w[0]*x1 + w[1]*y1 + w[2]*ConstNum 
						   tempNet[k] = (w[k * 3] * sample[i].X) + (w[(k * 3) + 1] * sample[i].Y) + (w[(k * 3) + 2] * sample[i].Const);  
						   // net değerine göre belirlenen output dizisi oluşturulur
						   if (tempNet[k] >= 0) sgnNet[k] = 1;
						   else sgnNet[k] = -1;
					   }
					   for (k = 0; k < dimension; k++)
					   {
						   /// <summary>
						   /// Beklenen değer ile çıktı karşılaştırılır. Birbirine eşit değilse ağırlıklar güncellenir.
						   /// </summary>
						   if (sgnNet[k] != desiredValue[k])
						   {
							   // omega = (c * [d - sgnNet])	
							   omega = C * (desiredValue[k] - sgnNet[k]);
							   // w[k]  = (c * [d - sgnNet]) * x1
							   w[(k * 3)] += (omega * sample[i].X);
							   // w[k+1]= (c * [d - sgnNet]) * x2
							   w[(k * 3) + 1] += (omega * sample[i].Y);
							   // w[k+2]= (c * [d - sgnNet]) * x3
							   w[(k * 3) + 2] += (omega * sample[i].Const);
							   // Error+= |(d - sgnNet)| / 2	
							   Error += Math::Abs(desiredValue[k] - sgnNet[k]) / 2;		
						   }
					   }
					   i++;
				   }
			   }

			   /// <summary>
			   /// Doğrunun ekranda gösterilmesi 
			   /// Doğruyu çizmek için 2 adet nokta belirlenir. Ve bu noktalar ağırlıklara göre hesaplanır.
			   /// </summary>
			   picMain->Refresh();
			   for (k = 0; k < dimension; k++)
			   {
				   Pen^ pen = gcnew Pen(Color::FromArgb(color[k].r, color[k].g, color[k].b), 3.0);

				   xMin = -half_width;
				   xMax = half_width;
				   yMin = YPoint(xMin, w, k);
				   yMax = YPoint(xMax, w, k);
				   
				   picMain->CreateGraphics()->DrawLine(pen, (float)0, half_height - yMin, half_width + xMax, half_height - yMax);
			   }

			   lblCycle->Visible = true;
			   lblCycle->Text = "Number of Cycles\nDiscrete Multi Perceptron: " + cycleNumber;
			   for (int n = 0; n < Total; n++)
			   {
				   SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(color[sample[n].Class].r, color[sample[n].Class].g, color[sample[n].Class].b));
				   x_before = sample[n].X + half_width;
				   y_before = half_height - sample[n].Y;
				   picMain->CreateGraphics()->FillEllipse(brush, x_before - 5, y_before, 8, 8);
			   }
		   }

		   /// <summary>
		   /// Tek katmanlı çok seviyeli sürekli öğrenme için Normalizasyon işlemi gerçekleştirilir.
		   /// </summary>
		   Void btnNormalize_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (!w) { MessageBox::Show("Baslangıc dogrusu belirtilmemis!", "Uyari", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }

			   float totalX = 0, totalY = 0, avgX = 0, avgY = 0;
			   float powX = 0, powY = 0, varY = 0;

			   for (int i = 0; i < Total; i++)
			   {
				   // X'lerin toplamı
				   totalX += sample[i].X;
				   // Y'lerin toplamı
				   totalY += sample[i].Y;                          
			   }

			   // Ortalama X
			   avgX = totalX / Total;
			   // Ortalama Y
			   avgY = totalY / Total;                               

			   for (int i = 0; i < Total; i++)
			   {
				   // Toplam (x-avgX)^2
				   powX += Math::Pow(sample[i].X - avgX, 2);
				   // Toplam (y-avgY)^2
				   powY += Math::Pow(sample[i].Y - avgY, 2);       
			   }

			   // square [ (x-avgX)^2 / totalSample ]
			   varX = Math::Sqrt(powX / Total);
			   // square [ (y-avgY)^2 / totalSample ]
			   varY = Math::Sqrt(powY / Total);					   

			   for (int i = 0; i < Total; i++)
			   {
				   // (x-avgX) / varyansX = new X value
				   sample[i].X = (sample[i].X - avgX) / varX;
				   // (y-avgY) / varyansY = new Y value
				   sample[i].Y = (sample[i].Y - avgY) / varY;      
			   }

			   MessageBox::Show("Normalizasyon islemi gerceklestirilmistir.", "Bilgi", MessageBoxButtons::OK, MessageBoxIcon::Information);
		   }

		   /// <summary>
		   /// Tek katmanlı çok seviyeli sürekli öğrenmeyi gerçekleştiren algoritma
		   /// </summary>
		   Void btnContinuousSM_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (!varX) { MessageBox::Show("Normalizasyon işlemi gerçekleştirilmemiş!", "Uyarı", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }

			   // class sayısını kontrol etmek için
			   int k = 0;
			   // örnek sayısını kontrol etmek için
			   int i = 0;                                                      
			   int lamda = 1;										             
			   float omega = 0;
			   // Hata sayısı kaç döngüde sıfırdan küçük olacak 
			   int cycleNumber = 0;
			   // 'fNet' value in the formula 
			   fNet = new double[dimension];
			   // 'fNet' değerinin türevi
			   fNetDer = new double[dimension];
			   // 'net' value in the formula 
			   tempNet = new double[dimension];
			   // class ları birbirinden ayırmak için belirlenen beklenen değer dizisi
			   desiredValue = new double[dimension];
			   // hata değerini kontrol etmek için
			   Error = new double[dimension];									
			   bool status = true;

			   while (status)
			   {
				   cycleNumber++;

				   for (int x = 0; x < dimension; x++)				   
					   Error[x] = 0;
				   
				   i = 0;
				   while (i < Total)
				   {
					   /// <summary>
					   /// Ağırlıkların güncellenebilmesi için gerekli olan değerler belirlenir
					   /// </summary>
					   for (k = 0; k < dimension; k++)
					   {
						   // Her bir örnek için beklenen değerler belirlenir.
						   if (sample[i].Class == k) desiredValue[k] = 1;
						   else desiredValue[k] = -1;
						   // net değeri hesaplanır
						   // net = w[0]*x1 + w[1]*y1 + w[2]*ConstNum 
						   tempNet[k] = (w[k * 3] * sample[i].X) + (w[(k * 3) + 1] * sample[i].Y) + (w[(k * 3) + 2] * sample[i].Const);   
						   // net değerine göre belirlenen output dizisi oluşturulur
						   // fNet = ( 2 / ( 1 + e^-lamda*net) ) -1;
						   fNet[k] = (2 / (1 + Math::Exp(-lamda * tempNet[k]))) - 1;                                                     
						   // fNet değerine göre belirlenen fNettürev dizisi oluşturulur
						   // fNetDerivative = 0.5 * ( 1 - (fNet^2) );
						   fNetDer[k] = 0.5 * (1 - Math::Pow(fNet[k], 2));																
					   }

					   /// <summary>
					   /// Ağırlıklar güncellenir.
					   /// </summary>
					   for (k = 0; k < dimension; k++)
					   {
						   // omega = m * (d - fNet) * fNetDerivative
						   omega = (float)(M * (desiredValue[k] - fNet[k])) * fNetDer[k];
						   // w[k]  = (c * [d - sgnNet]) * x1
						   w[(k * 3)] += (omega * sample[i].X);
						   // w[k+1]= (c * [d - sgnNet]) * x2
						   w[(k * 3) + 1] += (omega * sample[i].Y);
						   // w[k+2]= (c * [d - sgnNet]) * x3
						   w[(k * 3) + 2] += (omega * sample[i].Const);
						   // Error += 1 / 2 * ((d - fNet) ^ 2);
						   Error[k] += 0.5 * (Math::Pow(desiredValue[k] - fNet[k], 2));			
					   }
					   i++;
				   }

				   int counter = 0;
				   /// <summary>
				   /// Tüm class değerleri için hata değerlerini tek tek kontrol eder
				   /// </summary>
				   for (int x = 0; x < dimension; x++)
				   {
					   if (Error[x] > 0.1) continue;
					   else counter++;
				   }
				   if (counter == dimension) status = false;					   
			   }

			   /// <summary>
			   /// Doğrunun ekranda gösterilmesi 
			   /// Doğruyu çizmek için 2 adet nokta belirlenir. Ve bu noktalar ağırlıklara göre hesaplanır.
			   /// </summary>
			   picMain->Refresh();
			   for (k = 0; k < dimension; k++)
			   {
				   Pen^ pen = gcnew Pen(Color::FromArgb(color[k].r, color[k].g, color[k].b), 3.0);

				   xMin = -half_width;
				   xMax = half_width;
				   yMin = YPoint(xMin, w, k, 25);
				   yMax = YPoint(xMax, w, k, 25);

				   picMain->CreateGraphics()->DrawLine(pen, (float)0, half_height - yMin, half_width + xMax, half_height - yMax);
			   }

			   lblCycle->Visible = true;
			   lblCycle->Text = "Number of Cycles\nContinuous Multi Perceptron: " + cycleNumber;
			   for (int n = 0; n < Total; n++)
			   {
				   SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(color[sample[n].Class].r, color[sample[n].Class].g, color[sample[n].Class].b));
				   x_before = (sample[n].X * 25) + half_width;
				   y_before = half_height - (sample[n].Y * 25);
				   picMain->CreateGraphics()->FillEllipse(brush, x_before - 5, y_before, 8, 8);
			   }
		   }

		   /// <summary>
		   /// Ana menüye geri döner
		   /// </summary>
		   Void btnClear_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   btnBack->PerformClick();
		   }

		   /// <summary>
		   /// Geri dönme işlemi gerçekleştirir
		   /// </summary>
		   Void btnBack_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   DialogResult = Windows::Forms::DialogResult::OK;
		   }

};
}
