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
	cout << "Введите имя документа с текстом:" << endl;
	cin >> str;
	t.Load(str);
	char p;
	do
	{
		cout << "Выберите номер операции:" << endl;
		cout << "1. Вывести текст на экран" << endl;
		cout << "4. Вывести список свободных звеньев" << endl;
		cout << "5. Сборка \"мусора\"" << endl;
		cout << "6. Завершение работы" << endl;
		cin >> p;
		switch (p)
		{
		case '1': t.PrintText();
			break;
		case '4': TLink::PrintFree();
			break;
		case '5': TLink::MemClean(t);
		case '6': break;
		default: cout << "Некорректный ввод! Введите номер операции заново." << endl;
		}
	} while (p!='6');
	return 0;
}

