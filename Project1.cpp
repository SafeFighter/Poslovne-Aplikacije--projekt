//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit3.cpp", Pocetna);
USEFORM("Unit4.cpp", AdminPrijava);
USEFORM("Unit5.cpp", PocetnaAdmin);
USEFORM("Unit6.cpp", DodajRecenziju);
USEFORM("Unit7.cpp", Preuzmi);
USEFORM("Unit2.cpp", Registracija);
USEFORM("Unit1.cpp", Prijava);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TPrijava), &Prijava);
		Application->CreateForm(__classid(TRegistracija), &Registracija);
		Application->CreateForm(__classid(TPocetna), &Pocetna);
		Application->CreateForm(__classid(TAdminPrijava), &AdminPrijava);
		Application->CreateForm(__classid(TPocetnaAdmin), &PocetnaAdmin);
		Application->CreateForm(__classid(TDodajRecenziju), &DodajRecenziju);
		Application->CreateForm(__classid(TPreuzmi), &Preuzmi);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
