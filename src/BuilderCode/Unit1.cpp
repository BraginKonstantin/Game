//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1* Form1;  int pole[3][20][20], korablN[2], korabli[3][50][20], XP[3][50], karta[3][20][20],
cenu[3][20], nMax = 10, mMax = 10, sdvigX, sdvigY, wirina, visota, rassa[3],
xodit, rasstavlyaet = 1, zoloto[3], k[3];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	int n, m, Xkor, Ykor;
	for (n = 0; n < nMax; n++)
	{
		if (X - sdvigX < wirina / nMax) {
			Xkor = X; break;
		}

	}
	for (m = 0; m < mMax; m++)
	{
		if (Y - sdvigY < visota / mMax) {
			Ykor = Y; break;
		}

	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	if (rasstavlyaet == 1) {
		xodit = 1;
		int n, m, Xkor, Ykor;
		korablN[xodit] = 1;

		//-------------------
		wirina = Image1->Bitmap->Width;
		visota = Image1->Bitmap->Height;
		//-------------------

		for (n = 1; n <= nMax; n++)
		{
			if (X < wirina / nMax * n) {
				Xkor = n; break;
			}

		}

		for (m = 1; m <= mMax; m++)
		{
			if (Y < visota / mMax * m) {
				Ykor = m; break;
			}
		}

		//-------------------------
		/* TRect A(0,0,wirina/nMax,visota/mMax);
		TRect B(Xkor*wirina/nMax,Ykor*visota/mMax,Xkor*wirina/nMax+wirina/nMax,Ykor*visota/mMax+visota/mMax);
		Image1->Bitmap->Canvas->BeginScene();
		Image1->Bitmap->Canvas->DrawBitmap(Unitu->Bitmap,A,B,1,false);
		Image1->Bitmap->Canvas->EndScene();*/
		//-------------------------
		//-----Хватает ли золота на постройку
		if (zoloto[xodit] - cenu[rassa[1]][k[xodit]] >= 0) {
			//-------------Выбор типа корабля

			switch (k[xodit]) {
			case 1: {
				if (pole[xodit][Xkor][Ykor] == 0 && pole[xodit][Xkor + 1][Ykor] == 0 && pole[xodit][Xkor - 1][Ykor] == 0 &&
					pole[xodit][Xkor][Ykor - 1] == 0 && pole[xodit][Xkor][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 1] == 0 &&
					pole[xodit][Xkor + 1][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor + 1] == 0 && pole[xodit][Xkor + 1][Ykor - 1] == 0)
				{
					pole[xodit][Xkor][Ykor] = korablN[xodit];

					korabli[xodit][korablN[xodit]][1] = 1; //  тип
					korabli[xodit][korablN[xodit]][2] = 1;   //   ХП


					korablN[xodit] = korablN[xodit] + 1;
					zoloto[xodit] = zoloto[xodit] - cenu[rassa[1]][k[xodit]];
					//------------- Графика
					TRect A(0, 0, wirina / nMax, visota / mMax);
					TRect B((Xkor - 1) * wirina / nMax, (Ykor - 1) * visota / mMax, (Xkor - 1) * wirina / nMax + wirina / nMax, (Ykor - 1) * visota / mMax + visota / mMax);
					Image1->Bitmap->Canvas->BeginScene();
					Image1->Bitmap->Canvas->DrawBitmap(R1K1->Bitmap, A, B, 1, false);
					Image1->Bitmap->Canvas->EndScene();
					//----------------
				}

				break;
			}
			//------------------------
			case 2: {
				if (Xkor < nMax && pole[xodit][Xkor][Ykor] == 0 && pole[xodit][Xkor + 1][Ykor] == 0 && pole[xodit][Xkor - 1][Ykor] == 0 &&
					pole[xodit][Xkor][Ykor - 1] == 0 && pole[xodit][Xkor][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 1] == 0 &&
					pole[xodit][Xkor + 1][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor + 1] == 0 && pole[xodit][Xkor + 1][Ykor - 1] == 0
					&& pole[xodit][Xkor + 2][Ykor] == 0 && pole[xodit][Xkor + 2][Ykor + 1] == 0 && pole[xodit][Xkor + 2][Ykor - 1] == 0)
				{
					pole[xodit][Xkor][Ykor] = korablN[xodit]; pole[xodit][Xkor + 1][Ykor] = korablN[xodit];

					korabli[xodit][korablN[xodit]][1] = 2; //  тип
					korabli[xodit][korablN[xodit]][2] = 2;   //   ХП
					korablN[xodit] = korablN[xodit] + 1;

					zoloto[xodit] = zoloto[xodit] - cenu[rassa[xodit]][k[xodit]];
					//------------- Графика
					TRect A(0, 0, wirina / nMax * 2, visota / mMax);
					TRect B((Xkor - 1) * wirina / nMax, (Ykor - 1) * visota / mMax, (Xkor - 1) * wirina / nMax + wirina / nMax * 2, (Ykor - 1) * visota / mMax + visota / mMax);
					Image1->Bitmap->Canvas->BeginScene();
					Image1->Bitmap->Canvas->DrawBitmap(R1K2->Bitmap, A, B, 1, false);
					Image1->Bitmap->Canvas->EndScene();
					//----------------
				}
				break;
			}
			//-----------------------
			case 3: {
				if (Xkor < nMax - 1 && pole[xodit][Xkor][Ykor] == 0 && pole[xodit][Xkor + 1][Ykor] == 0 && pole[xodit][Xkor - 1][Ykor] == 0 &&
					pole[xodit][Xkor][Ykor - 1] == 0 && pole[xodit][Xkor][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 1] == 0 &&
					pole[xodit][Xkor + 1][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor + 1] == 0 && pole[xodit][Xkor + 1][Ykor - 1] == 0
					&& pole[xodit][Xkor + 2][Ykor] == 0 && pole[xodit][Xkor + 2][Ykor + 1] == 0 && pole[xodit][Xkor + 2][Ykor - 1] == 0
					&& pole[xodit][Xkor + 3][Ykor] == 0 && pole[xodit][Xkor + 3][Ykor - 1] == 0 && pole[xodit][Xkor + 3][Ykor + 1] == 0)
				{
					pole[xodit][Xkor][Ykor] = korablN[xodit]; pole[xodit][Xkor + 1][Ykor] = korablN[xodit];
					pole[xodit][Xkor + 2][Ykor] = korablN[xodit];

					korabli[xodit][korablN[xodit]][1] = 2; //  тип
					korabli[xodit][korablN[xodit]][2] = 2;   //   ХП



					korablN[xodit] = korablN[xodit] + 1;


					zoloto[xodit] = zoloto[xodit] - cenu[rassa[xodit]][k[xodit]];
					//------------- Графика
					TRect A(0, 0, wirina / nMax * 3, visota / mMax);
					TRect B((Xkor - 1) * wirina / nMax, (Ykor - 1) * visota / mMax, (Xkor - 1) * wirina / nMax + wirina / nMax * 3, (Ykor - 1) * visota / mMax + visota / mMax);
					Image1->Bitmap->Canvas->BeginScene();
					Image1->Bitmap->Canvas->DrawBitmap(R1K4->Bitmap, A, B, 1, false);
					Image1->Bitmap->Canvas->EndScene();
					//----------------
				}

				break;
			}
			case 4: {
				if (Xkor < nMax - 2 && pole[xodit][Xkor][Ykor] == 0 && pole[xodit][Xkor + 1][Ykor] == 0 && pole[xodit][Xkor - 1][Ykor] == 0 &&
					pole[xodit][Xkor][Ykor - 1] == 0 && pole[xodit][Xkor][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 1] == 0 &&
					pole[xodit][Xkor + 1][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor + 1] == 0 && pole[xodit][Xkor + 1][Ykor - 1] == 0
					&& pole[xodit][Xkor + 2][Ykor] == 0 && pole[xodit][Xkor + 2][Ykor + 1] == 0 && pole[xodit][Xkor + 2][Ykor - 1] == 0
					&& pole[xodit][Xkor + 3][Ykor] == 0 && pole[xodit][Xkor + 3][Ykor - 1] == 0 && pole[xodit][Xkor + 3][Ykor + 1] == 0
					&& pole[xodit][Xkor + 4][Ykor] == 0 && pole[xodit][Xkor + 4][Ykor - 1] == 0 && pole[xodit][Xkor + 4][Ykor + 1] == 0)
				{
					pole[xodit][Xkor][Ykor] = korablN[xodit]; pole[xodit][Xkor + 1][Ykor] = korablN[xodit];
					pole[xodit][Xkor + 2][Ykor] = korablN[xodit]; pole[xodit][Xkor + 3][Ykor] = korablN[xodit];
					zoloto[xodit] = zoloto[xodit] - cenu[rassa[xodit]][k[xodit]];

					korabli[xodit][korablN[xodit]][1] = 4; //  тип
					korabli[xodit][korablN[xodit]][2] = 4;   //   ХП
					korablN[xodit] = korablN[xodit] + 1;

					//------------- Графика
					TRect A(0, 0, wirina / nMax * 4, visota / mMax);
					TRect B((Xkor - 1) * wirina / nMax, (Ykor - 1) * visota / mMax, (Xkor - 1) * wirina / nMax + wirina / nMax * 4, (Ykor - 1) * visota / mMax + visota / mMax);
					Image1->Bitmap->Canvas->BeginScene();
					Image1->Bitmap->Canvas->DrawBitmap(R1K5->Bitmap, A, B, 1, false);
					Image1->Bitmap->Canvas->EndScene();
					//----------------
				}
				break;
			}
			case 5: {
				if (Xkor < nMax && Ykor < mMax && pole[xodit][Xkor][Ykor] == 0 && pole[xodit][Xkor + 1][Ykor] == 0 &&
					pole[xodit][Xkor - 1][Ykor] == 0 &&
					pole[xodit][Xkor][Ykor - 1] == 0 && pole[xodit][Xkor][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 1] == 0 &&
					pole[xodit][Xkor + 1][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor + 1] == 0 && pole[xodit][Xkor + 1][Ykor - 1] == 0
					&& pole[xodit][Xkor][Ykor + 2] == 0 && pole[xodit][Xkor + 1][Ykor + 2] == 0
					&& pole[xodit][Xkor + 2][Ykor + 2] == 0 && pole[xodit][Xkor + 2][Ykor - 2] == 0 && pole[xodit][Xkor + 2][Ykor] == 0
					&& pole[xodit][Xkor + 2][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 2] == 0)


				{
					pole[xodit][Xkor][Ykor] = korablN[xodit]; pole[xodit][Xkor + 1][Ykor] = korablN[xodit];
					pole[xodit][Xkor + 1][Ykor + 1] = korablN[xodit]; pole[xodit][Xkor][Ykor + 1] = korablN[xodit];
					zoloto[xodit] = zoloto[xodit] - cenu[rassa[xodit]][k[xodit]];
					korabli[xodit][korablN[xodit]][1] = 5; //  тип
					korabli[xodit][korablN[xodit]][2] = 4;   //   ХП
					korablN[xodit] = korablN[xodit] + 1;

					//------------- Графика
					TRect A(0, 0, wirina / nMax * 2, visota / mMax * 2);
					TRect B((Xkor - 1) * wirina / nMax, (Ykor - 1) * visota / mMax, (Xkor - 1) * wirina / nMax + wirina / nMax * 2, (Ykor - 1) * visota / mMax + visota / mMax * 2);
					Image1->Bitmap->Canvas->BeginScene();
					Image1->Bitmap->Canvas->DrawBitmap(R1K3->Bitmap, A, B, 1, false);
					Image1->Bitmap->Canvas->EndScene();
					//----------------
				}
				break;
			}
			default:;
			}
			//--------Если закончилось золотоо

			if (zoloto[xodit] == 0)
				rasstavlyaet = 0;
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PosetiImMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	Client1->Connect();
	PosetiIm->Visible = false;
	MenuIm->Visible = true;
	PomowIm->Visible = false;
	SkompomIm->Visible = false;
	VixodIm->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SkompomImMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	zoloto[1] = 10000;
	zoloto[2] = 1000;

	int Xkor, Ykor;
	rassa[2] = 1;    xodit = 2;
	PosetiIm->Visible = false;
	MenuIm->Visible = true;
	PomowIm->Visible = false;
	SkompomIm->Visible = false;
	VixodIm->Visible = false;
	ViborIm->Visible = true;
	korablN[xodit] = 1;


	//---------------Комп расставляет
	do {
		k[xodit] = random(4) + 1;
		Xkor = random(nMax - 1) + 1;
		Ykor = random(mMax - 1) + 1;
		//randomize();


		//-------------------------
		 //-----Хватает ли золота на постройку

		if (zoloto[xodit] - cenu[rassa[rassa[2]]][k[xodit]] >= 0) {
			//-------------Выбор типа корабля

			switch (k[xodit]) {
			case 1: {
				if (pole[xodit][Xkor][Ykor] == 0 && pole[xodit][Xkor + 1][Ykor] == 0 && pole[xodit][Xkor - 1][Ykor] == 0 &&
					pole[xodit][Xkor][Ykor - 1] == 0 && pole[xodit][Xkor][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 1] == 0 &&
					pole[xodit][Xkor + 1][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor + 1] == 0 && pole[xodit][Xkor + 1][Ykor - 1] == 0)
				{
					pole[xodit][Xkor][Ykor] = korablN[xodit];

					korabli[xodit][korablN[xodit]][1] = 1; //  тип
					korabli[xodit][korablN[xodit]][2] = 1;   //   ХП


					korablN[xodit] = korablN[xodit] + 1;
					zoloto[xodit] = zoloto[xodit] - cenu[rassa[2]][k[xodit]];

				}

				break;
			}
					//------------------------
			case 2: {
				if (Xkor < nMax && pole[xodit][Xkor][Ykor] == 0 && pole[xodit][Xkor + 1][Ykor] == 0 && pole[xodit][Xkor - 1][Ykor] == 0 &&
					pole[xodit][Xkor][Ykor - 1] == 0 && pole[xodit][Xkor][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 1] == 0 &&
					pole[xodit][Xkor + 1][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor + 1] == 0 && pole[xodit][Xkor + 1][Ykor - 1] == 0
					&& pole[xodit][Xkor + 2][Ykor] == 0 && pole[xodit][Xkor + 2][Ykor + 1] == 0 && pole[xodit][Xkor + 2][Ykor - 1] == 0)
				{
					pole[xodit][Xkor][Ykor] = korablN[xodit]; pole[xodit][Xkor + 1][Ykor] = korablN[xodit];

					korabli[xodit][korablN[xodit]][1] = 2; //  тип
					korabli[xodit][korablN[xodit]][2] = 2;   //   ХП
					korablN[xodit] = korablN[xodit] + 1;

					zoloto[xodit] = zoloto[xodit] - cenu[rassa[2]][k[xodit]];
				}
				break;
			}
					//-----------------------
			case 3: {
				if (Xkor < nMax - 1 && pole[xodit][Xkor][Ykor] == 0 && pole[xodit][Xkor + 1][Ykor] == 0 && pole[xodit][Xkor - 1][Ykor] == 0 &&
					pole[xodit][Xkor][Ykor - 1] == 0 && pole[xodit][Xkor][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 1] == 0 &&
					pole[xodit][Xkor + 1][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor + 1] == 0 && pole[xodit][Xkor + 1][Ykor - 1] == 0
					&& pole[xodit][Xkor + 2][Ykor] == 0 && pole[xodit][Xkor + 2][Ykor + 1] == 0 && pole[xodit][Xkor + 2][Ykor - 1] == 0
					&& pole[xodit][Xkor + 3][Ykor] == 0 && pole[xodit][Xkor + 3][Ykor - 1] == 0 && pole[xodit][Xkor + 3][Ykor + 1] == 0)
				{
					pole[xodit][Xkor][Ykor] = korablN[xodit]; pole[xodit][Xkor + 1][Ykor] = korablN[xodit];
					pole[xodit][Xkor + 2][Ykor] = korablN[xodit];

					korabli[xodit][korablN[xodit]][1] = 2; //  тип
					korabli[xodit][korablN[xodit]][2] = 2;   //   ХП

					korablN[xodit] = korablN[xodit] + 1;

					zoloto[xodit] = zoloto[xodit] - cenu[rassa[2]][k[xodit]];
				}
				break;
			}
			case 4: {
				if (Xkor < nMax - 2 && pole[xodit][Xkor][Ykor] == 0 && pole[xodit][Xkor + 1][Ykor] == 0 && pole[xodit][Xkor - 1][Ykor] == 0 &&
					pole[xodit][Xkor][Ykor - 1] == 0 && pole[xodit][Xkor][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 1] == 0 &&
					pole[xodit][Xkor + 1][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor + 1] == 0 && pole[xodit][Xkor + 1][Ykor - 1] == 0
					&& pole[xodit][Xkor + 2][Ykor] == 0 && pole[xodit][Xkor + 2][Ykor + 1] == 0 && pole[xodit][Xkor + 2][Ykor - 1] == 0
					&& pole[xodit][Xkor + 3][Ykor] == 0 && pole[xodit][Xkor + 3][Ykor - 1] == 0 && pole[xodit][Xkor + 3][Ykor + 1] == 0
					&& pole[xodit][Xkor + 4][Ykor] == 0 && pole[xodit][Xkor + 4][Ykor - 1] == 0 && pole[xodit][Xkor + 4][Ykor + 1] == 0)
				{
					pole[xodit][Xkor][Ykor] = korablN[xodit]; pole[xodit][Xkor + 1][Ykor] = korablN[xodit];
					pole[xodit][Xkor + 2][Ykor] = korablN[xodit]; pole[xodit][Xkor + 3][Ykor] = korablN[xodit];
					zoloto[xodit] = zoloto[xodit] - cenu[rassa[2]][k[xodit]];
					korabli[xodit][korablN[xodit]][1] = 4; //  тип
					korabli[xodit][korablN[xodit]][2] = 4;   //   ХП
					korablN[xodit] = korablN[xodit] + 1;
				}

				break;
			}
			case 5: {
				if (Xkor < nMax && Ykor < mMax && pole[xodit][Xkor][Ykor] == 0 && pole[xodit][Xkor + 1][Ykor] == 0 &&
					pole[xodit][Xkor - 1][Ykor] == 0 &&
					pole[xodit][Xkor][Ykor - 1] == 0 && pole[xodit][Xkor][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 1] == 0 &&
					pole[xodit][Xkor + 1][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor + 1] == 0 && pole[xodit][Xkor + 1][Ykor - 1] == 0
					&& pole[xodit][Xkor][Ykor + 2] == 0 && pole[xodit][Xkor + 1][Ykor + 2] == 0
					&& pole[xodit][Xkor + 2][Ykor + 2] == 0 && pole[xodit][Xkor + 2][Ykor - 2] == 0 && pole[xodit][Xkor + 2][Ykor] == 0
					&& pole[xodit][Xkor + 2][Ykor + 1] == 0 && pole[xodit][Xkor - 1][Ykor - 2] == 0)


				{
					pole[xodit][Xkor][Ykor] = korablN[xodit]; pole[xodit][Xkor + 1][Ykor] = korablN[xodit];
					pole[xodit][Xkor + 1][Ykor + 1] = korablN[xodit]; pole[xodit][Xkor][Ykor + 1] = korablN[xodit];
					zoloto[xodit] = zoloto[xodit] - cenu[rassa[2]][k[xodit]];
					korabli[xodit][korablN[xodit]][1] = 5; //  тип
					korabli[xodit][korablN[xodit]][2] = 4;   //   ХП
					korablN[xodit] = korablN[xodit] + 1;
				}

				break;
			}
			default:;
			}
		}
		//------------------------
	} while (zoloto[xodit] > 0);

	xodit = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuImMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	Image1->Visible = false;
	Image2->Visible = false;
	ViborIm->Visible = false;
	PosetiIm->Visible = true;
	MenuIm->Visible = false;
	TextIm->Visible = false;
	PomowIm->Visible = true;
	SkompomIm->Visible = true;
	VixodIm->Visible = true;
	ZanovoIm->Visible = false;
	Start->Visible = false;

	R1K1->Visible = false;
	R1K2->Visible = false;
	R1K3->Visible = false;
	R1K4->Visible = false;
	R1K5->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VixodImMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PomowImMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	TextIm->Visible = true;
	ViborIm->Visible = false;
	PosetiIm->Visible = false;
	MenuIm->Visible = true;
	PomowIm->Visible = false;
	SkompomIm->Visible = false;
	VixodIm->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ViborImMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{


	if (X < ViborIm->Width / 2) {
		rassa[1] = 1;
		R1K1->Visible = true;
		R1K2->Visible = true;
		R1K3->Visible = true;
		R1K4->Visible = true;
		R1K5->Visible = true;

	}
	else { rassa[1] = 2; }
	rasstavlyaet = 1;
	Start->Visible = true;
	Image1->Visible = true;
	Image2->Visible = true;
	ZanovoIm->Visible = true;
	ViborIm->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZanovoImMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	Image1->Visible = false;
	Image2->Visible = false;
	ZanovoIm->Visible = false;
	ViborIm->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject* Sender)
{
	for (int i = 1; i < 3; i++)
		for (int n = 1; n < 20; n++)
			for (int m = 1; m < 20; m++)
				pole[i][n][m] = 0;

	cenu[1][1] = 200;
	cenu[1][2] = 200;
	cenu[1][3] = 200;
	cenu[1][4] = 200;
	cenu[1][5] = 200;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::R1K1MouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	k[xodit] = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::R1K3MouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	k[xodit] = 5;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::R1K2MouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	k[xodit] = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::R1K4MouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	k[xodit] = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::R1K5MouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	k[xodit] = 4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StartMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)
{
	R1K1->Visible = false;
	R1K2->Visible = false;
	R1K3->Visible = false;
	R1K4->Visible = false;
	R1K5->Visible = false;
	Start->Visible = false;
	xodit = 1;
}
//---------------------------------------------------------------------------

void send(TIdTCPConnection* Connection)
{

	Connection->Socket->Write("sfhdfh");
}

void __fastcall TForm1::Image2MouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y)

{
	if (xodit = 1) {

		int n, m, Xkor, Ykor;

		//-------------------
		wirina = Image1->Bitmap->Width;
		visota = Image1->Bitmap->Height;
		//-------------------
		for (n = 1; n <= nMax; n++)
		{
			if (X < wirina / nMax * n) {
				Xkor = n; break;
			}

		}
		for (m = 1; m <= mMax; m++)
		{
			if (Y < visota / mMax * m) {
				Ykor = m; break;
			}

		}

		if (pole[2][Xkor][Ykor] != 0)
		{
			TRect A(0, 0, wirina / nMax, visota / mMax);
			TRect B((Xkor - 1) * wirina / nMax, (Ykor - 1) * visota / mMax, (Xkor - 1) * wirina / nMax + wirina / nMax, (Ykor - 1) * visota / mMax + visota / mMax);
			Image2->Bitmap->Canvas->BeginScene();
			Image2->Bitmap->Canvas->DrawBitmap(R1K1->Bitmap, A, B, 1, false);
			Image2->Bitmap->Canvas->EndScene();

		}
		else
		{

			TRect A(0, 0, wirina / nMax, visota / mMax);
			TRect B((Xkor - 1) * wirina / nMax, (Ykor - 1) * visota / mMax, (Xkor - 1) * wirina / nMax + wirina / nMax, (Ykor - 1) * visota / mMax + visota / mMax);
			Image2->Bitmap->Canvas->BeginScene();
			Image2->Bitmap->Canvas->DrawBitmap(vzruv->Bitmap, A, B, 1, false);
			Image2->Bitmap->Canvas->EndScene();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Server1Execute(TIdContext* AContext)
{
	int lenght = AContext->Connection->Socket->ReadLongInt();
	UnicodeString Message = AContext->Connection->Socket->ReadString(lenght);
	Message = "321";
	//AContext->Connection->Disconnect();
	AContext->Connection->Socket->WriteLn(Message);
	//Button1->Text="execute";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Enter(TObject* Sender)
{

	Client1->Disconnect();
	Client1->Connect();

	Client1->Socket->Write(Edit1->Text.Length());
	Client1->Socket->Write(Edit1->Text);
	UnicodeString nam = Client1->Socket->ReadString(3);
	Button1->Text = nam;
	//Client1->Disconnect();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Client1Connected(TObject* Sender)
{


	//Button1->Text="connect";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseMove(TObject* Sender, TShiftState Shift, float X,
	float Y)
{
	if (R1K1->Visible == false)
		R1K1->Visible = true;
	R1K1->Position->X = X;
	R1K1->Position->Y = Y;
}
//---------------------------------------------------------------------------
