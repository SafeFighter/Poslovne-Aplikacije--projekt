//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.Dialogs.hpp>
#include <IdIntercept.hpp>
#include <IdInterceptThrottler.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <map>
//---------------------------------------------------------------------------
class TPreuzmi : public TForm
{
__published:	// IDE-managed Components
	TProgressBar *ProgressBar1;
	TButton *btnPreuzmi;
	TIdHTTP *Preuzmi;
	TSaveDialog *SaveDialog1;
	TButton *btnPovratak;
	TIdInterceptThrottler *IdInterceptThrottler1;
	TIdSSLIOHandlerSocketOpenSSL *OpenSSL1;
	TLabel *Label2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TComboBox *ComboBox1;
	void __fastcall btnPreuzmiClick(TObject *Sender);
	void __fastcall btnPovratakClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall PreuzmiWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall PreuzmiWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall ComboBox1Change(TObject *Sender);


private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;
	__fastcall TPreuzmi(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPreuzmi *Preuzmi;
//---------------------------------------------------------------------------
#endif
