#pragma once
#include "SLSL.h"
#include "SLML.h"
#include "MLML.h"
namespace ArtNeuNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:	MainForm(void)
	{
		InitializeComponent();
		btnMLML->Enabled = false;
	}
	protected: ~MainForm()
	{
		if (components)
		{
			delete components;
		}
	}
	private: System::Windows::Forms::Button^ btnSLSL;
	private: System::Windows::Forms::Button^ btnSLML;
	private: System::Windows::Forms::Button^ btnMLML;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->btnSLSL = (gcnew System::Windows::Forms::Button());
			   this->btnSLML = (gcnew System::Windows::Forms::Button());
			   this->btnMLML = (gcnew System::Windows::Forms::Button());
			   this->btnExit = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // btnSLSL
			   // 
			   this->btnSLSL->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->btnSLSL->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnSLSL->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnSLSL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			   this->btnSLSL->Location = System::Drawing::Point(204, 148);
			   this->btnSLSL->Name = L"btnSLSL";
			   this->btnSLSL->Size = System::Drawing::Size(319, 157);
			   this->btnSLSL->TabIndex = 1;
			   this->btnSLSL->Text = L"Working in Single Layer\r\nSingle Level\r\n";
			   this->btnSLSL->UseVisualStyleBackColor = false;
			   this->btnSLSL->Click += gcnew System::EventHandler(this, &MainForm::btnSLSL_Click);
			   // 
			   // btnSLML
			   // 
			   this->btnSLML->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(192)));
			   this->btnSLML->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnSLML->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnSLML->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			   this->btnSLML->Location = System::Drawing::Point(529, 148);
			   this->btnSLML->Name = L"btnSLML";
			   this->btnSLML->Size = System::Drawing::Size(319, 157);
			   this->btnSLML->TabIndex = 2;
			   this->btnSLML->Text = L"Working in Single Layer\r\nMulti Level\r\n";
			   this->btnSLML->UseVisualStyleBackColor = false;
			   this->btnSLML->Click += gcnew System::EventHandler(this, &MainForm::btnSLML_Click);
			   // 
			   // btnMLML
			   // 
			   this->btnMLML->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->btnMLML->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnMLML->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnMLML->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			   this->btnMLML->Location = System::Drawing::Point(364, 311);
			   this->btnMLML->Name = L"btnMLML";
			   this->btnMLML->Size = System::Drawing::Size(319, 157);
			   this->btnMLML->TabIndex = 3;
			   this->btnMLML->Text = L"Working in Multi Layer\r\nMulti Level\r\n";
			   this->btnMLML->UseVisualStyleBackColor = false;
			   this->btnMLML->Click += gcnew System::EventHandler(this, &MainForm::btnMLML_Click);
			   // 
			   // btnExit
			   // 
			   this->btnExit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(128)));
			   this->btnExit->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			   this->btnExit->Location = System::Drawing::Point(982, 571);
			   this->btnExit->Name = L"btnExit";
			   this->btnExit->Size = System::Drawing::Size(97, 50);
			   this->btnExit->TabIndex = 3;
			   this->btnExit->Text = L"EXIT";
			   this->btnExit->UseVisualStyleBackColor = false;
			   this->btnExit->Click += gcnew System::EventHandler(this, &MainForm::btnExit_Click);
			   // 
			   // MainForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Thistle;
			   this->ClientSize = System::Drawing::Size(1091, 633);
			   this->Controls->Add(this->btnExit);
			   this->Controls->Add(this->btnMLML);
			   this->Controls->Add(this->btnSLML);
			   this->Controls->Add(this->btnSLSL);
			   this->Name = L"MainForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"MainForm";
			   this->ResumeLayout(false);

		   }
#pragma endregion

		   Void btnSLSL_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   SLSL^ slsl = gcnew SLSL();
			   this->Hide();
			   Windows::Forms::DialogResult dResult = slsl->ShowDialog();
			   if (dResult == Windows::Forms::DialogResult::OK)
			   {
				   slsl->Hide();
				   this->Show();
			   }
		   }

		   Void btnSLML_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   SLML^ slml = gcnew SLML();
			   this->Hide();
			   Windows::Forms::DialogResult dResult = slml->ShowDialog();
			    if (dResult == Windows::Forms::DialogResult::OK)
				{
					slml->Hide();
					this->Show();
				}
		   }

		   Void btnMLML_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   MLML^ mlml = gcnew MLML();
			   this->Hide();
			   Windows::Forms::DialogResult dResult = mlml->ShowDialog();
			   if (dResult == Windows::Forms::DialogResult::OK)
			   {
				   mlml->Hide();
				   this->Show();
			   }
		   }

		   Void btnExit_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (MessageBox::Show("Uygulama kapatılacaktır. Onaylıyor musunuz?", "Soru", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes)
			   {
				   Application::Exit();
			   }
		   }
};
}
