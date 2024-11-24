//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPreuzmi *Preuzmi;
//---------------------------------------------------------------------------
__fastcall TPreuzmi::TPreuzmi(TComponent* Owner)
	: TForm(Owner)
{
   translation["btnPovratak"] = {
	{
		{"ENG", "Return"},
		{"HRV", "Povratak"}
	}
};
translation["btnPreuzmi"] = {
	{
		{"ENG", "Download"},
		{"HRV", "Preuzmi"}
	}
};
}
//---------------------------------------------------------------------------

	 /* 17. funkcionalnost preuzimanje*/

void __fastcall TPreuzmi::btnPreuzmiClick(TObject *Sender)
{
	if (IdInterceptThrottler1->BitsPerSec == 0)
	{
		if (ComboBox1->Text == "HRV")
		{
			ShowMessage("Molimo odaberite brzinu preuzimanja prije nego što započnete preuzimanje.");
		}
		else
		{
			ShowMessage("Please select a download speed before starting the download.");
		}
		return;
	}

	if (SaveDialog1->Execute())
	{
		String url = "https://cdn.wallpapersafari.com/21/68/gAGD6k.jpg";


		TIdHTTP *http = new TIdHTTP(NULL);
        TMemoryStream *stream = new TMemoryStream;

        try
        {
			http->OnWorkBegin = PreuzmiWorkBegin;
            http->OnWork = PreuzmiWork;
			http->Intercept = IdInterceptThrottler1;

			http->Get(url, stream);

            stream->SaveToFile(SaveDialog1->FileName);
            if (ComboBox1->Text == "HRV")
            {
				ShowMessage("Preuzimanje i spremanje završeno!");
			}
            else
            {
                ShowMessage("Download completed");
			}
        }
        __finally
        {
			delete http;
			delete stream;
		}
	}
}

//---------------------------------------------------------------------------

void __fastcall TPreuzmi::btnPovratakClick(TObject *Sender)
{
	Hide();
	Pocetna->Show();
}
//---------------------------------------------------------------------------

void __fastcall TPreuzmi::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TPreuzmi::Button1Click(TObject *Sender)
{
	IdInterceptThrottler1->BitsPerSec = 40960;
}
//---------------------------------------------------------------------------

void __fastcall TPreuzmi::Button2Click(TObject *Sender)
{
	IdInterceptThrottler1->BitsPerSec = 819200;
}
//---------------------------------------------------------------------------

void __fastcall TPreuzmi::Button3Click(TObject *Sender)
{
	IdInterceptThrottler1->BitsPerSec = 4096000;
}
//---------------------------------------------------------------------------

void __fastcall TPreuzmi::PreuzmiWorkBegin(TObject *ASender, TWorkMode AWorkMode,
		  __int64 AWorkCountMax)
{
    ProgressBar1->Position = 0;
    ProgressBar1->Max = AWorkCountMax;
}
//---------------------------------------------------------------------------

void __fastcall TPreuzmi::PreuzmiWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)
{
	ProgressBar1->Position = AWorkCount;
	int ukupnaVelicina = ProgressBar1->Max;
	int postotakPreuzimanja = (AWorkCount * 100) / ukupnaVelicina;
	Label2->Caption = "Preuzeto: " + IntToStr(postotakPreuzimanja) + "%";
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation){
	for(int i = 0; i < Form->ComponentCount; i++) // iterate though all components on the form
		for(auto it_ComponentName = translation.begin(); it_ComponentName != translation.end(); it_ComponentName++)
			if(Form->Components[i]->Name == it_ComponentName->first) // find component by name
				for(auto it_Language = it_ComponentName->second.begin(); it_Language != it_ComponentName->second.end(); it_Language++)
					if(it_Language->first == Language) // find translation for the target language
						if(IsPublishedProp(Form->Components[i], "Caption"))
							SetPropValue(Form->Components[i], "Caption", it_Language->second);
}




void __fastcall TPreuzmi::ComboBox1Change(TObject *Sender)
{
	String selectedLanguage=ComboBox1->Text;
	translateForm(this, selectedLanguage, translation);
}
//---------------------------------------------------------------------------

