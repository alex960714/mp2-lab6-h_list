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
		int p1;
		int i = 1;
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
		cout << "9. ������� ������ ��������� �������" << endl;
		cout << "10. ������ \"������\"" << endl;
		cout << "11. ��������� ����� � ����" << endl;
		cout << "12. ���������� ������" << endl;
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
			cout << "������� ����� ������, ����� ������� ������ �������� ����� ������:" << endl;
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
					cout << "����� ������ �� ����������!" << endl;
				i++;
			}
			break;
		case 4: cout << "������� ������, ������� ������ ��������:" << endl;
			cin >> st;
			cout << "������� ����� ������, ����� ������� ������ �������� ����� ������:" << endl;
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
					cout << "����� ������ �� ����������!" << endl;
				i++;
			}
			break;
		case 5: cout << "������� ������, ������� ������ ��������:" << endl; //���������
			cin >> st;
			cout << "������� ����� ������, ����� ������� ������ �������� ����� ������:" << endl;
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
					cout << "����� ������ �� ����������!" << endl;
				i++;
			}
			break;
		case 6: cout << "������� ������, ������� ������ ��������:" << endl;
			cin >> st;
			cout << "������� ����� ������, ����� ������� ������ �������� ����� ������:" << endl;
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
					cout << "����� ������ �� ����������!" << endl;
				i++;
			}
			break;
		case 7: cout << "������� ����� ������, ������� ������ �������:" << endl;  
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
					cout << "����� ������ �� ����������!" << endl;
				i++;
			}
			break;
		case 8: cout << "������� ����� ������, ������� ������ �������:" << endl;  //���������
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
					cout << "����� ������ �� ����������!" << endl;
				i++;
			}
			break;
		case 9: TLink::PrintFree();
			break;
		case 10: TLink::MemClean(t);  
			break;
		case 11: cout << "������� ��� ���������, � ������� ������ ��������� �����:" << endl;
			cin >> str;
			t.SaveText(str);
			break;
		case 12: break;
		default: cout << "������������ ����! ������� ����� �������� ������." << endl;
		}
		cout << endl;
	} while (p!=12);
	return 0;
}

