#ifndef _T_TEXT_H_
#define _T_TEXT_H_

#define _CRT_SECURE_NO_WARNINGS

#include "TLink.h"
#include "T_Stack.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class TLink;

class TText
{
private:
	TLink *pFirst, *pCurr;
	T_Stack <TLink*> path;

	TLink* ReadSection(ifstream& ifs);  
	void PrintSection(TLink *ptemp);        
	void SaveSection(TLink *ptemp, ofstream& ofs);

public:
	TText(TLink *p=NULL);
	~TText() {};

	void GoNextLink();
	void GoDownLink();
	void GoPrevLink();
	void GoFirstLink();
	void InsNextLine(char *_str);  //вставить строку после данной
	void InsNextSection(char *_str);  //вставить строку после данной - следующие строки вложить в новую
	void InsDownLine(char *_str);  //вставить строку под данной строкой
	void InsDownSection(char *_str);  //вставить строку под данной - следующие строки вложить в новую
	void DelNextLine();  //удалить следующую строку
	void DelDownLine();  //удалить нижнюю строку
	string GetLine();
	void SetLine(string _str);

	void Reset();
	void GoNext();
	bool IsEnd();

	void Load(string f_name);  //загрузить новый текст
	void PrintText();  //напечатать текст
	void SaveText(string f_name);  //сохранить текст в файл
};


#endif