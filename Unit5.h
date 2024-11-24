//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
//---------------------------------------------------------------------------
class TPocetnaAdmin : public TForm
{
__published:	// IDE-managed Components
	TButton *Pregled;
	TButton *btnProfil;
	TButton *btnOdjava;
	TDBGrid *DBGrid1;
	TButton *btnUcitajSliku;
	TImage *Image1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label3;
	TDateTimePicker *DateTimePicker;
	TLabel *Label4;
	TButton *btnDodaj;
	TLabel *Label2;
	TEdit *Edit3;
	TComboBox *ComboBox1;
	TButton *btnObrisi;
	TEdit *Edit4;
	TEdit *Edit5;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *Edit6;
	TLabel *Label9;
	TComboBox *ComboBox2;
	TButton *btnIzmijeni;
	TButton *btnOsvjezi;
	TButton *btnRecenzija;
	TLabel *Label6;
	TButton *btnDodaj2;
	TButton *Button1;
	TListView *ListView1;
	TXMLDocument *XMLDocument1;
	TButton *Button2;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TEdit *Edit13;
	TListView *ListView2;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TDataSource *DIgre;
	TADOConnection *ADOConnection1;
	TOpenDialog *OpenDialog1;
	TADOQuery *ADOQuery1;
	TADOQuery *ADOQuery2;
	TADOQuery *ADOQuery3;
	TDataSource *DataSource1;
	TDBLookupComboBox *DBLookupComboBox1;
	void __fastcall btnUcitajSlikuClick(TObject *Sender);
	void __fastcall btnOdjavaClick(TObject *Sender);
	void __fastcall btnDodajClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall btnObrisiClick(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall btnIzmijeniClick(TObject *Sender);
	void __fastcall btnOsvjeziClick(TObject *Sender);
	void __fastcall btnRecenzijaClick(TObject *Sender);
	void __fastcall btnDodaj2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPocetnaAdmin(TComponent* Owner);
	void PrikaziSlikuIzBaze();
	void __fastcall OsvjeziPodatke();
	void __fastcall OsvjeziPodatkeID();
	void __fastcall OsvjeziTablicu();
};
//---------------------------------------------------------------------------
extern PACKAGE TPocetnaAdmin *PocetnaAdmin;
//---------------------------------------------------------------------------
#endif
