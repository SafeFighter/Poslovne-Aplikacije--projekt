//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <map>
//---------------------------------------------------------------------------
class TDodajRecenziju : public TForm
{
__published:	// IDE-managed Components
	TButton *btnSpremi;
	TMemo *Memo1;
	TButton *btnOdustani;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TComboBox *ComboBox1;
	TButton *btnOsvjezi;
	TComboBox *ComboBox2;
	TButton *Button1;
	TButton *Button2;
	void __fastcall btnOdustaniClick(TObject *Sender);
	void __fastcall btnSpremiClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall btnOsvjeziClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDodajRecenziju(TComponent* Owner);
	std::map<String, std::map<String, String>> translation;
	void __fastcall DodajPodatke();
};
//---------------------------------------------------------------------------
extern PACKAGE TDodajRecenziju *DodajRecenziju;
//---------------------------------------------------------------------------
#endif
