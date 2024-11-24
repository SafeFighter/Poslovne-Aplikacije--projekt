//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
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
#include <map>
//---------------------------------------------------------------------------
extern int idPrijavljenogKorisnika;
class TAdminPrijava : public TForm
{
__published:	// IDE-managed Components
	TLabel *userName;
	TLabel *lozinka;
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *btnPrijava;
	TFDConnection *FDConnection1;
	TButton *Button1;
	TComboBox *ComboBox1;
	void __fastcall btnPrijavaClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;
	__fastcall TAdminPrijava(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAdminPrijava *AdminPrijava;
//---------------------------------------------------------------------------
#endif
