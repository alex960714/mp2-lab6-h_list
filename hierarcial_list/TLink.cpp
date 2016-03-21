#include "TLink.h"

TLink::TLink(const char *_str, TLink *_pNext, TLink *_pDown)
{
	pNext=_pNext;
	pDown=_pDown;
	if(_str!=NULL)
		strcpy_s(str,_str);
	else str[0]='\0';
}

void* TLink::operator new(size_t size)
{
	TLink *tmp = TextMem.pFree;
if (TextMem.pFree != NULL)
TextMem.pFree = TextMem.pFree->pNext;
return tmp;
}

void TLink::operator delete(void* p)
{
	TLink *tmp = (TLink*)p;
	tmp->pNext = TextMem.pFree;
	TextMem.pFree = tmp;
	tmp->pDown = NULL;
}

void TLink::InitMem(int size)
{
	TextMem.pFirst = (TLink*) new char[size*sizeof(TLink)];
	TextMem.pFree = TextMem.pFirst;
	TextMem.pLast = TextMem.pFirst + (size - 1);
	TLink *tmp = TextMem.pFirst;
	for (int i = 0; i < size - 1; i++)
	{
		tmp->pNext = tmp + 1;
		tmp = tmp + 1;
	}
	tmp->pNext = NULL;
}

void TLink::MemClean(TText &txt)
{
	for (txt.Reset(); !txt.IsEnd(); txt.GoNext())
	{
		string tmp = "+++";
		tmp += txt.GetLine();
		txt.SetLine(tmp.c_str());
	}
	string tmp_s = "+++";
	tmp_s += txt.GetLine();
	txt.SetLine(tmp_s.c_str());
	TLink *tmp = TextMem.pFree;
	while (tmp != NULL)
	{
		for (int i = 0; i < 3; i++)
			tmp->str[i] = '+';
		tmp->str[3] = '\0';
		tmp = tmp->pNext;
	}
	tmp = TextMem.pFirst;
	while (true)
	{
		if ((tmp->str[0] == '+') && (tmp->str[1] == '+') && (tmp->str[2] == '+'))
			strcpy(tmp->str, tmp->str + 3);
		else
			delete tmp;
		if (tmp == TextMem.pLast)
			break;
		tmp = tmp + 1;
	}
}

void TLink::PrintFree()
{
	setlocale(LC_CTYPE, "Russian");
	TLink *tmp = TextMem.pFree;
	if (tmp == NULL)
		cout << "Нет свободных звеньев" << endl;
	else
	{
		cout << "Список свободных звеньев:" << endl;
		while (tmp != NULL)
		{
			int i = 0;
			TLink *t = TextMem.pFirst;
			while (t != tmp)
			{
				t = t + 1;
				i++;
			}
			cout << i << " ";
			tmp = tmp->pNext;
		}
		cout << endl;
	}
}