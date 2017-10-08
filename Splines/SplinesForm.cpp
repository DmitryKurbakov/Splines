#include "SplinesForm.h"

[STAThreadAttribute]
void Main(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SplinesForm form;
	Application::Run(%form);
}