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
	char p;
	do
	{
		cout << "�������� ����� ��������:" << endl;
		cout << "1. ������ ����� �����" << endl;
		cout << "2. ������� ����� �� �����" << endl;
		cout << "3. �������� ������ � �����" << endl;
		cout << "4. ������� ������ �� ������" << endl;
		cout << "5. ������� ������ ��������� �������" << endl;
		cout << "6. ������ \"������\"" << endl;
		cout << "7. ��������� ����� � ����" << endl;
		cout << "8. ���������� ������" << endl;
		cin >> p;
		switch (p)
		{
		case '1': cout << "������� ��� ��������� � �������:" << endl;
			cin >> str;
			t.Load(str);
			break;
		case '2': t.PrintText();
			break;
		case '3': cout << "�������� ��������� � ������ ����������" << endl;
			break;
		case '4': cout << "�������� ��������� � ������ ����������" << endl;
			break;
		case '5': TLink::PrintFree();
			break;
		case '6': TLink::MemClean(t);
			break;
		case '7': cout << "������� ��� ���������, � ������� ������ ��������� �����:" << endl;
			cin >> str;
			t.SaveText(str);
			break;
		case '8': break;
		default: cout << "������������ ����! ������� ����� �������� ������." << endl;
		}
	} while (p!='8');
	return 0;
}

