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

void LoadLine();
string str;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");
	TLink::InitMem(100);
	TText t;
	cout << "������� ��� ��������� � �������:" << endl;
	cin >> str;
	t.Load(str);
	int p;
	do
	{
		//char st[MaxLen];
		//string buffer;
		cout << "������� ����� ��������:" << endl;
		cout << "1. ������ ����� �����" << endl;
		cout << "2. ������� ����� �� �����" << endl;
		cout << "3. �������� ������ � ����� � ������ ������" << endl;
		cout << "4. �������� ������ � ����� � ������ ������" << endl;
		cout << "5. �������� ������ � ����� � ������ ������ � ��������� ������ ������" << endl;
		cout << "6. �������� ������ � ����� � ������ ������ � ��������� ������ ������" << endl;
		cout << "7. ������� ������ �� ������ � ������ ������" << endl;
		cout << "8. ������� ������ �� ������ � ������ ������" << endl;
		cout << "9. ������� ������ ������" << endl;
		cout << "10. ������������� ������ ������" << endl;
		cout << "11. ��������� �� ������" << endl;
		cout << "12. ������� ������ ��������� �������" << endl;
		cout << "13. ������ \"������\"" << endl;
		cout << "14. ��������� ����� � ����" << endl;
		cout << "15. ���������� ������" << endl;
		cin >> p;
		switch (p)
		{
		case 1: cout << "������� ��� ��������� � �������:" << endl;
			cin.get();
			getline(cin, str);
			t.Load(str);
			break;

		case 2: t.PrintText();
			break;

		case 3: LoadLine();
			t.InsNextLine(str);
			t.PrintText();
			break;

		case 4: LoadLine();
			t.InsDownLine(str);
			t.PrintText();
			break;

		case 5: LoadLine();
			t.InsNextSection(str);
			t.PrintText();
			break;

		case 6: LoadLine();
			t.InsDownSection(str);
			t.PrintText();
			break;

		case 7:	t.DelNextLine();
			t.PrintText();
			break;

		case 8: t.DelDownLine();
			t.PrintText();
			break;

		case 9: cout << "������ ������:" << endl;
			cout << t.GetLine() << endl;
			break;

		case 10: LoadLine();
			t.SetLine(str);
			break;

		case 11: t.Navigation();
			break;

		case 12: TLink::PrintFree();
			break;

		case 13: TLink::MemClean(t);  
			break;

		case 14: cout << "������� ��� ���������, � ������� ������ ��������� �����:" << endl;
			cin.get();
			getline(cin, str);
			t.SaveText(str);
			break;

		case 15: break;

		default: cout << "������������ ����! ������� ����� �������� ������." << endl;
		}
		cout << endl;
	} while (p!=15);
	return 0;
}

void LoadLine()
{
	cout << "������� �����, ������� ������ ��������:" << endl;
	cin.get();
	getline(cin, str);
}