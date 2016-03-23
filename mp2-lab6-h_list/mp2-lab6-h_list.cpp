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
	int p;
	do
	{
		char st[MaxLen];
		cout << "Введите номер операции:" << endl;
		cout << "1. Ввести новый текст" << endl;
		cout << "2. Вывести текст на экран" << endl;
		cout << "3. Вставить строку в текст в данную секцию" << endl;
		cout << "4. Вставить строку в текст в нижнюю секцию" << endl;
		cout << "5. Вставить строку в текст в данную секцию с созданием нижней секции" << endl;
		cout << "6. Вставить строку в текст в нижнюю секцию с созданием нижней секции" << endl;
		cout << "7. Удалить строку из текста в данной секции" << endl;
		cout << "8. Удалить строку из текста в нижней секции" << endl;
		cout << "9. Навигация по тексту" << endl;
		cout << "10. Вывести список свободных звеньев" << endl;
		cout << "11. Сборка \"мусора\"" << endl;
		cout << "12. Сохранить текст в файл" << endl;
		cout << "13. Завершение работы" << endl;
		cin >> p;
		switch (p)
		{
		case 1: cout << "Введите имя документа с текстом:" << endl;
			cin >> str;
			t.Load(str);
			break;

		case 2: t.PrintText();
			break;

		case 3: cout << "Введите строку, которую хотите добавить:" << endl;  
			cin >> st;
			t.InsNextLine(st);
			t.PrintText();
			break;

		case 4: cout << "Введите строку, которую хотите добавить:" << endl;
			cin >> st;
			t.InsDownLine(st);
			t.PrintText();
			break;

		case 5: cout << "Введите строку, которую хотите добавить:" << endl; 
			cin >> st;
			t.InsNextSection(st);
			t.PrintText();
			break;

		case 6: cout << "Введите строку, которую хотите добавить:" << endl;
			cin >> st;
			t.InsDownSection(st);
			t.PrintText();
			break;

		case 7:	t.DelNextLine();
			t.PrintText();
			break;

		case 8: t.DelDownLine();
			t.PrintText();
			break;

		case 9: t.Navigation();
			break;

		case 10: TLink::PrintFree();
			break;

		case 11: TLink::MemClean(t);  
			break;

		case 12: cout << "Введите имя документа, в который хотите сохранить текст:" << endl;
			cin >> str;
			t.SaveText(str);
			break;

		case 13: break;

		default: cout << "Некорректный ввод! Введите номер операции заново." << endl;
		}
		cout << endl;
	} while (p!=13);
	return 0;
}

