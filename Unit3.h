//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MSAcc.hpp>
#include <FireDAC.Phys.MSAccDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportBaseDialog.hpp"
#include "frxExportPDF.hpp"
#include "frxExportRTF.hpp"
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include "frCoreClasses.hpp"
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include <System.SysUtils.hpp>
#include <map>
//---------------------------------------------------------------------------
class TPocetna : public TForm
{
__published:	// IDE-managed Components
	TButton *Pregled;
	TButton *Button2;
	TButton *btnOdjava;
	TDataSource *DIgre;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDBGrid *DBGrid1;
	TImage *Image1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TMemo *Memo1;
	TADOQuery *ADOQuery2;
	TButton *btnUcitajTablicu;
	TComboBox *ComboBox2;
	TButton *btnFiltar;
	TComboBox *ComboBox3;
	TButton *btnResetFilter;
	TButton *btnReport;
	TfrxReport *frxReport1;
	TfrxDBDataset *frxDBIgre;
	TfrxDBDataset *frxDBRecenzije;
	TfrxPDFExport *frxPDFExport1;
	TfrxRTFExport *frxRTFExport1;
	TADOQuery *QueryIgreReport;
	TADOQuery *QueryRecenzijeReport;
	TButton *btnPreuzmi;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TCodec *Codec1;
	TCryptographicLibrary *CryptographicLibrary1;
	TADOQuery *ADOQuery3;
	TComboBox *ComboBox4;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TButton *Button1;
	void __fastcall btnOdjavaClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall btnUcitajTablicuClick(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnFiltarClick(TObject *Sender);
	void __fastcall btnResetFilterClick(TObject *Sender);
	void __fastcall btnReportClick(TObject *Sender);
	void __fastcall btnPreuzmiClick(TObject *Sender);
	void __fastcall PregledClick(TObject *Sender);
	void __fastcall ComboBox4Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
 void __fastcall translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation);
String odabraniJezik;
public:		// User declarations
	__fastcall TPocetna(TComponent* Owner);
	std::map<String, std::map<String, String>> translation;
	void PrikaziSlikuIzBaze();
	void __fastcall SetUsername(String korisnickoIme);
	void __fastcall SetJezik(String jezik);
	void __fastcall UcitajTablicu();
};
//---------------------------------------------------------------------------
extern PACKAGE TPocetna *Pocetna;
//---------------------------------------------------------------------------
#endif
