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
		cout << "Введите номер операции:" << endl;
		cout << "1. Ввести новый текст" << endl;
		cout << "2. Вывести текст на экран" << endl;
		cout << "3. Вставить строку в текст в данную секцию" << endl;
		cout << "4. Вставить строку в текст в нижнюю секцию" << endl;
		cout << "5. Вставить строку в текст в данную секцию с созданием нижней секции" << endl;
		cout << "6. Вставить строку в текст в нижнюю секцию с созданием нижней секции" << endl;
		cout << "7. Удалить строку из текста в данной секции" << endl;
		cout << "8. Удалить строку из текста в нижней секции" << endl;
		cout << "9. Вывести данную строку" << endl;
		cout << "10. Редактировать данную строку" << endl;
		cout << "11. Навигация по тексту" << endl;
		cout << "12. Вывести список свободных звеньев" << endl;
		cout << "13. Сборка \"мусора\"" << endl;
		cout << "14. Сохранить текст в файл" << endl;
		cout << "15. Завершение работы" << endl;
		cin >> p;
		switch (p)
		{
		case 1: cout << "Введите имя документа с текстом:" << endl;
			cin.get();
			getline(cin, str);
			t.Load(str);
			break;

		case 2: cout << endl;
			t.PrintText();
			break;

		case 3: cout << "Введите текст, который хотите добавить:" << endl;
			cin.get();
			getline(cin, str);
			t.InsNextLine(str);
			cout << endl;
			t.PrintText();
			break;

		case 4: cout << "Введите текст, который хотите добавить:" << endl;
			cin.get();
			getline(cin, str);
			t.InsDownLine(str);
			cout << endl;
			t.PrintText();
			break;

		case 5: cout << "Введите текст, который хотите добавить:" << endl;
			cin.get();
			getline(cin, str);
			t.InsNextSection(str);
			cout << endl;
			t.PrintText();
			break;

		case 6: cout << "Введите текст, который хотите добавить:" << endl;
			cin.get();
			getline(cin, str);
			t.InsDownSection(str);
			cout << endl;
			t.PrintText();
			break;

		case 7:	t.DelNextLine();
			cout << endl;
			t.PrintText();
			break;

		case 8: t.DelDownLine();
			cout << endl;
			t.PrintText();
			break;

		case 9: cout << "Данная строка:" << endl;
			cout << t.GetLine() << endl;
			break;

		case 10: cout << "Введите текст, который хотите добавить:" << endl;
			cin.get();
			getline(cin, str);
			t.SetLine(str);
			cout << endl;
			t.PrintText();
			break;

		case 11: t.Navigation();
			break;

		case 12: TLink::PrintFree();
			break;

		case 13: TLink::MemClean(t);  
			break;

		case 14: cout << "Введите имя документа, в который хотите сохранить текст:" << endl;
			cin.get();
			getline(cin, str);
			t.SaveText(str);
			break;

		case 15: break;

		default: cout << "Некорректный ввод! Введите номер операции заново." << endl;
		}
		cout << endl;
	} while (p!=15);
	return 0;
}
