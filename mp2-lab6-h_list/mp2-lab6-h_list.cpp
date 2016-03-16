// mp2-lab6-h_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TText.h"
#include <locale.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

TTextMem TLink::TextMem;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");
	TLink::InitMem(100);
	TText t;
	string str;
	cout << "Введите имя документа:" << endl;
	cin >> str;
	t.Load(str);
	t.PrintText();
	TLink::PrintFree();
	TLink::MemClean(t);
	TLink::PrintFree();
	return 0;
}

