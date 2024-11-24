//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
#include "Unit6.h"
#include "GOTY.h"
#include <jpeg.hpp>
#include <System.JSON.hpp>
#include <memory>
#include <pngimage.hpp>
#include <System.SysUtils.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPocetnaAdmin *PocetnaAdmin;
//---------------------------------------------------------------------------
__fastcall TPocetnaAdmin::TPocetnaAdmin(TComponent* Owner)
	: TForm(Owner)
{
	ADOQuery1->Open();
	OsvjeziTablicu();
	OsvjeziPodatke();
	OsvjeziPodatkeID();
}
//---------------------------------------------------------------------------
void __fastcall TPocetnaAdmin::btnUcitajSlikuClick(TObject *Sender)
{
	 /* 9. funkcionalnost ucitaj sliku */
	 if(OpenDialog1->Execute()){
			ADOQuery1->Edit();
		   static_cast<TBlobField*>(ADOQuery1->FieldByName("Slika"))->LoadFromFile(OpenDialog1->FileName);
		   ADOQuery1->Post();
		   PrikaziSlikuIzBaze();
	   }

}
//---------------------------------------------------------------------------
void __fastcall TPocetnaAdmin::btnOdjavaClick(TObject *Sender)
{
    	Hide();
		Prijava->Show();

}
//---------------------------------------------------------------------------
	void TPocetnaAdmin::PrikaziSlikuIzBaze()
{
	TMemoryStream *blobStream = new TMemoryStream;
	try
    {
        // Provjerite postoji li sadržaj u polju "Slika"
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


//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::btnDodajClick(TObject *Sender)
{
    /*7. funkcionalnost dodavanje podataka u tablicu igre */

	if(!ADOQuery1->Active)
	{
		ADOQuery1->Open(); // Otvori upit ako nije već otvoren
	}

		int cijena=StrToInt(Edit2->Text);
		int ocjena=StrToInt(Edit3->Text);
		TDateTime datum = DateTimePicker->Date;

		ADOQuery1->Insert();

		// Postavi vrijednosti polja iz komponenata za unos
		ADOQuery1->FieldByName("Naziv")->AsString = Edit1->Text;
		ADOQuery1->FieldByName("Cijena")->AsInteger = cijena;
		ADOQuery1->FieldByName("Ocjena")->AsInteger = ocjena;
		ADOQuery1->FieldByName("Datum_izlaska")->AsDateTime = datum;


		ADOQuery1->Post(); // Spremi zapis u bazu

		ShowMessage("Podaci su uspješno spremljeni.");
		OsvjeziPodatke();
		OsvjeziPodatkeID();
        OsvjeziTablicu();

		Edit1->Text = "";
		Edit2->Text = "";
		Edit3->Text = "";
		DateTimePicker->Date = Date();

}
//---------------------------------------------------------------------------





void __fastcall TPocetnaAdmin::ComboBox1Change(TObject *Sender)
{
		if (ComboBox1->ItemIndex != -1) {
		// Dohvati odabrano ime
		String odabranaIgra = ComboBox1->Items->Strings[ComboBox1->ItemIndex];

		// Postavljanje SQL upita u ADOQuery za dohva?anje dodatnih podataka o korisniku
		ADOQuery1->SQL->Text = "SELECT * FROM igre WHERE Naziv = :Naziv";
		ADOQuery1->Parameters->ParamByName("Naziv")->Value = odabranaIgra;
		}

		ADOQuery1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::btnObrisiClick(TObject *Sender)
{
    /* 7. funkcionalnost brisanje podataka iz tablice igre*/

	String selectedName = ComboBox1->Text; // Dohvat odabranog imena iz ComboBox-a

    if (!selectedName.IsEmpty())
	{
        TADOQuery *Query = new TADOQuery(NULL);
		Query->Connection = ADOConnection1;

		// Primjer SQL upita za brisanje na temelju imena:
		Query->SQL->Text = "DELETE FROM igre WHERE Naziv = :ime";
		Query->Parameters->ParamByName("ime")->Value = selectedName;
		Query->ExecSQL();
		delete Query;

		// Osvježi Combo Box nakon brisanja podatka
		ComboBox1->Clear();
		OsvjeziPodatke();
		ShowMessage("Podaci su uspješno obrisani.");

	}
}

void __fastcall TPocetnaAdmin::OsvjeziPodatke()
{
	ComboBox1->Clear();
	ADOQuery2->Open();
	while (!ADOQuery2->Eof)
	{
		String naziv = ADOQuery2->FieldByName("Naziv")->AsString;
		ComboBox1->Items->Add(naziv);
		ADOQuery2->Next();
	}
	ADOQuery2->Close();
}

void __fastcall TPocetnaAdmin::ComboBox2Change(TObject *Sender)
{
	ShowMessage("Za izmjenu unesi sva polja");
	if (ComboBox1->ItemIndex != -1)
    {
		// Dohvati odabrani ID kao cjelobrojnu vrijednost
        int odabranID = StrToInt(ComboBox1->Items->Strings[ComboBox1->ItemIndex]);

		// Postavljanje SQL upita u ADOQuery za dohvaćanje dodatnih podataka o igri
		ADOQuery1->Close(); // Zatvori ADOQuery prije promjene upita
        ADOQuery1->SQL->Text = "SELECT * FROM igre WHERE ID = :ID";
		ADOQuery1->Parameters->ParamByName("ID")->Value = odabranID;

		// Otvori ADOQuery kako bi se izvršio novi upit
		ADOQuery1->Open();
	}
}
//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::OsvjeziPodatkeID()
{
	ComboBox2->Clear();
	ADOQuery2->Open();
	while (!ADOQuery2->Eof)
	{
		int ID = ADOQuery2->FieldByName("ID")->AsInteger;
		ComboBox2->Items->Add(IntToStr(ID));
		ADOQuery2->Next();
	}
	ADOQuery2->Close();
}
void __fastcall TPocetnaAdmin::btnIzmijeniClick(TObject *Sender)
{
		/* 7. funkcionalnost izmjena podataka iz tablice igre*/

	if (ComboBox2->ItemIndex != -1)
	{
		int odabranID = StrToInt(ComboBox2->Items->Strings[ComboBox2->ItemIndex]);

		// Dohvati unesene vrijednosti iz Edit polja
		String noviNaziv = Edit5->Text;
		double novaCijena = StrToFloat(Edit4->Text);
		int novaOcjena = StrToInt(Edit6->Text);


		// Postavljanje SQL upita za ažuriranje podataka u bazi
		ADOQuery1->SQL->Text = "UPDATE igre SET Naziv = :Naziv, Cijena = :Cijena, Ocjena = :Ocjena WHERE ID = :ID";
		ADOQuery1->Parameters->ParamByName("Naziv")->Value = noviNaziv;
		ADOQuery1->Parameters->ParamByName("Cijena")->Value = novaCijena;
		ADOQuery1->Parameters->ParamByName("Ocjena")->Value = novaOcjena;
		ADOQuery1->Parameters->ParamByName("ID")->Value = odabranID;



		// Izvrši UPDATE SQL upit
		ADOQuery1->ExecSQL();

		Edit4->Text = "";
		Edit5->Text = "";
		Edit6->Text = "";


		// Osvježi podatke u ComboBoxu kako bi se prikazali ažurirani podaci
		OsvjeziPodatkeID();
		OsvjeziPodatke();
	}

}

void __fastcall TPocetnaAdmin::OsvjeziTablicu()
{

	ADOQuery1->Close();

	// Postavite SQL upit za dohvaćanje podataka iz baze (prilagodite upit vašoj bazi)
    ADOQuery1->SQL->Text = "SELECT * FROM igre";

    // Otvorite ADOQuery kako bi dohvatili nove podatke iz baze
	ADOQuery1->Open();
}

void __fastcall TPocetnaAdmin::btnOsvjeziClick(TObject *Sender)
{
	OsvjeziTablicu();
}
//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::btnRecenzijaClick(TObject *Sender)
{
	Hide();
	DodajRecenziju->Show();
}
//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::btnDodaj2Click(TObject *Sender)
{
	/* 8. funkcionalnost lookup */
	if(!ADOQuery1->Active)
	{
		ADOQuery1->Open(); // Otvori upit ako nije već otvoren
	}

	String zanr = DBLookupComboBox1->KeyValue;

	ADOQuery1->FieldByName("Zanr")->AsString = zanr;

	ADOQuery1->Post();

	ShowMessage("Žanr je uspješno spremljen.");
	OsvjeziPodatke();
	OsvjeziPodatkeID();
	OsvjeziTablicu();
}
//---------------------------------------------------------------------------//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::Button1Click(TObject *Sender)
{
	/*5. funkcionalnost čitanje XML datoteke */

    // Deklaracija objekta za XML podatke
	_di_IXMLGamesOfTheYearType GameOfTheYear;

	// Poziv funkcije za dobivanje XML podataka
	GameOfTheYear = GetGamesOfTheYear(XMLDocument1);

    // Obriši postojeće stavke u ListView-u
    ListView1->Clear();

    ListView1->Columns->Clear();
    ListView1->Columns->Add()->Caption = "Naslov";
    ListView1->Columns->Add()->Caption = "Razvojni tim";
    ListView1->Columns->Add()->Caption = "Godina";

    // Iteriraj kroz svaku igru i dodajte je u ListView
    for(int i = 0; i < GameOfTheYear->Count; i++)
	{
		TListItem* stavka = ListView1->Items->Add();
		stavka->Caption = GameOfTheYear->Game[i]->Get_Title(); // Pristupi naslovu
		stavka->SubItems->Add(GameOfTheYear->Game[i]->Get_Developer()); // Pristupi razvojnom timu
        stavka->SubItems->Add(GameOfTheYear->Game[i]->Get_Year()); // Pristupi godini
    }
}

//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::Button2Click(TObject *Sender)
{

	/*5. funkcionalnost dodavanje podataka u XML datoteku */

	// Učitaj XML dokument
	_di_IXMLGamesOfTheYearType GameOfTheYear = GetGamesOfTheYear(XMLDocument1);

    // Dodaj novi čvor u XML dokument
    _di_IXMLGameType Game = GameOfTheYear->Add();

    // Učitaj nove podatke iz Text Edita
    UnicodeString naslov = Edit7->Text.Trim();
    UnicodeString razvojniTim = Edit8->Text.Trim();
    UnicodeString godina = Edit9->Text.Trim();

    // Provjeri jesu li svi podaci uneseni
    if (naslov.IsEmpty() || razvojniTim.IsEmpty() || godina.IsEmpty())
    {
        ShowMessage("Molimo unesite sve podatke.");
        return;
    }

    // Pretvori UnicodeString godina u int
    int year = StrToInt(godina);

    // Postavi vrijednosti unutar novog čvora
    Game->Title = naslov;
    Game->Developer = razvojniTim;
	Game->Year = year;

    // Spremi promjene u XML datoteku
    XMLDocument1->SaveToFile(XMLDocument1->FileName);

	ShowMessage("Podaci su uspješno dodani u XML datoteku.");

	Edit7->Text = "";
	Edit8->Text = "";
	Edit9->Text = "";
}


//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::Button3Click(TObject *Sender)
{
	/*5. funkcionalnost brisanje iz XML datoteke */

// Provjeri je li stavka označena
	int selectedIndex = ListView1->ItemIndex;
	if (selectedIndex == -1)
	{
		ShowMessage("Molimo označite igru koju želite obrisati.");
		return;
	}

	// Učitaj XML dokument
	_di_IXMLGamesOfTheYearType GameOfTheYear = GetGamesOfTheYear(XMLDocument1);

    // Provjeri je li indeks u valjanom rasponu
    if (selectedIndex < 0 || selectedIndex >= GameOfTheYear->Count)
    {
        ShowMessage("Neispravan indeks.");
        return;
    }

    // Obriši označenu igru iz XML dokumenta
    GameOfTheYear->Delete(selectedIndex);

    // Spremi promjene u XML datoteku
    XMLDocument1->SaveToFile(XMLDocument1->FileName);

    // Ažuriraj ListView
    ListView1->Items->Delete(selectedIndex);

	ShowMessage("Igra je uspješno obrisana.");
}
//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::Button4Click(TObject *Sender)
{

	/*5. funkcionalnost čitanje JSON datoteke */

	// Učitaj JSON datoteku
	std::unique_ptr<TStringStream> jsonStream(new TStringStream);
	jsonStream->LoadFromFile("bestSellingGames.json");

	// Stvori JSON objekt koji predstavlja cijelu JSON datoteku
	TJSONObject* jsonFile = (TJSONObject*)TJSONObject::ParseJSONValue(jsonStream->DataString);

    // Stvori JSON objekt koji predstavlja polje unutar objekta "best_selling_games"
	TJSONArray* gamesArray = (TJSONArray*)TJSONObject::ParseJSONValue(jsonFile->GetValue("best_selling_games")->ToString());

    // Čitaj i prikaži svaku igru
	ListView2->Items->Clear();
	for (int i = 0; i < gamesArray->Count; i++) {
        // Čitaj informacije o igri
		String naslov = gamesArray->Items[i]->GetValue<UnicodeString>("title");
		String izdavac = gamesArray->Items[i]->GetValue<UnicodeString>("publisher");
        int prodano = gamesArray->Items[i]->GetValue<int>("units_sold");
		int godinaIzlaska = gamesArray->Items[i]->GetValue<int>("release_year");

        // Prikaži informacije o igri unutar komponente ListView
        ListView2->Items->Add();
		ListView2->Items->Item[i]->Caption = naslov;
		ListView2->Items->Item[i]->SubItems->Add(izdavac);
		ListView2->Items->Item[i]->SubItems->Add(prodano);
        ListView2->Items->Item[i]->SubItems->Add(godinaIzlaska);
    }
}

//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::Button5Click(TObject *Sender)
{
	/*5. funkcionalnost brisanje podataka JSON datoteke */
	ListView2->DeleteSelected();
}
//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::Button6Click(TObject *Sender)
{
	/*5. funkcionalnost dodavanje podataka u JSON datoteku */

	ListView2->Items->Add();
	int lastIndex = ListView2->Items->Count-1;
	ListView2->Items->Item[lastIndex]->Caption = Edit10->Text;
	ListView2->Items->Item[lastIndex]->SubItems->Add(Edit11->Text);
	ListView2->Items->Item[lastIndex]->SubItems->Add(Edit12->Text);
	ListView2->Items->Item[lastIndex]->SubItems->Add(Edit13->Text);

	Edit10->Text = "";
	Edit11->Text = "";
	Edit12->Text = "";
	Edit13->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::Button7Click(TObject *Sender)
{
		  /*5. funkcionalnost spremanje podataka u JSON datoteku */

	String jsonDoc = "{";
	jsonDoc += "\"best_selling_games\":";
	jsonDoc += "[";
	// Dodaj postojeće igre...
	for (int i = 0; i < ListView2->Items->Count; i++) {
		jsonDoc +=
			"{"
				"\"title\":\"" + ListView2->Items->Item[i]->Caption + "\","
				"\"publisher\":\"" + ListView2->Items->Item[i]->SubItems->Strings[0] + "\","
				"\"units_sold\":" + ListView2->Items->Item[i]->SubItems->Strings[1] + ","
				"\"release_year\":" + ListView2->Items->Item[i]->SubItems->Strings[2] + ""
			"}";
		jsonDoc += (i + 1 != ListView2->Items->Count) ? "," : "";
	}
	jsonDoc += "]";
	jsonDoc += "}";


	// Formatiraj JSON dokument (prijelazi u novi red, uvlačenja...)
	jsonDoc = ((TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc))->Format(2);

	std::unique_ptr<TStringStream> ss(new TStringStream);
	ss->WriteString(jsonDoc);
	ss->SaveToFile("bestSellingGames.json");
	 ShowMessage("Podaci su spremljeni u dokument!");
}
//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::Button8Click(TObject *Sender)
{
    /*5. funkcionalnost izmjena podataka u JSON datoteci */

	if(ListView2->ItemIndex == -1)
		return;

	ListView2->Items->Item[ListView2->ItemIndex]->Caption = Edit10->Text;
	ListView2->Items->Item[ListView2->ItemIndex]->SubItems->Strings[0] = Edit11->Text;
	ListView2->Items->Item[ListView2->ItemIndex]->SubItems->Strings[1] = Edit12->Text;
	ListView2->Items->Item[ListView2->ItemIndex]->SubItems->Strings[2] = Edit13->Text;

    Edit10->Text = "";
	Edit11->Text = "";
	Edit12->Text = "";
	Edit13->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TPocetnaAdmin::Button9Click(TObject *Sender)
{
		/*5. funkciobalnost izmjena podataka XML datoteke */

		// Provjeri je li stavka označena
		int selectedIndex = ListView1->ItemIndex;
		if (selectedIndex == -1)
		{
			ShowMessage("Molimo označite igru koju želite izmijeniti.");
			return;
		}

		// Učitaj XML dokument
		_di_IXMLGamesOfTheYearType GameOfTheYear = GetGamesOfTheYear(XMLDocument1);

		// Dohvati odabrani čvor (igru)
		_di_IXMLGameType selectedGame = GameOfTheYear->Game[selectedIndex];

		// Učitaj nove podatke iz Text Edita
		UnicodeString naslov = Edit7->Text.Trim();
		UnicodeString razvojniTim = Edit8->Text.Trim();
		UnicodeString godina = Edit9->Text.Trim();

		// Provjeri jesu li svi podaci uneseni
		if (naslov.IsEmpty() || razvojniTim.IsEmpty() || godina.IsEmpty()) {
			ShowMessage("Molimo unesite sve podatke.");
			return;
		}

		// Pretvori UnicodeString godina u int
		int year = StrToInt(godina);

		// Postavi nove vrijednosti unutar odabranog čvora
		selectedGame->Title = naslov;
		selectedGame->Developer = razvojniTim;
		selectedGame->Year = year;

		// Spremi promjene u XML datoteku
		XMLDocument1->SaveToFile(XMLDocument1->FileName);

		ShowMessage("Podaci su uspješno ažurirani u XML datoteci.");

		Edit7->Text = "";
		Edit8->Text = "";
		Edit9->Text = "";
}
//---------------------------------------------------------------------------





