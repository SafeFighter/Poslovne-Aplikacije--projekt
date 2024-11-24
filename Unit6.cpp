#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit5.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDodajRecenziju *DodajRecenziju;
//---------------------------------------------------------------------------
__fastcall TDodajRecenziju::TDodajRecenziju(TComponent* Owner)
    : TForm(Owner)
{
    DodajPodatke();

    translation["btnOdustani"] = {
        { {"ENG", "Cancel"}, {"HRV", "Odustani"} }
    };
    translation["btnOsvjezi"] = {
        { {"ENG", "Refresh"}, {"HRV", "Osvježi"} }
    };
    translation["btnSpremi"] = {
        { {"ENG", "Save"}, {"HRV", "Spremi"} }
    };
    translation["btnIzmijeni"] = {
        { {"ENG", "Edit"}, {"HRV", "Izmijeni"} }
    };
}
//---------------------------------------------------------------------------
void __fastcall TDodajRecenziju::btnOdustaniClick(TObject *Sender)
{
    Hide();
    PocetnaAdmin->Show();
}
//---------------------------------------------------------------------------
void __fastcall TDodajRecenziju::btnSpremiClick(TObject *Sender)
{
	/*7. funkcionalnost spremi recenziju u bazu */

    String recenzija = Memo1->Text;
    String nazivIgre = ComboBox1->Text;
    int idIgre = -1;

    ADOQuery1->SQL->Clear();
    ADOQuery1->SQL->Text = "SELECT id FROM igre WHERE naziv = :naziv";
    ADOQuery1->Parameters->ParamByName("naziv")->Value = nazivIgre;
    ADOQuery1->Open();

    if (!ADOQuery1->Eof) {
        idIgre = ADOQuery1->FieldByName("id")->AsInteger;
    }
    ADOQuery1->Close();

    if (idIgre == -1) {
        if (ComboBox2->Text == "HRV") {  // Provjera jezika pomoću ComboBox2
            ShowMessage("Igra nije pronađena!");
        } else {
            ShowMessage("Game not found");
        }
        return;
    }

    int idKorisnika = idPrijavljenogKorisnika;

    ADOQuery1->SQL->Clear();
    ADOQuery1->SQL->Text = "INSERT INTO recenzije (ID_korisnika, ID_Igre, Sadrzaj_recenzija) VALUES (:idKorisnika, :idIgre, :recenzija)";
    ADOQuery1->Parameters->ParamByName("idKorisnika")->Value = idKorisnika;
    ADOQuery1->Parameters->ParamByName("idIgre")->Value = idIgre;
    ADOQuery1->Parameters->ParamByName("recenzija")->Value = recenzija;
    ADOQuery1->ExecSQL();

    if (ComboBox2->Text == "HRV") {  // Provjera jezika pomoću ComboBox2
        ShowMessage("Recenzija uspješno spremljena!");
    } else {
        ShowMessage("Review saved");
    }
}
//---------------------------------------------------------------------------
void __fastcall TDodajRecenziju::Button1Click(TObject *Sender)
{
	/*7. funkcionalnost ažuriraj recenziju u bazu */

	String recenzija = Memo1->Text;
    String nazivIgre = ComboBox1->Text;
    int idIgre = -1;

    ADOQuery1->SQL->Clear();
    ADOQuery1->SQL->Text = "SELECT id FROM igre WHERE naziv = :naziv";
    ADOQuery1->Parameters->ParamByName("naziv")->Value = nazivIgre;
    ADOQuery1->Open();

    if (!ADOQuery1->Eof) {
        idIgre = ADOQuery1->FieldByName("id")->AsInteger;
    }
    ADOQuery1->Close();

    if (idIgre == -1) {
        if (ComboBox2->Text == "HRV") {  // Provjera jezika pomoću ComboBox2
            ShowMessage("Igra nije pronađena!");
        } else {
            ShowMessage("Game not found");
        }
        return;
    }

    int idKorisnika = idPrijavljenogKorisnika;

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Text = "UPDATE recenzije SET Sadrzaj_recenzija = :recenzija WHERE ID_korisnika = :idKorisnika AND ID_Igre = :idIgre";
	ADOQuery1->Parameters->ParamByName("recenzija")->Value = recenzija;
    ADOQuery1->Parameters->ParamByName("idKorisnika")->Value = idKorisnika;
    ADOQuery1->Parameters->ParamByName("idIgre")->Value = idIgre;
    ADOQuery1->ExecSQL();

    if (ComboBox2->Text == "HRV") {  // Provjera jezika pomoću ComboBox2
        ShowMessage("Recenzija uspješno izmijenjena!");
    } else {
        ShowMessage("Review successfully updated");
    }
}
//---------------------------------------------------------------------------
void __fastcall TDodajRecenziju::ComboBox1Change(TObject *Sender)
{
	/* 7. funkcionalnost citaj recenzije iz baze*/

	if (ComboBox1->ItemIndex != -1) {
		String odabranaIgra = ComboBox1->Items->Strings[ComboBox1->ItemIndex];

        ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Text = "SELECT id FROM igre WHERE Naziv = :Naziv";
		ADOQuery1->Parameters->ParamByName("Naziv")->Value = odabranaIgra;


			ADOQuery1->Open();
			int idIgre = -1;
			if (!ADOQuery1->Eof) {
				idIgre = ADOQuery1->FieldByName("id")->AsInteger;
			}
			ADOQuery1->Close();

			// Dohvati sve recenzije za odabranu igru
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Text = "SELECT Sadrzaj_recenzija FROM recenzije WHERE ID_Igre = :idIgre";
			ADOQuery1->Parameters->ParamByName("idIgre")->Value = idIgre;

			ADOQuery1->Open();
			if (!ADOQuery1->Eof) {
				String sadrzajRecenzije = ADOQuery1->FieldByName("Sadrzaj_recenzija")->AsString;
				Memo1->Text = sadrzajRecenzije;
            } else {
				Memo1->Text = "";  // Ako nema recenzija, očisti memo
            }
            ADOQuery1->Close();

	}
}
//---------------------------------------------------------------------------
void __fastcall TDodajRecenziju::DodajPodatke()
{
	ComboBox1->Clear();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Text = "SELECT Naziv FROM igre";
	ADOQuery1->Open();
	while (!ADOQuery1->Eof) {
		String naziv = ADOQuery1->FieldByName("Naziv")->AsString;
		ComboBox1->Items->Add(naziv);
		ADOQuery1->Next();
	}
	ADOQuery1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TDodajRecenziju::btnOsvjeziClick(TObject *Sender)
{
	DodajPodatke();
}
//---------------------------------------------------------------------------
void __fastcall TDodajRecenziju::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------
void translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation)
{
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
void __fastcall TDodajRecenziju::ComboBox2Change(TObject *Sender)
{
    String selectedLanguage = ComboBox2->Text;
    translateForm(this, selectedLanguage, translation);
}
//---------------------------------------------------------------------------

void __fastcall TDodajRecenziju::Button2Click(TObject *Sender)
{
	/*7. funkcionalnost obriši recenziju u bazi */

	String nazivIgre = ComboBox1->Text;
    int idIgre = -1;

    ADOQuery1->SQL->Clear();
    ADOQuery1->SQL->Text = "SELECT id FROM igre WHERE naziv = :naziv";
    ADOQuery1->Parameters->ParamByName("naziv")->Value = nazivIgre;
    ADOQuery1->Open();

    if (!ADOQuery1->Eof) {
        idIgre = ADOQuery1->FieldByName("id")->AsInteger;
    }
    ADOQuery1->Close();

    if (idIgre == -1) {
        if (ComboBox2->Text == "HRV") {  // Provjera jezika pomoću ComboBox2
            ShowMessage("Igra nije pronađena!");
        } else {
            ShowMessage("Game not found");
        }
        return;
    }

    int idKorisnika = idPrijavljenogKorisnika;

    ADOQuery1->SQL->Clear();
    ADOQuery1->SQL->Text = "DELETE FROM recenzije WHERE ID_korisnika = :idKorisnika AND ID_Igre = :idIgre";
    ADOQuery1->Parameters->ParamByName("idKorisnika")->Value = idKorisnika;
    ADOQuery1->Parameters->ParamByName("idIgre")->Value = idIgre;
    ADOQuery1->ExecSQL();

    if (ComboBox2->Text == "HRV") {  // Provjera jezika pomoću ComboBox2
        ShowMessage("Recenzija uspješno obrisana!");
    } else {
        ShowMessage("Review successfully deleted");
    }

    // Očisti memo nakon brisanja recenzije
    Memo1->Text = "";
}
//---------------------------------------------------------------------------

