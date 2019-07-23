//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <System.Net.HttpClient.hpp>
#include <System.Net.HttpClientComponent.hpp>
#include <System.Net.URLClient.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Objects.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TBitmapAnimation *BitmapAnimation1;
	TImage *Image1;
	TImage *Image2;
	TImage *PosetiIm;
	TImage *SkompomIm;
	TImage *PomowIm;
	TImage *VixodIm;
	TImage *ViborIm;
	TImage *MenuIm;
	TImage *TextIm;
	TImage *ZanovoIm;
	TImage *Unitu;
	TImage *R1K1;
	TImage *R1K3;
	TImage *R1K2;
	TImage *R1K4;
	TImage *R1K5;
	TImage *Start;
	TImage *vzruv;
	TIdTCPServer *Server1;
	TIdTCPClient *Client1;
	TButton *Button1;
	TEdit *Edit1;
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall PosetiImMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall SkompomImMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall MenuImMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall VixodImMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall PomowImMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall ViborImMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall ZanovoImMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall R1K1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall R1K3MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall R1K2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall R1K4MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall R1K5MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall StartMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall Image2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall Server1Execute(TIdContext *AContext);
	void __fastcall Button1Enter(TObject *Sender);
	void __fastcall Client1Connected(TObject *Sender);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, float X, float Y);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
