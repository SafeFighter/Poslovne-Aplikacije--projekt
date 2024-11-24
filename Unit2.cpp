#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include <DateUtils.hpp>
#include <memory>
#include <system.hash.hpp>
#include "CountryInfoService.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Hash"
#pragma link "uTPLb_Codec"
#pragma resource "*.dfm"
TRegistracija *Registracija;
//---------------------------------------------------------------------------
__fastcall TRegistracija::TRegistracija(TComponent* Owner)
	: TForm(Owner)
{
	translation["Label1"] = {
	{
		{"ENG", "Registration"},
		{"HRV", "Registracija"}
	}
};
translation["Label2"] = {
	{
		{"ENG", "First Name:"},
		{"HRV", "Ime:"}
	}
};
translation["Label3"] = {
	{
		{"ENG", "Last Name:"},
        {"HRV", "Prezime:"}
	}
};
translation["Label4"] = {
	{
        {"ENG", "City"},
		{"HRV", "Grad"}
	}
};
translation["Label5"] = {
	{
        {"ENG", "Address"},
		{"HRV", "Adresa"}
	}
};
translation["Label6"] = {
	{
        {"ENG", "Country"},
		{"HRV", "Država"}
	}
};
translation["ComboBox1"] = {
	{
		{"ENG", "Select Country"},
		{"HRV", "Odaberi državu"}
	}
};
translation["Label8"] = {
	{
		{"ENG", "Password"},
		{"HRV", "Lozinka"}
	}
};
translation["Label7"] = {
	{
		{"ENG", "Username"},
		{"HRV", "Korisnicko ime"}
	}
};
translation["Button1"] = {
	{
		{"ENG", "Register"},
		{"HRV", "Registriraj se"}
	}
};
translation["Button2"] = {
	{
		{"ENG", "Back"},
		{"HRV", "Povratak"}
	}
};

}
//---------------------------------------------------------------------------
// Funkcija za generiranje jedinstvene soli na temelju korisničkog imena
String generirajSol(String korisnickoIme) {
	std::unique_ptr<THashSHA2> sha2(new THashSHA2);
	return sha2->GetHashString(korisnickoIme, THashSHA2::SHA256);
}

// Funkcija za generiranje nasumičnog papra kao malog slova engleske abecede
String generirajPapar() {
	srand(static_cast<unsigned int>(time(nullptr)));
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int index = rand() % (sizeof(alphabet) - 1);
	return String(alphabet[index]);
}

void __fastcall TRegistracija::Button1Click(TObject *Sender)
{
	String korisnickoIme = editKorisnickoIme->Text;
	String ime = editIme->Text;
	String prezime = editPrezime->Text;
    String grad = editGrad->Text;
    String adresa = editAdresa->Text;
	String drzava = ComboBox1->Text;
	String lozinka = editLozinka->Text;
	TDateTime datumPrijave = Date();

	if (korisnickoIme.IsEmpty() || ime.IsEmpty() || prezime.IsEmpty() || grad.IsEmpty() || adresa.IsEmpty() || drzava.IsEmpty() || lozinka.IsEmpty()) {
		if (ComboBox2->Text=="HRV"){
				ShowMessage("Neuspješna registracija. Unesite sve tražene podatke!");
			}else {ShowMessage("Unsuccessful registration please enter all data");}
		return;
	}

	// Provjeri je li korisničko ime već zauzeto
	String checkSql = "SELECT COUNT(*) AS cnt FROM korisnici WHERE korisnicko_ime = :username";
	TFDQuery *checkQuery = new TFDQuery(NULL);
	checkQuery->Connection = FDConnection1;
	checkQuery->SQL->Text = checkSql;
	checkQuery->ParamByName("username")->AsString = korisnickoIme;
	checkQuery->Open();

	if (checkQuery->FieldByName("cnt")->AsInteger > 0) {
			if (ComboBox2->Text=="HRV"){ShowMessage("Korisničko ime već postoji odaberite drugo korisničko ime");
			}else {ShowMessage("Username already exists. Pleas pick another username");}
		delete checkQuery;
		return;
    }
	delete checkQuery;

	/*Funkcionalnost 25 lozinke */

    // Generiraj sol na temelju korisničkog imena
	String sol = generirajSol(korisnickoIme);

	// Generiraj nasumični papar
	String papar = generirajPapar();

	// Hashiraj lozinku s soli
	String lozinkaSaSolju = sol + lozinka;
	std::unique_ptr<THashSHA2> sha2(new THashSHA2);
	String hashLozinkeSaSolju = sha2->GetHashString(lozinkaSaSolju, THashSHA2::SHA256);

	// Dodaj papar hashu i ponovno ga hashiraj
	String konacniHashInput = hashLozinkeSaSolju + papar;
	String konacniHash = sha2->GetHashString(konacniHashInput, THashSHA2::SHA256);
	/*Funkcionalnost 25 lozinke */

	/*Funkcionalnost 23 kriptiranje imena i prezimena korisnik */
	// Kriptiraj osobne podatke
	String kljuc = "kljuc";
	String kriptiranoIme;
	String kriptiranoPrezime;
	Codec1->CryptoLibrary = CryptographicLibrary1;
	Codec1->Password = kljuc;
	Codec1->EncryptString(ime, kriptiranoIme, TEncoding::UTF8);
	Codec1->EncryptString(prezime, kriptiranoPrezime, TEncoding::UTF8);

	/* 7. FUNKCIONALNOST upisivanje korisnika u bazu */
    // Ubaci podatke u bazu
	String sql = "INSERT INTO korisnici (korisnicko_ime, ime, prezime, grad, adresa, drzava, lozinka, datum_prijave, tip_korisnika) "
				 "VALUES (:korisnickoIme, :ime, :prezime, :grad, :adresa, :drzava, :lozinka, :datumPrijave, :tipKorisnika)";

	TFDQuery *query = new TFDQuery(NULL);
	query->Connection = FDConnection1;
	query->SQL->Text = sql;

	// Postavljanje parametara SQL upita
	query->ParamByName("korisnickoIme")->AsString = korisnickoIme;
	query->ParamByName("ime")->AsString = kriptiranoIme;
	query->ParamByName("prezime")->AsString = kriptiranoPrezime;
	query->ParamByName("grad")->AsString = grad;
	query->ParamByName("adresa")->AsString = adresa;
	query->ParamByName("drzava")->AsString = drzava;
	query->ParamByName("datumPrijave")->AsString = datumPrijave;
	query->ParamByName("lozinka")->AsString = konacniHash;
	query->ParamByName("tipKorisnika")->AsString = "korisnik";

	query->ExecSQL();

	/* 7. FUNKCIONALNOST upisivanje korisnika u bazu */
	if (ComboBox2->Text=="HRV"){
				ShowMessage("Uspješna registracija");
			}else {ShowMessage("Successful registration");}

	// Oslobađanje memorije
	delete query;

	Hide();
	Prijava->ShowModal();
}
//---------------------------------------------------------------------------





void __fastcall TRegistracija::FormCreate(TObject *Sender)
{
	editLozinka->PasswordChar = '*';

	/* 18. funkcionalnost */

	_di_CountryInfoServiceSoapType CountryInfoService = GetCountryInfoServiceSoapType();

	NS_CountryInfoService::ArrayOftCountryCodeAndName CountryNames;
	CountryNames = CountryInfoService->ListOfCountryNamesByName();

	ComboBox1->Clear();

	for (int i = 0; i < CountryNames.Length; ++i)
	{
		ComboBox1->Items->Add(CountryNames[i]->sName);
	}
	/* 18. funkcionalnost */
}
//---------------------------------------------------------------------------

void __fastcall TRegistracija::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------



void __fastcall TRegistracija::Button2Click(TObject *Sender)
{
	Hide();
	Prijava->Show();
}
//---------------------------------------------------------------------------



void __fastcall TRegistracija::ComboBox1Change(TObject *Sender)
{
	if (ComboBox2->Text=="HRV"){
				ShowMessage("Odaberana država: " + ComboBox1->Text);
			}else {ShowMessage("Picked country: " + ComboBox1->Text);}

}
//---------------------------------------------------------------------------

bool __fastcall TRegistracija::Codec1Progress(TObject *Sender, __int64 CountBytesProcessed)

{
	return true;
}

void translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation){
	for(int i = 0; i < Form->ComponentCount; i++) // iterate though all components on the form
		for(auto it_ComponentName = translation.begin(); it_ComponentName != translation.end(); it_ComponentName++)
			if(Form->Components[i]->Name == it_ComponentName->first) // find component by name
				for(auto it_Language = it_ComponentName->second.begin(); it_Language != it_ComponentName->second.end(); it_Language++)
					if(it_Language->first == Language) // find translation for the target language
						if(IsPublishedProp(Form->Components[i], "Caption"))
							SetPropValue(Form->Components[i], "Caption", it_Language->second);
}

void __fastcall TRegistracija::ComboBox2Change(TObject *Sender)
{
	String selectedLanguage=ComboBox2->Text;
	translateForm(this, selectedLanguage, translation);
}
//---------------------------------------------------------------------------

