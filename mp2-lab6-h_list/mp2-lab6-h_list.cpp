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
	cout << "������� ��� ��������� � �������:" << endl;
	cin >> str;
	t.Load(str);
	int p;
	do
	{
		char st[MaxLen];
		cout << "������� ����� ��������:" << endl;
		cout << "1. ������ ����� �����" << endl;
		cout << "2. ������� ����� �� �����" << endl;
		cout << "3. �������� ������ � ����� � ������ ������" << endl;
		cout << "4. �������� ������ � ����� � ������ ������" << endl;
		cout << "5. �������� ������ � ����� � ������ ������ � ��������� ������ ������" << endl;
		cout << "6. �������� ������ � ����� � ������ ������ � ��������� ������ ������" << endl;
		cout << "7. ������� ������ �� ������ � ������ ������" << endl;
		cout << "8. ������� ������ �� ������ � ������ ������" << endl;
		cout << "9. ��������� �� ������" << endl;
		cout << "10. ������� ������ ��������� �������" << endl;
		cout << "11. ������ \"������\"" << endl;
		cout << "12. ��������� ����� � ����" << endl;
		cout << "13. ���������� ������" << endl;
		cin >> p;
		switch (p)
		{
		case 1: cout << "������� ��� ��������� � �������:" << endl;
			cin >> str;
			t.Load(str);
			break;

		case 2: t.PrintText();
			break;

		case 3: cout << "������� ������, ������� ������ ��������:" << endl;  
			cin >> st;
			t.InsNextLine(st);
			t.PrintText();
			break;

		case 4: cout << "������� ������, ������� ������ ��������:" << endl;
			cin >> st;
			t.InsDownLine(st);
			t.PrintText();
			break;

		case 5: cout << "������� ������, ������� ������ ��������:" << endl; 
			cin >> st;
			t.InsNextSection(st);
			t.PrintText();
			break;

		case 6: cout << "������� ������, ������� ������ ��������:" << endl;
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

		case 12: cout << "������� ��� ���������, � ������� ������ ��������� �����:" << endl;
			cin >> str;
			t.SaveText(str);
			break;

		case 13: break;

		default: cout << "������������ ����! ������� ����� �������� ������." << endl;
		}
		cout << endl;
	} while (p!=13);
	return 0;
}

