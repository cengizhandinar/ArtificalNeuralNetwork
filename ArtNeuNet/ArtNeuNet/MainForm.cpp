#include "MainForm.h"
using namespace System::Drawing;
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ArtNeuNet::MainForm form;
	Application::Run(% form);
}