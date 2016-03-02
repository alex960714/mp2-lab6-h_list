// mp2-lab6-h_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TText.h"
#include <locale.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");
	TText t;
	string str;
	cout << "Введите имя документа:" << endl;
	cin >> str;
	t.Load(str);
	t.PrintText();
	return 0;
}

