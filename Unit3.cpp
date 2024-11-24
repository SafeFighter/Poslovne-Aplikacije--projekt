//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit7.h"
#include <jpeg.hpp>
#include <pngimage.hpp>
#include <System.hpp>
#include <Vcl.Dialogs.hpp>
#include <System.JSON.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma link "frxExportRTF"
#pragma link "frCoreClasses"
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma resource "*.dfm"
TPocetna *Pocetna;
void __fastcall TPocetna::translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation) {
	for (int i = 0; i < Form->ComponentCount; i++) {
		for (auto it_ComponentName = translation.begin(); it_ComponentName != translation.end(); it_ComponentName++) {
			if (Form->Components[i]->Name == it_ComponentName->first) {
				for (auto it_Language = it_ComponentName->second.begin(); it_Language != it_ComponentName->second.end(); it_Language++) {
					if (it_Language->first == Language) {
						if (IsPublishedProp(Form->Components[i], "Caption")) {
							SetPropValue(Form->Components[i], "Caption", it_Language->second);
						}
					}
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
__fastcall TPocetna::TPocetna(TComponent* Owner)
	: TForm(Owner)
{
		 ADOConnection1->Connected=true;
	ADOQuery1->SQL->Text="SELECT Naziv FROM igre";
	ADOQuery1->Open();

	while(!ADOQuery1->Eof){
		String naziv = ADOQuery1 -> FieldByName("Naziv")->AsString;
		ComboBox1->Items->Add(naziv);

		ADOQuery1->Next();


	}

		  ADOQuery1->Close();

		  DBGrid1->DataSource = DIgre;

		  Image1->Picture->Assign(nullptr);


		  translation["btnFilter"] = {
    {
        {"ENG", "Filter"},
        {"HRV", "Filtar"}
    }
};

translation["btnOdjava"] = {
    {
        {"ENG", "Logout"},
        {"HRV", "Odjava"}
    }
};

translation["Button2"] = {
    {
        {"ENG", "Profile"},
        {"HRV", "Profil"}
    }
};

translation["btnPreuzmi"] = {
    {
        {"ENG", "Download Witcher Background"},
        {"HRV", "Preuzmi Witcher pozadinu"}
    }
};

translation["btnReport"] = {
    {
        {"ENG", "Report"},
        {"HRV", "Izvještaj"}
    }
};

translation["btnResetFilter"] = {
	{
		{"ENG", "Reset Filter"},
		{"HRV", "Poništi filtar"}
	}
};

translation["btnUcitajTablicu"] = {
    {
        {"ENG", "Load Table"},
        {"HRV", "Učitaj tablicu"}
    }
};

translation["Label2"] = {
    {
        {"ENG", "Game Selection"},
        {"HRV", "Odabir igre"}
    }
};

translation["Label3"] = {
    {
        {"ENG", "Sorting"},
        {"HRV", "Sortiranje"}
    }
};

translation["Label4"] = {
    {
        {"ENG", "Filter"},
        {"HRV", "Filtar"}
    }
};

translation["Pregled"] = {
    {
        {"ENG", "Free Games on EpicGames"},
        {"HRV", "Besplatne igre na EpicGames"}
    }
};

translation["Button2"] = {
	{
		{"ENG", "Change adress"},
		{"HRV", "Izmijeni adresu"}
	}
};

translation["Button1"] = {
	{
		{"ENG", "Delete account"},
		{"HRV", "Obriši račun"}
	}
};

}
//---------------------------------------------------------------------------
void __fastcall TPocetna::btnOdjavaClick(TObject *Sender)
{

	Hide();
	Prijava->Show();
	if (ComboBox4->Text=="HRV"){
				ShowMessage("Uspješna odjava");
			}else {ShowMessage("Successful logout");}


}
//---------------------------------------------------------------------------

void __fastcall TPocetna::FormClose(TObject *Sender, TCloseAction &Action)
{
	   /* 4. funkcionalnost upisivanje u registar*/

		TRegistry *reg = new TRegistry;
		reg->RootKey = HKEY_CURRENT_USER;
		UnicodeString key = "Software\\AppJezik";
		String selectedLanguage = ComboBox4->Text;

		reg->CreateKey(key);
		if (reg->OpenKey(key, true)) {
			reg->WriteString("Jezik", selectedLanguage);
			reg->CloseKey();
		}

		delete reg;
	   /* 4. funkcionalnost upisivanje u registar*/

	Application->Terminate();
}
//---------------------------------------------------------------------------



void TPocetna::PrikaziSlikuIzBaze()
{
	/* 9. funkcionalnost prikaz slika */

	TMemoryStream *blobStream = new TMemoryStream;
	try
	{
		// Provjeri postoji li sadržaj u polju "Slika"
		if (!ADOQuery1->FieldByName("Slika")->IsNull)
		{
			// Dohvati BLOB polje i spremi ga u memoriju
			TBlobField *blobField = static_cast<TBlobField*>(ADOQuery1->FieldByName("Slika"));
			blobStream->Clear();
			blobField->SaveToStream(blobStream);

			// Postavi sliku iz memorije u TImage komponentu
			blobStream->Position = 0;
			Image1->Picture->LoadFromStream(blobStream);
		}
		else
		{
			// Ako je polje "Slika" NULL, postavi praznu sliku u TImage komponentu
			Image1->Picture->Assign(nullptr);
		}
	}
	catch (Exception &e)
	{
		ShowMessage("Došlo je do greške pri prikazu slike: " + e.Message);
	}

	// Oslobodi resurse
	delete blobStream;
}



void __fastcall TPocetna::SetUsername(String korisnickoIme)
{
	/*2. funckionalnost dohvat postavljenog korisničkog imena sa forme Prijava*/
	/* 7. FUNKCIONALNOST citanje imena i prezimena korisnika iz baze */

	ADOQuery3->SQL->Text = "SELECT ime, prezime FROM korisnici WHERE korisnicko_ime = :korisnickoIme";
	ADOQuery3->Parameters->ParamByName("korisnickoIme")->Value = korisnickoIme;
	ADOQuery3->Open();

	/*Funkcionalnost 23 dekriptiranje imena i prezimena korisnik */
	String kriptiranoIme = ADOQuery3->FieldByName("ime")->AsString;
	String kriptiranoPrezime = ADOQuery3->FieldByName("prezime")->AsString;

	String kljuc = "kljuc";
	String dekriptiranoIme;
	String dekriptiranoPrezime;

	Codec1->CryptoLibrary = CryptographicLibrary1;
	Codec1->Password = kljuc;
	Codec1->DecryptString(dekriptiranoIme, kriptiranoIme, TEncoding::UTF8);
	Codec1->DecryptString(dekriptiranoPrezime, kriptiranoPrezime, TEncoding::UTF8);
	/*Funkcionalnost 23 dekriptiranje imena i prezimena korisnik */

	Label1->Caption =korisnickoIme + ", "+ dekriptiranoIme + " " + dekriptiranoPrezime + "!";


}

void TPocetna::SetJezik(String jezik)
{
	/*2. funckionalnost dohvat postavljenog jezika sa forme Prijava*/

	odabraniJezik = jezik;
	 if (odabraniJezik == "ENG") {
		ComboBox4->ItemIndex = 1;
	} else if (odabraniJezik == "HRV") {
		ComboBox4->ItemIndex = 0;
	}

	translateForm(this, odabraniJezik, translation);

}


//---------------------------------------------------------------------------

void __fastcall TPocetna::ComboBox1Change(TObject *Sender)
{
		  /*7. funkcionalnost ucitaj recenziju u memo */


	if (ComboBox1->ItemIndex != -1) {

		String odabranaIgra = ComboBox1->Items->Strings[ComboBox1->ItemIndex];


		ADOQuery1->SQL->Text = "SELECT * FROM igre WHERE Naziv = :Naziv";
		ADOQuery1->Parameters->ParamByName("Naziv")->Value = odabranaIgra;


		ADOQuery1->Open();

		int idIgre = ADOQuery1->FieldByName("ID")->AsInteger;


		ADOQuery2->SQL->Text = "SELECT Sadrzaj_recenzija FROM recenzije WHERE ID_igre = :id_igre";
		ADOQuery2->Parameters->ParamByName("id_igre")->Value = idIgre;
		ADOQuery2->Open();

		if (!ADOQuery2->FieldByName("Sadrzaj_recenzija")->IsNull)
		{
			Memo1->Text = ADOQuery2->FieldByName("Sadrzaj_recenzija")->AsString;
		}
		else
		{
            Memo1->Clear();
        }

		PrikaziSlikuIzBaze();
	}
}

void __fastcall TPocetna::UcitajTablicu()
{
	/* 7. funkcionalnost ucitavanje podataka iz tablice igre*/

	ADOQuery1->Close();

	ADOQuery1->SQL->Text = "SELECT * FROM igre";

	ADOQuery1->Open();


	ComboBox1->ItemIndex = -1;
	ComboBox2->ItemIndex = -1;
	ComboBox3->ItemIndex = -1;
	Memo1->Clear();
	Image1->Picture->Assign(nullptr);

}

void __fastcall TPocetna::btnUcitajTablicuClick(TObject *Sender)
{
	UcitajTablicu();
}
//---------------------------------------------------------------------------

void __fastcall TPocetna::ComboBox2Change(TObject *Sender)
{

/* 8 funkcionalnost sortiranje */
if (ComboBox2->Text == "A-Z")
	{
		ADOQuery1->SQL->Text = "SELECT * FROM igre ORDER BY Naziv ASC";
		ADOQuery1->Active = true;
	}
	else if (ComboBox2->Text == "Z-A")
	{
		ADOQuery1->SQL->Text = "SELECT * FROM igre ORDER BY Naziv DESC";
		ADOQuery1->Active = true;
	}

	else if (ComboBox2->Text == "Najveća cijena/MaxPrice")
	{
		ADOQuery1->SQL->Text = "SELECT * FROM igre ORDER BY Cijena DESC";
		ADOQuery1->Active = true;
	}
	else if (ComboBox2->Text == "Najmanja cijena/MinPrice")
	{
		ADOQuery1->SQL->Text = "SELECT * FROM igre ORDER BY Cijena ASC";
		ADOQuery1->Active = true;
	}


}
//---------------------------------------------------------------------------

void __fastcall TPocetna::FormCreate(TObject *Sender)
{
	ComboBox2->Items->Add("A-Z");
	ComboBox2->Items->Add("Z-A");
	ComboBox2->Items->Add("Najveća cijena/MaxPrice");
	ComboBox2->Items->Add("Najmanja cijena/MinPrice");
	ComboBox3->Items->Add("Ocjena veća od/Grade higher than");
	ComboBox3->Items->Add("Ocjena manja od/Grade lesser than");
	UcitajTablicu();


}
//---------------------------------------------------------------------------

void __fastcall TPocetna::btnFiltarClick(TObject *Sender)
{
   /*8. funkcionalnost filtriranje */
	String filterValue;

	if (ComboBox4->Text == "HRV")
	{
		filterValue = InputBox("Unos ocjene", "Unesite ocjenu:", "");
	}
	else
	{
		filterValue = InputBox("Enter rating", "Enter the rating:", "");
	}

    if (!filterValue.IsEmpty())
    {
        int rating = StrToIntDef(filterValue, -1);
        if (rating != -1)
        {
			if (ComboBox3->Text == "Ocjena veća od/Grade higher than")
			{
                ADOQuery1->SQL->Text = "SELECT * FROM igre WHERE Ocjena > " + IntToStr(rating);
                ADOQuery1->Active = true;
            }
			else if (ComboBox3->Text == "Ocjena manja od/Grade lesser than")
            {
                ADOQuery1->SQL->Text = "SELECT * FROM igre WHERE Ocjena < " + IntToStr(rating);
                ADOQuery1->Active = true;
            }
		}
        else
        {
            if (ComboBox4->Text == "HRV")
            {
                ShowMessage("Unesite ispravan broj za ocjenu.");
            }
            else
            {
                ShowMessage("Enter a valid number for the rating.");
            }
        }
    }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TPocetna::btnResetFilterClick(TObject *Sender)
{
	UcitajTablicu();
}
//---------------------------------------------------------------------------

void __fastcall TPocetna::btnReportClick(TObject *Sender)
{
    /* 10. funkcionalnost */
	frxReport1->ShowReport();
}
//---------------------------------------------------------------------------

void __fastcall TPocetna::btnPreuzmiClick(TObject *Sender)
{
	Hide();
	Preuzmi->Show();
}
//---------------------------------------------------------------------------

void __fastcall TPocetna::PregledClick(TObject *Sender)
{

    /* 20. funkcionalnost REST */

	RESTRequest1->AddAuthParameter("X-RapidAPI-Key", "4193788d77mshf52f1fa1f2b0454p12c217jsnfff84eefbd15", TRESTRequestParameterKind::pkHTTPHEADER);
	RESTRequest1->AddParameter("X-RapidAPI-Host", "epic-free-games1.p.rapidapi.com");

	RESTRequest1->Execute();

	String ApiResponse = RESTResponse1->Content;

	ShowMessage(ApiResponse);
}

void __fastcall TPocetna::ComboBox4Change(TObject *Sender)
{
	String selectedLanguage=ComboBox4->Text;
	translateForm(this, selectedLanguage, translation);
}
//---------------------------------------------------------------------------



void __fastcall TPocetna::Button2Click(TObject *Sender)
{
	String korisnickoIme;


		if (ComboBox4->Text == "HRV")
		{
			korisnickoIme = InputBox("Unos korisničkog imena", "Unesite svoje korisničko ime:", "");
		}
		else
		{
			korisnickoIme = InputBox("Enter username", "Enter your username", "");
		}




		if (korisnickoIme.IsEmpty())
		{
				if (ComboBox4->Text=="HRV"){
						ShowMessage("Niste unjeli korisničko ime");
					}else {ShowMessage("You need to enter username");}

			return;
		}



	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT COUNT(*) AS BrojKorisnika FROM korisnici WHERE korisnicko_ime = :username");
	ADOQuery1->Parameters->ParamByName("username")->Value = korisnickoIme;

	ADOQuery1->Open();
	int brojKorisnika = ADOQuery1->FieldByName("BrojKorisnika")->AsInteger;
	ADOQuery1->Close();

	if (brojKorisnika == 0)
	{
			if (ComboBox4->Text=="HRV"){
				ShowMessage("Pogrešno korisničko ime");
			}else {ShowMessage("Wrong username");}

		return;
    }



		String novaAdresa;

		if (ComboBox4->Text == "HRV")
		{
			novaAdresa = InputBox("Unos nove adrese", "Unesite novu adresu:", "");
		}
		else
		{
			novaAdresa = InputBox("Enter new address", "Enter your new address:", "");
		}

		if (novaAdresa.IsEmpty())
		{
				if (ComboBox4->Text=="HRV"){
						ShowMessage("Niste unjeli adresu");
					}else {ShowMessage("You didn't enter new adress");}

			return;
		}


		/* 7. FUNKCIONALNOST ažuriranje adrese korisnika u bazi */
ADOQuery1->SQL->Clear();
ADOQuery1->SQL->Add("UPDATE korisnici SET adresa = :novaAdresa WHERE korisnicko_ime = :username");

ADOQuery1->Parameters->ParamByName("novaAdresa")->Value = novaAdresa;
ADOQuery1->Parameters->ParamByName("username")->Value = korisnickoIme;


    ADOQuery1->ExecSQL();
		if (ComboBox4->Text=="HRV"){
				ShowMessage("Adresa ažurirana");
			}else {ShowMessage("Adress updated");}



}
//---------------------------------------------------------------------------



void __fastcall TPocetna::Button1Click(TObject *Sender)
{
	String korisnickoIme;

    if (ComboBox4->Text == "HRV")
    {
		korisnickoIme = InputBox("Unos korisničkog imena", "Unesite svoje korisničko ime:", "");
    }
	else
    {
        korisnickoIme = InputBox("Enter username", "Enter your username", "");
    }

    if (korisnickoIme.IsEmpty())
    {
        if (ComboBox4->Text == "HRV")
        {
            ShowMessage("Niste unijeli korisničko ime.");
        }
        else
        {
            ShowMessage("You didn't enter your username.");
        }
        return;
    }

	UnicodeString potvrdaPoruka;
	UnicodeString naslovPoruke;
	if (ComboBox4->Text == "HRV")
	{
		potvrdaPoruka = L"Jeste li sigurni da želite izbrisati račun?";
		naslovPoruke = L"Potvrda brisanja računa";
	}
	else
	{
		potvrdaPoruka = L"Are you sure you want to delete your account?";
		naslovPoruke = L"Account deletion confirmation";
	}

	if (Application->MessageBox(potvrdaPoruka.c_str(), naslovPoruke.c_str(), MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		/* 7. FUNKCIONALNOST brisanje korisničkog računa */
		// Izvršavanje SQL upita za brisanje računa
		String sqlDelete = "DELETE FROM korisnici WHERE korisnicko_ime = :username";
		TADOQuery *query = new TADOQuery(NULL);
        query->Connection = ADOConnection1;


			query->SQL->Add(sqlDelete);
			query->Parameters->ParamByName("username")->Value = korisnickoIme;
            query->ExecSQL();

            if (ComboBox4->Text == "HRV")
			{
                ShowMessage("Vaš račun je uspješno izbrisan!");
			}
            else
			{
                ShowMessage("Your account has been deleted!");
			}

			Hide();
			Prijava->Show();
		delete query;

}
}
//---------------------------------------------------------------------------




