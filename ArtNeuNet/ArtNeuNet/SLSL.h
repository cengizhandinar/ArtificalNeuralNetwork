#pragma once
#include <time.h>
#include <Windows.h>
#include "MainService.h"

namespace ArtNeuNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class SLSL : public System::Windows::Forms::Form
	{
	public:	SLSL(void)
	{
		InitializeComponent();
	}
		  Samples* sample;
		  // Doðru çizmek için kullanýlan aðýrlýk dizisi
		  double* w;
		  // Normalizasyon iþlemi gerçekleþtirilmiþ mi?
		  int varX = 0;
		  // Toplam class
		  int Total = 0;
		  // Class1 sayýsý
		  int SizeC1 = 0;
		  // Class2 sayýsý
		  int SizeC2 = 0;                                             
		  int dimension = 0;	
		  float xMin, xMax, yMin, yMax;
		  // Classlarýn düzleme uyarlanmýþ noktalarýnýn tutulduðu deðerler
		  double x_after = 0, y_after = 0;
		  // Classlarýn düzleme uyarlanmamýþ noktalarýnýn tutulduðu deðerler
		  double x_before = 0, y_before = 0;                           
		  int half_width = 0, half_height = 0;
		  // for Class1
		  SolidBrush^ _brushC1 = gcnew SolidBrush(Color::IndianRed);
		  // for Class2
		  SolidBrush^ _brushC2 = gcnew SolidBrush(Color::BlueViolet);

	protected: ~SLSL()
	{
		if (components)
		{
			delete components;
		}
	}		
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::PictureBox^ picMain;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ operationsToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::ToolStripMenuItem^ btnManual;
	private: System::Windows::Forms::ToolStripMenuItem^ btnRandom;
	private: System::Windows::Forms::ToolStripMenuItem^ btnDiscreteSS;
	private: System::Windows::Forms::ToolStripMenuItem^ btnContinuousSS;
	private: System::Windows::Forms::Button^ btnNormalize;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::ComboBox^ cbClass;
	private: System::Windows::Forms::ListBox^ listValue;
	private: System::Windows::Forms::Label^ lblCycle;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->picMain = (gcnew System::Windows::Forms::PictureBox());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->operationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnManual = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnRandom = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnDiscreteSS = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnContinuousSS = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->lblTotal = (gcnew System::Windows::Forms::Label());
			   this->lblCycle = (gcnew System::Windows::Forms::Label());
			   this->btnNormalize = (gcnew System::Windows::Forms::Button());
			   this->btnClear = (gcnew System::Windows::Forms::Button());
			   this->btnBack = (gcnew System::Windows::Forms::Button());
			   this->cbClass = (gcnew System::Windows::Forms::ComboBox());
			   this->listValue = (gcnew System::Windows::Forms::ListBox());
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
			   this->picMain->TabIndex = 0;
			   this->picMain->TabStop = false;
			   this->picMain->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SLSL::picMain_Paint);
			   this->picMain->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SLSL::picMain_MouseClick);
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->operationsToolStripMenuItem });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1091, 26);
			   this->menuStrip1->TabIndex = 1;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // operationsToolStripMenuItem
			   // 
			   this->operationsToolStripMenuItem->BackColor = System::Drawing::Color::Linen;
			   this->operationsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				   this->btnManual,
					   this->btnRandom, this->btnDiscreteSS, this->btnContinuousSS
			   });
			   this->operationsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->operationsToolStripMenuItem->ForeColor = System::Drawing::Color::Indigo;
			   this->operationsToolStripMenuItem->Name = L"operationsToolStripMenuItem";
			   this->operationsToolStripMenuItem->Size = System::Drawing::Size(99, 22);
			   this->operationsToolStripMenuItem->Text = L"Operations";
			   // 
			   // btnManual
			   // 
			   this->btnManual->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnManual->Name = L"btnManual";
			   this->btnManual->Size = System::Drawing::Size(186, 22);
			   this->btnManual->Text = L"Manual Initiate";
			   this->btnManual->Click += gcnew System::EventHandler(this, &SLSL::btnManual_Click);
			   // 
			   // btnRandom
			   // 
			   this->btnRandom->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnRandom->Name = L"btnRandom";
			   this->btnRandom->Size = System::Drawing::Size(186, 22);
			   this->btnRandom->Text = L"Random Initiate";
			   this->btnRandom->Click += gcnew System::EventHandler(this, &SLSL::btnRandom_Click);
			   // 
			   // btnDiscreteSS
			   // 
			   this->btnDiscreteSS->ForeColor = System::Drawing::Color::Green;
			   this->btnDiscreteSS->Name = L"btnDiscreteSS";
			   this->btnDiscreteSS->Size = System::Drawing::Size(186, 22);
			   this->btnDiscreteSS->Text = L"Discrete";
			   this->btnDiscreteSS->Click += gcnew System::EventHandler(this, &SLSL::btnDiscreteSS_Click);
			   // 
			   // btnContinuousSS
			   // 
			   this->btnContinuousSS->ForeColor = System::Drawing::Color::Green;
			   this->btnContinuousSS->Name = L"btnContinuousSS";
			   this->btnContinuousSS->Size = System::Drawing::Size(186, 22);
			   this->btnContinuousSS->Text = L"Continuous";
			   this->btnContinuousSS->Click += gcnew System::EventHandler(this, &SLSL::btnContinuousSS_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->label1->Location = System::Drawing::Point(752, 41);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(100, 18);
			   this->label1->TabIndex = 3;
			   this->label1->Text = L"Select Class:";
			   // 
			   // lblTotal
			   // 
			   this->lblTotal->AutoSize = true;
			   this->lblTotal->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->lblTotal->Location = System::Drawing::Point(665, 299);
			   this->lblTotal->Name = L"lblTotal";
			   this->lblTotal->Size = System::Drawing::Size(43, 18);
			   this->lblTotal->TabIndex = 4;
			   this->lblTotal->Text = L"Total";
			   this->lblTotal->Visible = false;
			   // 
			   // lblCycle
			   // 
			   this->lblCycle->AutoSize = true;
			   this->lblCycle->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->lblCycle->Location = System::Drawing::Point(665, 238);
			   this->lblCycle->Name = L"lblCycle";
			   this->lblCycle->Size = System::Drawing::Size(47, 18);
			   this->lblCycle->TabIndex = 4;
			   this->lblCycle->Text = L"Cycle";
			   this->lblCycle->Visible = false;
			   // 
			   // btnNormalize
			   // 
			   this->btnNormalize->BackColor = System::Drawing::Color::LightBlue;
			   this->btnNormalize->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnNormalize->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->btnNormalize->Location = System::Drawing::Point(668, 544);
			   this->btnNormalize->Name = L"btnNormalize";
			   this->btnNormalize->Size = System::Drawing::Size(256, 31);
			   this->btnNormalize->TabIndex = 9;
			   this->btnNormalize->Text = L"Normalizasyon Gerçekleþtir";
			   this->btnNormalize->UseVisualStyleBackColor = false;
			   this->btnNormalize->Click += gcnew System::EventHandler(this, &SLSL::btnNormalize_Click);
			   // 
			   // btnClear
			   // 
			   this->btnClear->BackColor = System::Drawing::Color::Linen;
			   this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnClear->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->btnClear->Location = System::Drawing::Point(668, 581);
			   this->btnClear->Name = L"btnClear";
			   this->btnClear->Size = System::Drawing::Size(127, 31);
			   this->btnClear->TabIndex = 9;
			   this->btnClear->Text = L"Temizle";
			   this->btnClear->UseVisualStyleBackColor = false;
			   this->btnClear->Click += gcnew System::EventHandler(this, &SLSL::btnClear_Click);
			   // 
			   // btnBack
			   // 
			   this->btnBack->BackColor = System::Drawing::Color::Linen;
			   this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnBack->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->btnBack->Location = System::Drawing::Point(797, 581);
			   this->btnBack->Name = L"btnBack";
			   this->btnBack->Size = System::Drawing::Size(127, 31);
			   this->btnBack->TabIndex = 9;
			   this->btnBack->Text = L"Geri Dön";
			   this->btnBack->UseVisualStyleBackColor = false;
			   this->btnBack->Click += gcnew System::EventHandler(this, &SLSL::btnBack_Click);
			   // 
			   // cbClass
			   // 
			   this->cbClass->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cbClass->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->cbClass->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.25F));
			   this->cbClass->IntegralHeight = false;
			   this->cbClass->ItemHeight = 17;
			   this->cbClass->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Class1", L"Class2" });
			   this->cbClass->Location = System::Drawing::Point(668, 62);
			   this->cbClass->Name = L"cbClass";
			   this->cbClass->Size = System::Drawing::Size(266, 25);
			   this->cbClass->TabIndex = 10;
			   // 
			   // listValue
			   // 
			   this->listValue->BackColor = System::Drawing::Color::White;
			   this->listValue->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
			   this->listValue->ForeColor = System::Drawing::Color::SteelBlue;
			   this->listValue->FormattingEnabled = true;
			   this->listValue->ItemHeight = 14;
			   this->listValue->Location = System::Drawing::Point(940, 62);
			   this->listValue->Name = L"listValue";
			   this->listValue->SelectionMode = System::Windows::Forms::SelectionMode::None;
			   this->listValue->Size = System::Drawing::Size(141, 550);
			   this->listValue->TabIndex = 11;
			   // 
			   // SLSL
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Thistle;
			   this->ClientSize = System::Drawing::Size(1091, 633);
			   this->Controls->Add(this->listValue);
			   this->Controls->Add(this->cbClass);
			   this->Controls->Add(this->btnBack);
			   this->Controls->Add(this->btnClear);
			   this->Controls->Add(this->btnNormalize);
			   this->Controls->Add(this->lblCycle);
			   this->Controls->Add(this->lblTotal);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->picMain);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"SLSL";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Single Layer Single Level";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMain))->EndInit();
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
		   		   
		   /// <summary>
		   /// Koordinat düzleminin çizilmesi
		   /// </summary>
		   Void picMain_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		   {
			   Pen^ pen = gcnew Pen(Color::Black, 3.0f);
			   half_width = (int)(picMain->Width / 2);	
			   half_height = (int)(picMain->Height / 2); 

			   e->Graphics->DrawLine(pen, half_width, 0, half_width, picMain->Height);
			   e->Graphics->DrawLine(pen, 0, half_height, picMain->Width, half_height);
		   }

		   /// <summary>
		   /// Manuel doðru çizilmesi ( x = -y  -->  w=[1,1,0] )
		   /// </summary>
		   Void btnManual_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   btnRandom->Enabled = false;
			   Pen^ pen = gcnew Pen(Color::AliceBlue, 3.0f);
			   w = new double[3];
			   w[0] = 1;
			   w[1] = 1;
			   w[2] = 0;
			   picMain->CreateGraphics()->DrawLine(pen, 0, 0, picMain->Width, picMain->Height);
		   }

		   /// <summary>
		   /// Rastgele doðru çizilmesi
		   /// </summary>
		   Void btnRandom_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (!(SizeC1 && SizeC2)) { MessageBox::Show("Lütfen en az 2 farklý örnek belirtiniz", "Uyarý", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }
			   Pen^ pen = gcnew Pen(Color::AliceBlue, 3.0f);

			   btnManual->Enabled = false;
			   w = new double[3];
			   srand(time(0));
			   for (int i = 0; i < 3; i++)
				   w[i] = ((double)rand() / (RAND_MAX));
		   	
			   xMin = -half_width;
			   xMax = half_width;
			   yMin = YPoint(xMin, w);
			   yMax = YPoint(xMax, w);
			   picMain->CreateGraphics()->DrawLine(pen, (double)0, half_height - yMin, (double)half_width + xMax, half_height - yMax);
		   }

		   /// <summary>
		   /// Classlar belirlenir ve nokta olarak gösterilir \n
		   /// Her bir örnek için 4 adet deðer tanýmlandý ve bu alana karþýlýk düþen deðerler verildi
		   /// </summary>
		   Void picMain_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		   {
			   picMain->Focus();
			   int X = e->X;
			   int Y = e->Y;
			   x_before = X;
			   y_before = Y;
			   x_after = (double)(x_before - half_width);
			   y_after = (double)(half_height - y_before);

			   if (cbClass->SelectedIndex != -1)
			   {
				   if (cbClass->SelectedItem == "Class1")
				   {
					   if (Total == 0) {
						   Total = SizeC1 = 1;
						   sample = new Samples[1];
						   sample[0].X = x_after;
						   sample[0].Y = y_after;
						   sample[0].Class = Class1;
						   sample[0].Const = ConstNum;
					   }
					   else
					   {
						   Samples* temp;
						   temp = sample;
						   SizeC1++;
						   Total = SizeC1 + SizeC2;
						   sample = new Samples[Total];
						   for (int i = 0; i < Total - 1; i++) {
							   sample[i].X = temp[i].X;
							   sample[i].Y = temp[i].Y;
							   sample[i].Class = temp[i].Class;
							   sample[i].Const = ConstNum;
						   }
						   sample[Total - 1].X = x_after;
						   sample[Total - 1].Y = y_after;
						   sample[Total - 1].Class = Class1;
						   sample[Total - 1].Const = ConstNum;
						   delete temp;
					   }
					   picMain->CreateGraphics()->FillEllipse(_brushC1, x_before - 5, y_before, 8, 8);
					   
				   }
				   else if (cbClass->SelectedItem == "Class2")
				   {
					   if (Total == 0) {
						   Total = SizeC2 = 1;
						   sample = new Samples[1];
						   sample[0].X = x_after;
						   sample[0].Y = y_after;
						   sample[0].Class = Class2;
						   sample[0].Const = ConstNum;
					   }
					   else
					   {
						   Samples* temp;
						   temp = sample;
						   SizeC2++;
						   Total = SizeC1 + SizeC2;
						   sample = new Samples[Total];
						   for (int i = 0; i < Total - 1; i++) {
							   sample[i].X = temp[i].X;
							   sample[i].Y = temp[i].Y;
							   sample[i].Class = temp[i].Class;
							   sample[i].Const = ConstNum;
						   }
						   sample[Total - 1].X = x_after;
						   sample[Total - 1].Y = y_after;
						   sample[Total - 1].Class = Class2;
						   sample[Total - 1].Const = ConstNum;
						   delete temp;
					   }
					   picMain->CreateGraphics()->FillEllipse(_brushC2, x_before - 5, y_before, 8, 8);
				   }

				   // Classlarýn yapýda tutulduðu konumlarýn deðerini yazar.
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
				   lblTotal->Text =
					   "Samples Total: " + Convert::ToString(Total)
					   + "\nClass 1: " + Convert::ToString(SizeC1)
					   + "\nClass 2: " + Convert::ToString(SizeC2);
			   }
			   else
				   MessageBox::Show("Lütfen bir sýnýf türü seçiniz!", "Uyarý", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }

		   /// <summary>
		   /// Tek katmanlý tek seviyeli ayrýk öðrenmeyi gerçekleþtiren algoritma
		   /// </summary>
		   Void btnDiscreteSS_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (!w) { MessageBox::Show("Baþlangýç doðrusu belirtilmemiþ!", "Uyarý", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }

			   // aðýrlýk dizisinin indislerini kontrol etmek için
			   int k = 0;
			   // bellek alanýný kontrol etmek için
			   int i = 0;
			   // hata deðerini kontrol etmek için
			   int Error = 1;
			   // 'net' value in the formula 
			   float net = 0;
			   // 'sgnNet' value in the formula 
			   int sgnNet = 0;											 
			   float omega = 0;
			  // Hata sayýsý kaç döngüde sýfýrdan küçük olacak 
			   int cycleNumber = 0;										 
			   Pen^ pen = gcnew Pen(Color::AliceBlue, 3.0f);

			   while (Error > 0)
			   {
				   i = 0;
				   Error = 0;
				   cycleNumber++;
				   while (i < Total)
				   {
					   k = 0;
					   // net = w[0]*x1 + w[1]*y1 + w[2]*ConstNum 
					   net = (w[k] * sample[i].X) + (w[k + 1] * sample[i].Y) + (w[k + 2] * sample[i].Const);

					   if (net > 0)  sgnNet = 1;
					   else          sgnNet = -1;
					   
					   // omega = (c * [d - sgnNet])				   
					   omega = C * (sample[i].Class - sgnNet);
					   // w[k]  = (c * [d - sgnNet]) * x1
					   w[k] += (omega * sample[i].X);
					   // w[k+1]= (c * [d - sgnNet]) * x2
					   w[k + 1] += (omega * sample[i].Y);
					   // w[k+2]= (c * [d - sgnNet]) * x3
					   w[k + 2] += (omega * sample[i].Const); 

					   // Error+= |(d - sgnNet)| / 2
					   Error += Math::Abs(sample[i].Class - sgnNet) / 2;
					   
					   // Doðrunun ekranda gösterilmesi 
					   // Doðruyu çizmek için 2 adet nokta belirlenir. Ve bu noktalar aðýrlýklara göre hesaplanýr.
					   // 1. noktanýn x deðeri
					   i++;
				   }
			   }
			   xMin = -half_width;
			   // 1. noktanýn y deðeri
			   yMin = YPoint(xMin, w);
			   // 2. noktanýn x deðeri
			   xMax = half_width;
			   // 2. noktanýn y deðeri
			   yMax = YPoint(xMax, w);

			   // Doðrular çarpýþmasýn diye	
			   picMain->Refresh();
			   picMain->CreateGraphics()->DrawLine(pen, (float)0, half_height - yMin, (float)picMain->Width, half_height - yMax);
			   lblCycle->Visible = true;
			   lblCycle->Text = "Number of Cycles\nDiscrete Perceptron: " + cycleNumber;

			   for (int n = 0; n < Total; n++)
			   {
				   // class1 elemanlarý					
				   if (sample[n].Class == Class1) _brushC1 = gcnew SolidBrush(Color::IndianRed);
				   // class2 elemanlarý					   
				   else if (sample[n].Class == Class2) _brushC1 = gcnew SolidBrush(Color::BlueViolet);  

				   x_before = sample[n].X + half_width;
				   y_before = half_height - sample[n].Y;
				   picMain->CreateGraphics()->FillEllipse(_brushC1, x_before - 5, y_before, 8, 8);
			   }
		   }

		   /// <summary>
		   /// Tek katmanlý tek seviyeli sürekli öðrenme için Normalizasyon iþlemi gerçekleþtirilir.
		   /// </summary>
		   Void btnNormalize_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (!(SizeC1 && SizeC2)) { MessageBox::Show("Lütfen en az 2 farklý örnek belirtiniz", "Uyarý", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }
			   if (!w) { MessageBox::Show("Baþlangýç doðrusu belirtilmemiþ!", "Uyarý", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }

			   float totalX = 0, totalY = 0, avgX = 0, avgY = 0;
			   float powX = 0, powY = 0, varY = 0;

			   for (int i = 0; i < Total; i++)
			   {
				   // X'lerin toplamý
				   totalX += sample[i].X;
				   // Y'lerin toplamý
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

			   MessageBox::Show("Normalizasyon iþlemi gerçekleþtirilmiþtir.", "Bilgi", MessageBoxButtons::OK, MessageBoxIcon::Information);
		   }

		   /// <summary>
		   /// Tek katmanlý tek seviyeli sürekli öðrenmeyi gerçekleþtiren algoritma
		   /// </summary>
		   Void btnContinuousSS_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (!varX) { MessageBox::Show("Normalizasyon iþlemi gerçekleþtirilmemiþ!", "Uyarý", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }

			   // aðýrlýk dizisinin indislerini kontrol etmek için
			   int k = 0;
			   // bellek alanýný kontrol etmek için
			   int i = 0;
			   // 'fNet' value in the formula 
			   float fNet = 0;
			   // hata deðerini kontrol etmek için
			   float Error = 1;                                               
			   int lamda = 1;
			   // 'net' value in the formula 
			   float net = 0;                                                  
			   float omega = 0;
			   // Hata sayýsý kaç döngüde sýfýrdan küçük olacak 
			   int cycleNumber = 0;
			   // fNet deðerinin türevi
			   float fNetDer = 0;								                
			   Pen^ pen = gcnew Pen(Color::AliceBlue, 3.0f);

			   while (Error > 0.01)
			   {
				   cycleNumber++;
				   Error = 0;
				   i = 0;
				   while (i < Total) {
					   k = 0;

					   // net = w[0]*x1 + w[1]*y1 + w[2]*ConstNum 
					   net = (w[k] * sample[i].X) + (w[k + 1] * sample[i].Y) + (w[k + 2] * sample[i].Const);

					   // fNet = ( 2 / ( 1 + e^-lamda*net) ) -1;
					   fNet = (2 / (1 + Math::Exp(-lamda * net))) - 1;
					   // fNetDerivative = 0.5 * ( 1 - (fNet^2) );
					   fNetDer = 0.5 * (1 - Math::Pow(fNet, 2));            

					   // omega = m * (d - fNet) * fNetDerivative
					   omega = (float)(M * (sample[i].Class - fNet)) * fNetDer;
					   // w[k]    = m * (d - fNet) * fNetDerivative * x1
					   w[k] += (omega * sample[i].X);
					   // w[k+1]  = m * (d - fNet) * fNetDerivative * x2
					   w[k + 1] += (omega * sample[i].Y);
					   // w[k+2]  = m * (d - fNet) * fNetDerivative * x3
					   w[k + 2] += (omega * sample[i].Const);                 

					   // Error += 1 / 2 * ((d - fNet) ^ 2);
					   Error += 0.5 * (Math::Pow(sample[i].Class - fNet, 2)); 

					   // Doðrunun ekranda gösterilmesi 
					   // Doðruyu çizmek için 2 adet nokta belirlenir
					   // Noktalarý görebilmek için * 15 oranýnda büyütürüz.
					   // Çizilen doðrular içinde w[2] deðerini 15 ile çarparýz.
					   
					   // 1. noktanýn x deðeri
					   xMin = -half_width;
					   // 1. noktanýn y deðeri
					   yMin = YPoint(xMin, w, 0, 15);
					   // 2. noktanýn x deðeri
					   xMax = half_width;
					   // 2. noktanýn y deðeri
					   yMax = YPoint(xMax, w, 0, 15);						      

					   // Çizilen doðrularýn üst üste gelmemesi için
					   picMain->Refresh();											   
					   picMain->CreateGraphics()->DrawLine(pen, (float)0, half_height - yMin, (float)picMain->Width, half_height - yMax);
					   i++;
				   }
			   }
		   	
			   lblCycle->Visible = true;
			   lblCycle->Text = "Number of Cycles\nContinuous Perceptron: " + cycleNumber;
			   for (int n = 0; n < Total; n++)
			   {
				   // class1 elemanlarý						
				   if (sample[n].Class == Class1) _brushC2 = gcnew SolidBrush(Color::IndianRed);
				   // class2 elemanlarý					   
				   else if (sample[n].Class == Class2) _brushC2 = gcnew SolidBrush(Color::BlueViolet);  

				   x_before = (sample[n].X * 15) + half_width;
				   y_before = half_height - (sample[n].Y * 15);
				   picMain->CreateGraphics()->FillEllipse(_brushC2, x_before - 5, y_before, 8, 8);
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
		   /// Geri dönme iþlemi gerçekleþtirir
		   /// </summary>
		   Void btnBack_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   DialogResult = Windows::Forms::DialogResult::OK;
		   }
};
}

