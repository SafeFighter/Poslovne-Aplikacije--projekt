#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit5.h"
#include <memory>
#include <system.hash.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAdminPrijava *AdminPrijava;
//---------------------------------------------------------------------------
__fastcall TAdminPrijava::TAdminPrijava(TComponent* Owner)
	: TForm(Owner)
{
translation["Label1"] = {
    {
        {"ENG", "Admin Login"},
        {"HRV", "Prijava za administratora"}
    }
};
translation["userName"] = {
    {
        {"ENG", "Username:"},
        {"HRV", "Korisničko ime:"}
    }
};
translation["lozinka"] = {
    {
        {"ENG", "Password:"},
        {"HRV", "Lozinka:"}
    }
};
translation["btnPrijava"] = {
    {
        {"ENG", "Login"},
        {"HRV", "Prijavi se"}
    }
};

translation["Button1"] = {
    {
        {"ENG", "Back"},
        {"HRV", "Povratak"}
    }
};
}
//---------------------------------------------------------------------------
String generirajSol(String korisnickoIme) {
	std::unique_ptr<THashSHA2> sha2(new THashSHA2);
	return sha2->GetHashString(korisnickoIme, THashSHA2::SHA256);
}
void __fastcall TAdminPrijava::btnPrijavaClick(TObject *Sender)
{
	String korisnickoIme = Edit1->Text.Trim();
	String lozinka = Edit2->Text.Trim();
    if (korisnickoIme.IsEmpty() || lozinka.IsEmpty()) {
        ShowMessage("Molimo unesite korisničko ime i lozinku.");
        return;
    }

	// Postavljanje karaktera za lozinku
    Edit2->PasswordChar = '*';

	String sql = "SELECT lozinka, tip_korisnika, ID FROM korisnici WHERE korisnicko_ime = :username";

    TFDQuery *query = new TFDQuery(NULL);
    query->Connection = FDConnection1;
    query->SQL->Text = sql;

	// Postavljanje parametra za korisničko ime
    query->ParamByName("username")->AsString = korisnickoIme;

    // Izvršavanje SQL upita
    query->Open();

	// Provjera postojanja korisnika
    bool authenticated = false;
    if (!query->Eof) {
        String pohranjeniHash = query->FieldByName("lozinka")->AsString;

		// Generiranje soli na osnovu korisničkog imena
        String sol = generirajSol(korisnickoIme);

        // Inicijalizacija SHA-256 hasera
        std::unique_ptr<THashSHA2> sha2(new THashSHA2);

		// Iteracija kroz sve moguće "papre" (a-z)
        for (char c = 'a'; c <= 'z'; ++c) {
            String papar = String(c); // Konkatenacija za formiranje papra

			// Rekonstrukcija hasha koristeći unjete lozinke, soli i papra
            String lozinkaSaSolju = sol + lozinka;
            String hashLozinkeSaSolju = sha2->GetHashString(lozinkaSaSolju, THashSHA2::SHA256);

            String konacniHashInput = hashLozinkeSaSolju + papar;
            String konacniHash = sha2->GetHashString(konacniHashInput, THashSHA2::SHA256);

			// Upoređivanje rekonstruiranog hasha sa pohranjenim hash-om
            if (konacniHash == pohranjeniHash) {
                // Provjera da li je korisnik admin
                String tipKorisnika = query->FieldByName("tip_korisnika")->AsString;
				if (tipKorisnika == "admin") {
					idPrijavljenogKorisnika = query->FieldByName("ID")->AsInteger;
                    authenticated = true;
                    break;
                }
            }
        }
    }

    // Oslobađanje resursa
    delete query;

	if (authenticated) {
		if (ComboBox1->Text == "HRV") {
			ShowMessage("Uspješna prijava!");
		} else {
			ShowMessage("Successful login");
		}
        Hide();
		PocetnaAdmin->Show();
	} else {

		if (ComboBox1->Text == "HRV") {
			ShowMessage("Neuspešna prijava. Provjerite korisničko ime i lozinku ili nemate ovlasti");
		} else {
			ShowMessage("Wrong username or password or you do not have permission to enter here");
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TAdminPrijava::Button1Click(TObject *Sender)
{
		Hide();
		Prijava->Show();
}
//---------------------------------------------------------------------------

int idPrijavljenogKorisnika = -1; // Inicijalizacija globalne varijable za ID prijavljenog korisnika

void __fastcall TAdminPrijava::FormCreate(TObject *Sender)
{
	   Edit2->PasswordChar = '*';
}
//---------------------------------------------------------------------------
void __fastcall TAdminPrijava::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
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

void __fastcall TAdminPrijava::ComboBox1Change(TObject *Sender)
{
    String selectedLanguage=ComboBox1->Text;
	translateForm(this, selectedLanguage, translation);
}
//---------------------------------------------------------------------------

