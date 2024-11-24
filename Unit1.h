//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MSAcc.hpp>
#include <FireDAC.Phys.MSAccDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <map>
//---------------------------------------------------------------------------
class TPrijava : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *btnPrijava;
	TButton *btnRegistracija;
	TButton *Button1;
	TFDConnection *FDConnection1;
	TLabel *Label4;
	TComboBox *ComboBox1;

	void __fastcall btnPrijavaClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

	void __fastcall btnRegistracijaClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;  //3. funkcionalnost deklaracija fukcije za prevođenje
	__fastcall TPrijava(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrijava *Prijava;
//---------------------------------------------------------------------------
#endif
