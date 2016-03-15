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
	void InsNextLine(char *_str);
	void InsNextSection(char *_str);
	void InsDownLine(char *_str);
	void InsDownSection(char *_str);
	void DelNextLine();
	void DelDownLine();
	string GetLine();
	void SetLine(string _str);

	void Reset();
	void GoNext();
	bool IsEnd();

	void Load(string f_name);
	void PrintText();
	void SaveText(string f_name);
};


#endif