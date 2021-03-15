#pragma once

namespace ArtNeuNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MLML : public System::Windows::Forms::Form
	{
	public:	MLML(void)
	{
		InitializeComponent();
	}
	protected: ~MLML()
	{
		if (components)
		{
			delete components;
		}
	}
	private: System::Windows::Forms::PictureBox^ picMain;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ operationsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ btnRandom;
	private: System::Windows::Forms::ToolStripMenuItem^ btnDiscreteSM;
	private: System::Windows::Forms::ToolStripMenuItem^ btnContinuousSM;
	private: System::Windows::Forms::TextBox^ txtClassNumber;
	private: System::Windows::Forms::ComboBox^ cbClass;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnNormalize;
	private: System::Windows::Forms::ListBox^ listValue;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblCycle;
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::Label^ label1;
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
			   this->txtClassNumber = (gcnew System::Windows::Forms::TextBox());
			   this->cbClass = (gcnew System::Windows::Forms::ComboBox());
			   this->btnBack = (gcnew System::Windows::Forms::Button());
			   this->btnClear = (gcnew System::Windows::Forms::Button());
			   this->btnNormalize = (gcnew System::Windows::Forms::Button());
			   this->listValue = (gcnew System::Windows::Forms::ListBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->lblCycle = (gcnew System::Windows::Forms::Label());
			   this->lblTotal = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMain))->BeginInit();
			   this->menuStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // picMain
			   // 
			   this->picMain->BackColor = System::Drawing::Color::Thistle;
			   this->picMain->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->picMain->Location = System::Drawing::Point(12, 49);
			   this->picMain->Name = L"picMain";
			   this->picMain->Size = System::Drawing::Size(639, 570);
			   this->picMain->TabIndex = 26;
			   this->picMain->TabStop = false;
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->operationsToolStripMenuItem });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1091, 26);
			   this->menuStrip1->TabIndex = 27;
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
			   // 
			   // btnDiscreteSM
			   // 
			   this->btnDiscreteSM->ForeColor = System::Drawing::Color::Green;
			   this->btnDiscreteSM->Name = L"btnDiscreteSM";
			   this->btnDiscreteSM->Size = System::Drawing::Size(186, 22);
			   this->btnDiscreteSM->Text = L"Discrete";
			   // 
			   // btnContinuousSM
			   // 
			   this->btnContinuousSM->ForeColor = System::Drawing::Color::Green;
			   this->btnContinuousSM->Name = L"btnContinuousSM";
			   this->btnContinuousSM->Size = System::Drawing::Size(186, 22);
			   this->btnContinuousSM->Text = L"Continuous";
			   // 
			   // txtClassNumber
			   // 
			   this->txtClassNumber->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.25F));
			   this->txtClassNumber->Location = System::Drawing::Point(668, 72);
			   this->txtClassNumber->Multiline = true;
			   this->txtClassNumber->Name = L"txtClassNumber";
			   this->txtClassNumber->Size = System::Drawing::Size(266, 29);
			   this->txtClassNumber->TabIndex = 37;
			   // 
			   // cbClass
			   // 
			   this->cbClass->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cbClass->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->cbClass->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.25F));
			   this->cbClass->IntegralHeight = false;
			   this->cbClass->ItemHeight = 17;
			   this->cbClass->Location = System::Drawing::Point(668, 136);
			   this->cbClass->Name = L"cbClass";
			   this->cbClass->Size = System::Drawing::Size(266, 25);
			   this->cbClass->TabIndex = 36;
			   // 
			   // btnBack
			   // 
			   this->btnBack->BackColor = System::Drawing::Color::Linen;
			   this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnBack->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->btnBack->Location = System::Drawing::Point(797, 590);
			   this->btnBack->Name = L"btnBack";
			   this->btnBack->Size = System::Drawing::Size(127, 31);
			   this->btnBack->TabIndex = 33;
			   this->btnBack->Text = L"Geri Dön";
			   this->btnBack->UseVisualStyleBackColor = false;
			   // 
			   // btnClear
			   // 
			   this->btnClear->BackColor = System::Drawing::Color::Linen;
			   this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnClear->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->btnClear->Location = System::Drawing::Point(668, 590);
			   this->btnClear->Name = L"btnClear";
			   this->btnClear->Size = System::Drawing::Size(127, 31);
			   this->btnClear->TabIndex = 34;
			   this->btnClear->Text = L"Temizle";
			   this->btnClear->UseVisualStyleBackColor = false;
			   // 
			   // btnNormalize
			   // 
			   this->btnNormalize->BackColor = System::Drawing::Color::LightBlue;
			   this->btnNormalize->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnNormalize->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->btnNormalize->Location = System::Drawing::Point(668, 553);
			   this->btnNormalize->Name = L"btnNormalize";
			   this->btnNormalize->Size = System::Drawing::Size(256, 31);
			   this->btnNormalize->TabIndex = 35;
			   this->btnNormalize->Text = L"Normalizasyon Gerçekleştir";
			   this->btnNormalize->UseVisualStyleBackColor = false;
			   // 
			   // listValue
			   // 
			   this->listValue->BackColor = System::Drawing::Color::White;
			   this->listValue->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
			   this->listValue->ForeColor = System::Drawing::Color::SteelBlue;
			   this->listValue->FormattingEnabled = true;
			   this->listValue->ItemHeight = 14;
			   this->listValue->Location = System::Drawing::Point(940, 72);
			   this->listValue->Name = L"listValue";
			   this->listValue->SelectionMode = System::Windows::Forms::SelectionMode::None;
			   this->listValue->Size = System::Drawing::Size(141, 550);
			   this->listValue->TabIndex = 32;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->label2->Location = System::Drawing::Point(744, 109);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(100, 18);
			   this->label2->TabIndex = 28;
			   this->label2->Text = L"Select Class:";
			   // 
			   // lblCycle
			   // 
			   this->lblCycle->AutoSize = true;
			   this->lblCycle->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->lblCycle->Location = System::Drawing::Point(665, 247);
			   this->lblCycle->Name = L"lblCycle";
			   this->lblCycle->Size = System::Drawing::Size(47, 18);
			   this->lblCycle->TabIndex = 30;
			   this->lblCycle->Text = L"Cycle";
			   this->lblCycle->Visible = false;
			   // 
			   // lblTotal
			   // 
			   this->lblTotal->AutoSize = true;
			   this->lblTotal->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->lblTotal->Location = System::Drawing::Point(665, 290);
			   this->lblTotal->Name = L"lblTotal";
			   this->lblTotal->Size = System::Drawing::Size(43, 18);
			   this->lblTotal->TabIndex = 31;
			   this->lblTotal->Text = L"Total";
			   this->lblTotal->Visible = false;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->label1->Location = System::Drawing::Point(723, 49);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(152, 18);
			   this->label1->TabIndex = 29;
			   this->label1->Text = L"Write Class Number:";
			   // 
			   // MLML
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Thistle;
			   this->ClientSize = System::Drawing::Size(1091, 633);
			   this->Controls->Add(this->picMain);
			   this->Controls->Add(this->menuStrip1);
			   this->Controls->Add(this->txtClassNumber);
			   this->Controls->Add(this->cbClass);
			   this->Controls->Add(this->btnBack);
			   this->Controls->Add(this->btnClear);
			   this->Controls->Add(this->btnNormalize);
			   this->Controls->Add(this->listValue);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->lblCycle);
			   this->Controls->Add(this->lblTotal);
			   this->Controls->Add(this->label1);
			   this->Name = L"MLML";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Multi Layer Multi Level";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMain))->EndInit();
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   Void txtClassNumber_TextChanged(System::Object^ sender, System::EventArgs^ e)
		   {

		   }


		   Void btnManual_Click(System::Object^ sender, System::EventArgs^ e)
		   {

		   }


		   Void btnRandom_Click(System::Object^ sender, System::EventArgs^ e)
		   {

		   }


		   Void btnDiscreteSM_Click(System::Object^ sender, System::EventArgs^ e)
		   {

		   }


		   Void btnContinuousSM_Click(System::Object^ sender, System::EventArgs^ e)
		   {

		   }


		   Void btnNormalize_Click(System::Object^ sender, System::EventArgs^ e)
		   {

		   }


		   Void btnBack_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   DialogResult = Windows::Forms::DialogResult::OK;
		   }


		   Void btnDelSamples_Click(System::Object^ sender, System::EventArgs^ e)
		   {

		   }
	};
}
