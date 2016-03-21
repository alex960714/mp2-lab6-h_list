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
		int p1;
		int i = 1;
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
		cout << "9. Вывести список свободных звеньев" << endl;
		cout << "10. Сборка \"мусора\"" << endl;
		cout << "11. Сохранить текст в файл" << endl;
		cout << "12. Завершение работы" << endl;
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
			cout << "Введите номер строки, после которой хотите вставить новую строку:" << endl;
			cin >> p1;
			for (t.Reset(); !t.IsEnd();)
			{
				if (i == p1)
				{
					t.InsNextLine(st);
					t.PrintText();
					break;
				}
				t.GoNext();
				if (t.IsEnd())
					cout << "Такой строки не существует!" << endl;
				i++;
			}
			break;
		case 4: cout << "Введите строку, которую хотите добавить:" << endl;
			cin >> st;
			cout << "Введите номер строки, после которой хотите вставить новую строку:" << endl;
			cin >> p1;
			for (t.Reset(); !t.IsEnd();)
			{
				if (i == p1)
				{
					t.InsDownLine(st);
					t.PrintText();
					break;
				}
				t.GoNext();
				if (t.IsEnd())
					cout << "Такой строки не существует!" << endl;
				i++;
			}
			break;
		case 5: cout << "Введите строку, которую хотите добавить:" << endl; 
			cin >> st;
			cout << "Введите номер строки, после которой хотите вставить новую строку:" << endl;
			cin >> p1;
			for (t.Reset(); !t.IsEnd();)
			{
				if (i == p1)
				{
					t.InsNextSection(st);
					t.PrintText();
					break;
				}
				t.GoNext();
				if (t.IsEnd())
					cout << "Такой строки не существует!" << endl;
				i++;
			}
			break;
		case 6: cout << "Введите строку, которую хотите добавить:" << endl;
			cin >> st;
			cout << "Введите номер строки, после которой хотите вставить новую строку:" << endl;
			cin >> p1;
			for (t.Reset(); !t.IsEnd();)
			{
				if (i == p1)
				{
					t.InsDownSection(st);
					t.PrintText();
					break;
				}
				t.GoNext();
				if (t.IsEnd())
					cout << "Такой строки не существует!" << endl;
				i++;
			}
			break;
		case 7: cout << "Введите номер строки, которую хотите удалить:" << endl;  
			cin >> p1;
			i++;
			for (t.Reset(); !t.IsEnd();)
			{
				if (i == p1)
				{
					t.DelNextLine();
					t.PrintText();
					break;
				}
				t.GoNext();
				if (t.IsEnd())
					cout << "Такой строки не существует!" << endl;
				i++;
			}
			break;
		case 8: cout << "Введите номер строки, которую хотите удалить:" << endl;  
			cin >> p1;
			i++;
			for (t.Reset(); !t.IsEnd();)
			{
				if (i == p1)
				{
					t.DelDownLine();
					t.PrintText();
					break;
				}
				t.GoNext();
				if (t.IsEnd())
					cout << "Такой строки не существует!" << endl;
				i++;
			}
			break;
		case 9: TLink::PrintFree();
			break;
		case 10: TLink::MemClean(t);  
			break;
		case 11: cout << "Введите имя документа, в который хотите сохранить текст:" << endl;
			cin >> str;
			t.SaveText(str);
			break;
		case 12: break;
		default: cout << "Некорректный ввод! Введите номер операции заново." << endl;
		}
		cout << endl;
	} while (p!=12);
	return 0;
}

