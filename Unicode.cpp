#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

double pow(double x, int y)
{
    double temp;
    if (y == 0)
    return 1;
    temp = pow(x, y / 2);
    if ((y % 2) == 0) {
        return temp * temp;
    } else {
        if (y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

string DecToHex(int a) // is desimtaines i sesioliktaine.
{
	char hexa[1000];
	_itoa_s(a, hexa, 16);
	return string(hexa);
}

int bytskai(int a)				// nustato kiek bitu uzims simbolis
{
	if (a<128)
	{
		return 1;
	}
	if (a < 2048)
	{
		return 2;
	}
	if (a < 65536)
	{
		return 3;
	}
	if (a < 1114112)
	{
		return 4;
	}
}

void utf8(int a)
{
	int n = a;
	int bytes = bytskai(a);
	if (bytes == 1)			// jei uzima viena bita tiesiog ji verciame.
	{
		cout << "UTF-8: " << DecToHex(a) << endl;			// pavercia simboli i hex.
	}
	else
	{
		long long binnum = 0;
		int liekana = 0, k = 0, y = 0;
		int bin[21] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, bin2[21] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; // binarus sk
		while (n != 0)
		{
			liekana = n % 2;
			n = n / 2;
			bin[y] = liekana;
			y++;
			k++;
		}
		for (int i = 21; i > 0; i--)
		{
			bin2[21 - i] = bin[i - 1];
		}
		int j = 21;

		if (bytes == 2)
		{
			int byte1[8] = { 1,1,0,0,0,0,0,0 }, byte2[8] = { 1,0,0,0,0,0,0,0 };
			for (int i = 7; i >= 2; i--)
			{
				j--;
				byte2[i] = bin2[j];
			}
			for (int i = 7; i >= 3; i--)
			{
				j--;
				byte1[i] = bin2[j];
			}
			stringstream s1, s2;
			int skc1, skc2;
			for (int a : byte1)
			{
				s1 << a;
			}
			s1 >> skc1;
			for (int b : byte2)
			{
				s2 << b;
			}
			s2 >> skc2;
			int decNum = 0, x = 0, liekana1;
			while (skc1 != 0)
			{
				liekana1 = skc1 % 10;
				skc1 = skc1 / 10;
				decNum = decNum + liekana1 * pow(2, x);
				x++;
			}
			int decNum1 = 0, x1 = 0, liekana2;
			while (skc2 != 0)
			{
				liekana2 = skc2 % 10;
				skc2 = skc2 / 10;
				decNum1 = decNum1 + liekana2 * pow(2, x1);
				x1++;
			}
			string skaicius; skaicius = DecToHex(decNum);
			string skaicius2; skaicius2 = DecToHex(decNum1);
			cout << "UTF-8: " << skaicius << " " << skaicius2 << endl;
		}
		if (bytes == 3)
		{
			int byte1[8] = { 1,1,1,0,0,0,0,0 }, byte2[8] = { 1,0,0,0,0,0,0,0 }, byte3[8] = { 1,0,0,0,0,0,0,0 };
			for (int i = 7; i >= 2; i--)
			{
				j--;
				byte3[i] = bin2[j];
			}
			for (int i = 7; i >= 2; i--)
			{
				j--;
				byte2[i] = bin2[j];
			}
			for (int i = 7; i >= 4; i--)
			{
				j--;
				byte1[i] = bin2[j];
			}
			stringstream s1, s2, s3;
			int skc1, skc2, skc3;
			for (int a : byte1)
			{
				s1 << a;
			}
			s1 >> skc1;
			for (int b : byte2)
			{
				s2 << b;
			}
			s2 >> skc2;
			for (int c : byte3)
			{
				s3 << c;
			}
			s3 >> skc3;

			int decNum = 0, x = 0, liekana1;
			while (skc1 != 0)
			{
				liekana1 = skc1 % 10;
				skc1 = skc1 / 10;
				decNum = decNum + liekana1 * pow(2, x);
				x++;
			}
			int decNum1 = 0, x1 = 0, liekana2;
			while (skc2 != 0)
			{
				liekana2 = skc2 % 10;
				skc2 = skc2 / 10;
				decNum1 = decNum1 + liekana2 * pow(2, x1);
				x1++;
			}
			int decNum2 = 0, x2 = 0, liekana3;
			while (skc3 != 0)
			{
				liekana3 = skc3 % 10;
				skc3 = skc3 / 10;
				decNum2 = decNum2 + liekana3 * pow(2, x2);
				x2++;
			}
			string skaicius; skaicius = DecToHex(decNum);
			string skaicius2; skaicius2 = DecToHex(decNum1);
			string skaicius3; skaicius3 = DecToHex(decNum2);
			cout << "UTF-8: " << skaicius << " " << skaicius2 << " " << skaicius3 << endl;
		}
		if (bytes == 4)
		{
			int byte1[8] = { 1,1,1,1,0,0,0,0 }, byte2[8] = { 1,0,0,0,0,0,0,0 }, byte3[8] = { 1,0,0,0,0,0,0,0 }, byte4[8] = { 1,0,0,0,0,0,0,0 };
			for (int i = 7; i >= 2; i--)
			{
				j--;
				byte4[i] = bin2[j];
			}
			for (int i = 7; i >= 2; i--)
			{
				j--;
				byte3[i] = bin2[j];
			}
			for (int i = 7; i >= 2; i--)
			{
				j--;
				byte2[i] = bin2[j];
			}
			for (int i = 7; i >= 5; i--)
			{
				j--;
				byte1[i] = bin2[j];
			}
			stringstream s1, s2, s3, s4;
			int skc1, skc2, skc3, skc4;
			for (int a : byte1)
			{
				s1 << a;
			}
			s1 >> skc1;
			for (int b : byte2)
			{
				s2 << b;
			}
			s2 >> skc2;
			for (int c : byte3)
			{
				s3 << c;
			}
			s3 >> skc3;
			for (int d : byte4)
			{
				s4 << d;
			}
			s4 >> skc4;

			int decNum = 0, x = 0, liekana1;
			while (skc1 != 0)
			{
				liekana1 = skc1 % 10;
				skc1 = skc1 / 10;
				decNum = decNum + liekana1 * pow(2, x);
				x++;
			}
			int decNum1 = 0, x1 = 0, liekana2;
			while (skc2 != 0)
			{
				liekana2 = skc2 % 10;
				skc2 = skc2 / 10;
				decNum1 = decNum1 + liekana2 * pow(2, x1);
				x1++;
			}
			int decNum2 = 0, x2 = 0, liekana3;
			while (skc3 != 0)
			{
				liekana3 = skc3 % 10;
				skc3 = skc3 / 10;
				decNum2 = decNum2 + liekana3 * pow(2, x2);
				x2++;
			}
			int decNum3 = 0, x3 = 0, liekana4;
			while (skc4 != 0)
			{
				liekana4 = skc4 % 10;
				skc4 = skc4 / 10;
				decNum3 = decNum3 + liekana4 * pow(2, x3);
				x3++;
			}
			string skaicius; skaicius = DecToHex(decNum);
			string skaicius2; skaicius2 = DecToHex(decNum1);
			string skaicius3; skaicius3 = DecToHex(decNum2);
			string skaicius4; skaicius4 = DecToHex(decNum3);
			cout << "UTF-8: " << skaicius << " " << skaicius2 << " " << skaicius3 << " " << skaicius4 << endl;
		}
	}
}

string CodePage427(unsigned char simbolis)
{
	if (simbolis == 128)
		return u8"\u00C7";
	if (simbolis == 129)
		return u8"\u00FC";
	if (simbolis == 130)
		return u8"\u00E9";
	if (simbolis == 131)
		return u8"\u00E2";
	if (simbolis == 132)
		return u8"\u00E4";
	if (simbolis == 133)
		return u8"\u00E0";
	if (simbolis == 134)
		return u8"\u00E5";
	if (simbolis == 135)
		return u8"\u00E7";
	if (simbolis == 136)
		return u8"\u00EA";
	if (simbolis == 137)
		return u8"\u00EB";
	if (simbolis == 138)
		return u8"\u00E8";
	if (simbolis == 139)
		return u8"\u00EF";
	if (simbolis == 140)
		return u8"\u00EE";
	if (simbolis == 141)
		return u8"\u00EC";
	if (simbolis == 142)
		return u8"\u00C4";
	if (simbolis == 143)
		return u8"\u00C5";
	if (simbolis == 144)
		return u8"\u00C9";
	if (simbolis == 145)
		return u8"\u00E6";
	if (simbolis == 146)
		return u8"\u00C6";
	if (simbolis == 147)
		return u8"\u00F4";
	if (simbolis == 148)
		return u8"\u00F6";
	if (simbolis == 149)
		return u8"\u00F2";
	if (simbolis == 150)
		return u8"\u00FB";
	if (simbolis == 151)
		return u8"\u00F9";
	if (simbolis == 152)
		return u8"\u00FF";
	if (simbolis == 153)
		return u8"\u00D6";
	if (simbolis == 154)
		return u8"\u00DC";
	if (simbolis == 155)
		return u8"\u00A2";
	if (simbolis == 156)
		return u8"\u00A3";
	if (simbolis == 157)
		return u8"\u00A5";
	if (simbolis == 158)
		return u8"\u20A7";
	if (simbolis == 159)
		return u8"\u0192";
	if (simbolis == 160)
		return u8"\u00E1";
	if (simbolis == 161)
		return u8"\u00ED";
	if (simbolis == 162)
		return u8"\u00F3";
	if (simbolis == 163)
		return u8"\u00FA";
	if (simbolis == 164)
		return u8"\u00F1";
	if (simbolis == 165)
		return u8"\u00D1";
	if (simbolis == 166)
		return u8"\u00AA";
	if (simbolis == 167)
		return u8"\u00BA";
	if (simbolis == 168)
		return u8"\u00BF";
	if (simbolis == 169)
		return u8"\u2310";
	if (simbolis == 170)
		return u8"\u00AC";
	if (simbolis == 171)
		return u8"\u00BD";
	if (simbolis == 172)
		return u8"\u00BC";
	if (simbolis == 173)
		return u8"\u00A1";
	if (simbolis == 174)
		return u8"\u00AB";
	if (simbolis == 175)
		return u8"\u00BB";
	if (simbolis == 176)
		return u8"\u2591";
	if (simbolis == 177)
		return u8"\u2592";
	if (simbolis == 178)
		return u8"\u2593";
	if (simbolis == 179)
		return u8"\u2502";
	if (simbolis == 180)
		return u8"\u2524";
	if (simbolis == 181)
		return u8"\u2561";
	if (simbolis == 182)
		return u8"\u2562";
	if (simbolis == 183)
		return u8"\u2556";
	if (simbolis == 184)
		return u8"\u2555";
	if (simbolis == 185)
		return u8"\u2563";
	if (simbolis == 186)
		return u8"\u2551";
	if (simbolis == 187)
		return u8"\u2557";
	if (simbolis == 188)
		return u8"\u255D";
	if (simbolis == 189)
		return u8"\u255C";
	if (simbolis == 190)
		return u8"\u255B";
	if (simbolis == 191)
		return u8"\u2510";
	if (simbolis == 192)
		return u8"\u2514";
	if (simbolis == 193)
		return u8"\u2534";
	if (simbolis == 194)
		return u8"\u252C";
	if (simbolis == 195)
		return u8"\u251C";
	if (simbolis == 196)
		return u8"\u2500";
	if (simbolis == 197)
		return u8"\u253C";
	if (simbolis == 198)
		return u8"\u255E";
	if (simbolis == 199)
		return u8"\u255F";
	if (simbolis == 200)
		return u8"\u255A";
	if (simbolis == 201)
		return u8"\u2554";
	if (simbolis == 202)
		return u8"\u2569";
	if (simbolis == 203)
		return u8"\u2566";
	if (simbolis == 204)
		return u8"\u2560";
	if (simbolis == 205)
		return u8"\u2550";
	if (simbolis == 206)
		return u8"\u256C";
	if (simbolis == 207)
		return u8"\u2567";
	if (simbolis == 208)
		return u8"\u2568";
	if (simbolis == 209)
		return u8"\u2564";
	if (simbolis == 210)
		return u8"\u2565";
	if (simbolis == 211)
		return u8"\u2559";
	if (simbolis == 212)
		return u8"\u2558";
	if (simbolis == 213)
		return u8"\u2552";
	if (simbolis == 214)
		return u8"\u2553";
	if (simbolis == 215)
		return u8"\u256B";
	if (simbolis == 216)
		return u8"\u256A";
	if (simbolis == 217)
		return u8"\u2518";
	if (simbolis == 218)
		return u8"\u250C";
	if (simbolis == 219)
		return u8"\u2588";
	if (simbolis == 220)
		return u8"\u2584";
	if (simbolis == 221)
		return u8"\u258C";
	if (simbolis == 222)
		return u8"\u2590";
	if (simbolis == 223)
		return u8"\u2580";
	if (simbolis == 224)
		return u8"\u03B1";
	if (simbolis == 225)
		return u8"\u00DF";
	if (simbolis == 226)
		return u8"\u0393";
	if (simbolis == 227)
		return u8"\u03C0";
	if (simbolis == 228)
		return u8"\u03A3";
	if (simbolis == 229)
		return u8"\u03C3";
	if (simbolis == 230)
		return u8"\u00B5";
	if (simbolis == 231)
		return u8"\u03C4";
	if (simbolis == 232)
		return u8"\u03A6";
	if (simbolis == 233)
		return u8"\u0398";
	if (simbolis == 234)
		return u8"\u03A9";
	if (simbolis == 235)
		return u8"\u03B4";
	if (simbolis == 236)
		return u8"\u221E";
	if (simbolis == 237)
		return u8"\u03C6";
	if (simbolis == 238)
		return u8"\u03B5";
	if (simbolis == 239)
		return u8"\u2229";
	if (simbolis == 240)
		return u8"\u2261";
	if (simbolis == 241)
		return u8"\u00B1";
	if (simbolis == 242)
		return u8"\u2265";
	if (simbolis == 243)
		return u8"\u2264";
	if (simbolis == 244)
		return u8"\u2320";
	if (simbolis == 245)
		return u8"\u2321";
	if (simbolis == 246)
		return u8"\u00F7";
	if (simbolis == 247)
		return u8"\u2248";
	if (simbolis == 248)
		return u8"\u00B0";
	if (simbolis == 249)
		return u8"\u2219";
	if (simbolis == 250)
		return u8"\u00B7";
	if (simbolis == 251)
		return u8"\u221A";
	if (simbolis == 252)
		return u8"\u207F";
	if (simbolis == 253)
		return u8"\u00B2";
	if (simbolis == 254)
		return u8"\u25A0";
	if (simbolis == 255)
		return u8"\u00A0";
}

int main()
{
	int pas;
	cout << "1. Pirma laboratorinio uzduotis. 2. Antra laboratorinio uzduotis" << endl;
		cin >> pas;
	switch (pas) {
	case 1 : {
		cout << "Iveskite skaiciu ir jis bus paverstas i UTF-8: ";
		int a;
		cin >> a;
		cout << "U+hex: U+" << DecToHex(a) << endl;
		utf8(a);
	} break;
	case 2 : {
		basic_ifstream <unsigned char> fd("386intel.txt");
		ofstream rez("rez.txt");
		unsigned char simbolis;

		while (fd)
		{
			fd.get(simbolis);
			if (simbolis < 128)
			{
				rez << simbolis;
			}
			else
			{
				rez << CodePage427(simbolis);
			}
		}
		fd.close();
		rez.close();
	}break;
	}
	return 0;
}
