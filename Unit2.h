//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Data.Win.ADODB.hpp>
#include <FireDAC.Phys.MSAcc.hpp>
#include <FireDAC.Phys.MSAccDef.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Hash.hpp"
#include "uTPLb_Codec.hpp"
#include <System.SysUtils.hpp>
#include <map>
//---------------------------------------------------------------------------
class TRegistracija : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *editKorisnickoIme;
	TEdit *editIme;
	TEdit *editPrezime;
	TEdit *editGrad;
	TEdit *editAdresa;
	TButton *Button1;
	TFDConnection *FDConnection1;
	TEdit *editLozinka;
	TLabel *Label8;
	TButton *Button2;
	TComboBox *ComboBox1;
	TCodec *Codec1;
	TCryptographicLibrary *CryptographicLibrary1;
	TComboBox *ComboBox2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	bool __fastcall Codec1Progress(TObject *Sender, __int64 CountBytesProcessed);
	void __fastcall ComboBox2Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;
	__fastcall TRegistracija(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRegistracija *Registracija;
//---------------------------------------------------------------------------
#endif
