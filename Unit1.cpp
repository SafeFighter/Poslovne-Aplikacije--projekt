//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include <memory>
#include <system.hash.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrijava *Prijava;

void translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation){
	for(int i = 0; i < Form->ComponentCount; i++) // iterate though all components on the form
		for(auto it_ComponentName = translation.begin(); it_ComponentName != translation.end(); it_ComponentName++)
			if(Form->Components[i]->Name == it_ComponentName->first) // find component by name
				for(auto it_Language = it_ComponentName->second.begin(); it_Language != it_ComponentName->second.end(); it_Language++)
					if(it_Language->first == Language) // find translation for the target language
						if(IsPublishedProp(Form->Components[i], "Caption"))
							SetPropValue(Form->Components[i], "Caption", it_Language->second);
}
//---------------------------------------------------------------------------
__fastcall TPrijava::TPrijava(TComponent* Owner)
	: TForm(Owner)
{
	translation["Label1"] = {
	{
		{"ENG", "Login"},
		{"HRV", "Prijava"}
	}
};
translation["Label2"] = {
	{
		{"ENG", "Username:"},
		{"HRV", "Korisničko ime:"}
    }
};
translation["Label3"] = {
    {
		{"ENG", "Password:"},
		{"HRV", "Lozinka:"}
    }
};
translation["Label4"] = {
	{
		{"ENG", "Don't have an account? Register?"},
		{"HRV", "Nemaš račun? Registriraj se?"}
    }
};
translation["btnPrijava"] = {
    {
		{"ENG", "Login"},
		{"HRV", "Prijavi se"}
    }
};
translation["btnRegistracija"] = {
    {
		{"ENG", "Register"},
		{"HRV", "Registriraj se"}
	}
};
translation["Button1"] = {
    {
		{"ENG", "Admin Login"},
		{"HRV", "Prijava za administratora"}
	}
};



}
void __fastcall TPrijava::ComboBox1Change(TObject *Sender)
{
	String selectedLanguage=ComboBox1->Text;
	translateForm(this, selectedLanguage, translation);
}
//---------------------------------------------------------------------------
// Funkcija za generiranje konzistentne soli na temelju korisničkog imena
String generirajSol(String korisnickoIme) {
	std::unique_ptr<THashSHA2> sha2(new THashSHA2);
	return sha2->GetHashString(korisnickoIme, THashSHA2::SHA256);
}


void __fastcall TPrijava::btnPrijavaClick(TObject *Sender)
{
	/*Funkcionalnost 25 lozinke */

	// Dobivanje korisničkog unosa
	String korisnickoIme = Edit1->Text;
	String lozinka = Edit2->Text;

	Edit2->PasswordChar = '*';

	// Priprema SQL-a za dohvaćanje pohranjenog hash-a
	String sql = "SELECT lozinka FROM korisnici WHERE korisnicko_ime = :username";

	TFDQuery *query = new TFDQuery(NULL);
	query->Connection = FDConnection1;
	query->SQL->Text = sql;

	// Postavljanje parametra za korisničko ime
	query->ParamByName("username")->AsString = korisnickoIme;

	// Izvršavanje SQL upita
	query->Open();

	// Provjera postojanja korisnika
	if (!query->Eof) {
		String pohranjeniHash = query->FieldByName("lozinka")->AsString;

		// Generiranje soli na temelju korisničkog imena
		String sol = generirajSol(korisnickoIme);

		// Iteracija kroz sve moguće papre (a-z)
		std::unique_ptr<THashSHA2> sha2(new THashSHA2);
		bool authenticated = false;
		for (char c = 'a'; c <= 'z'; ++c) {
			String papar = String(c); // Koristimo string konkatenaciju za stvaranje papra
			// Rekonstrukcija hash-a koristeći unesenu lozinku, izvedenu sol i trenutni papar
			String lozinkaSaSolju = sol + lozinka;
			String hashLozinkeSaSolju = sha2->GetHashString(lozinkaSaSolju, THashSHA2::SHA256);

			String konacniHashInput = hashLozinkeSaSolju + papar;
			String konacniHash = sha2->GetHashString(konacniHashInput, THashSHA2::SHA256);

			// Usporedba rekonstruiranog hash-a s pohranjenim hash-om
			if (konacniHash == pohranjeniHash) {
				authenticated = true;
				break;
			}
		}

		if (authenticated) {
			if (ComboBox1->Text=="HRV"){
				ShowMessage("Uspješna prijava!");
			}else {ShowMessage("Successful login");}

		 /*Funkcionalnost 25 lozinke */

			/* 4. funkcionalnost upisivanje u ini datoteku*/
			TDateTime trenutnoVrijeme = Now();
			UnicodeString trenutnoVrijemeString = DateTimeToStr(trenutnoVrijeme);

			UnicodeString nazivFonta = Pocetna->Font->Name;
			UnicodeString velicinaFonta = Pocetna->Font->Size;

			TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
			ini->WriteString("Datum i vrijeme", "Vrijeme prijave", trenutnoVrijemeString);
			ini->WriteString("Font", "Naziv fonta", nazivFonta);
			ini->WriteString("Font", "Veličina fonta", velicinaFonta);
			ini->WriteString("Korisničko ime", "Korisničko ime", korisnickoIme);
			delete ini;
			/* 4. funkcionalnost upisivanje u ini datoteku*/

			Hide();
			TPocetna *Pocetna = new TPocetna(this);
			Pocetna->SetUsername(korisnickoIme);     //2. funkcionalnost
			String odabraniJezik = ComboBox1->Text;  //za prijenos podataka
			Pocetna->SetJezik(odabraniJezik);        //između formi
			Edit1->Clear();
			Edit2->Clear();
			Pocetna->Show();
		} else {
			if (ComboBox1->Text=="HRV"){
				ShowMessage("Neuspješna prijava!");
			}else {ShowMessage("Unsuccessful login");}
		}
	} else {
		if (ComboBox1->Text=="HRV"){
				ShowMessage("Neuspješna prijava!");
			}else {ShowMessage("Unsuccessful login");}
		Edit2->Clear();
	}

	// Oslobađanje memorije
	delete query;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------



void __fastcall TPrijava::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TPrijava::btnRegistracijaClick(TObject *Sender)
{
		Hide();
		Registracija->Show();
}
//---------------------------------------------------------------------------
void __fastcall TPrijava::Button1Click(TObject *Sender)
{
	Hide();
	AdminPrijava->Show();
}
//----------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TPrijava::FormCreate(TObject *Sender)
{
	Edit2->PasswordChar = '*';

	 /* 4. funkcionalnost čitanje iz ini datoteke*/
	 TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	UnicodeString trenutnoVrijemeString = ini->ReadString("Datum i vrijeme", "Vrijeme prijave", "N/A");
	UnicodeString nazivFonta = ini->ReadString("Font", "Naziv fonta", "N/A");
	UnicodeString velicinaFonta = ini->ReadString("Font", "Veličina fonta", "N/A");
	UnicodeString korisnickoIme = ini->ReadString("Korisničko ime", "Korisničko ime", "N/A");
	delete ini;

	UnicodeString poruka = "Vrijeme zadnje prijave: " + trenutnoVrijemeString + "\n" +
						   "Naziv fonta: " + nazivFonta + "\n" +
						   "Veličina fonta: " + velicinaFonta + "\n" +
						   "Korisničko ime: " + korisnickoIme;

	ShowMessage(poruka);

	 /* 4. funkcionalnost čitanje iz ini datoteke*/

	  /* 4. funkcionalnost čitanje iz registra*/

	TRegistry *reg = new TRegistry;
		reg->RootKey = HKEY_CURRENT_USER;
		UnicodeString key = "Software\\AppJezik";
		String selectedLanguage;

		if (reg->OpenKey(key, false)) {
			selectedLanguage = reg->ReadString("Jezik");
			reg->CloseKey();
		}

		delete reg;
		/* 4. funkcionalnost čitanje iz registra*/
	   ComboBox1->ItemIndex = ComboBox1->Items->IndexOf(selectedLanguage);
	   translateForm(this, selectedLanguage, translation);
}
