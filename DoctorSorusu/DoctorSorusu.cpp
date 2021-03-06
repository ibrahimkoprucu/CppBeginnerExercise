#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void BilgiAl(int  bolum_toplam[7], int  cerrahi[4]);
void Islem1(int  cerrahi[4], string doktorlar[4]);
void Islem2(int  bolum_toplam[7], string  bolumler[7]);
int main()
{
	setlocale(LC_ALL, "turkish");
	string doktorlar[4] = { "Ahmet","Mehmet","Ayse","Fatma" };
	string bolumler[7] = { "A","B","C","D","E","F","Cerrahi" };//bölümlerin isimlerini harflerle ifade ettim.
	int cerrahi[4] = { 0 };       // cerrahi bölümüne  gönderilen toplam hasta sayıları tutulacak
	int bolum_toplam[7] = { 0 };  //her bir bölüme gönderilen toplam hasta sayılarını tutacak

	BilgiAl(bolum_toplam, cerrahi);
	Islem1(cerrahi, doktorlar);
	Islem2(bolum_toplam, bolumler);
}

void Islem1(int  cerrahi[4], string doktorlar[4])
{
	int en_buyuk = 0;
	int indis = 0;
	for (int i = 0; i < 4; i++)
	{
		if (cerrahi[i] > en_buyuk)
		{
			en_buyuk = cerrahi[i];
			indis = i;
		}
	}

	cout << "cerrahi bölümüne " << en_buyuk << " hastayla en fazla hasta gönderen doktorun ismi " << doktorlar[indis] << endl;
}

void Islem2(int  bolum_toplam[7], string  bolumler[7])
{
	int en_buyuk = 0;
	int indis = 0;
	for (int i = 0; i < 7; i++)
	{
		if (bolum_toplam[i] > en_buyuk)
		{
			en_buyuk = bolum_toplam[i];
			indis = i;
		}
	}
	cout << "en fazla hasta " << en_buyuk << " hastayla " << bolumler[indis] << " bölümüne gönderilmiştir" << endl;
}

void BilgiAl(int  bolum_toplam[7], int  cerrahi[4])
{
	while (true)
	{
		int doktor_no = 0;
		int hata = 0;
		int hasta_durumu = 0;
		int bolum = 0;

		do
		{
			cout << "hasta hangi doktora geldi(Ahmet-1,Mehmet-2,Ayşe-3,Fatma-4)?" << endl;
			cin >> doktor_no;
			hata++;
			if (hata == 3)
			{
				cout << "fazla hata yaptınız program sonlandırılacaktır" << endl;
				exit(1);
			}
		} while (doktor_no < 0 || doktor_no>4); //doktor_no'yu doğru girmezse döngüye devam edecek.

		hata = 0;
		do
		{
			cout << "hastanın durumu ağır mı?(ağır-1,hafif-2)" << endl;
			cin >> hasta_durumu;
			hata++;
			if (hata == 3)
			{
				cout << "fazla hata yaptınız program sonlandırılacaktır" << endl;
				exit(1);
			}
		} while (hasta_durumu < 0 || hasta_durumu>2);

		hata = 0;
		if (hasta_durumu == 1)
		{
			do
			{
				cout << "hasta hangi bölüme havale edildi(A-1,B-2,C-3,D-4,E-5,F-6,Cerrahi-7)?" << endl;
				cin >> bolum;
				hata++;
				if (hata == 3)
				{
					cout << "çok fazla hata yaptınız program sonlandırılacaktır" << endl;
					exit(1);
				}
			} while (bolum < 1 || bolum>7);//klavyeden sayısal bir değer girmezse de patlayacak yeterli değil aslında

			bolum_toplam[bolum - 1]++;
			if (bolum == 7)
			{
				cerrahi[doktor_no - 1]++;
			}
		}
		else
		{
			cout << "hasta tedavi edildi ve evine gönderildi." << endl;
		}

		string karar = "0";
		hata = 0;
		do
		{
			cout << "bitirmek için 1 giriniz devam için 2" << endl;
			cin >> karar;
			hata++;
			if (hata == 3)
			{
				cout << "çok fazla hata yaptınız" << "program sonlandırılacaktır" << endl;
				exit(1);//fonksiyonun tanımına üzerine f12 ye basarak bakabilirsiniz
			}
		} while (karar != "1" && karar != "2"); //mesala burda yukarıdaki sorun yok istersen ½,} bunları gir

		if (karar == "1")
		{
			cout << "gün bitti" << endl;
			break;
		}
	}
}