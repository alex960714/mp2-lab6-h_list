#ifndef _T_TEXT_H_
#define _T_TEXT_H_

#include "TLink.h"
#include "T_Stack.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class TText
{
private:
	TLink *pFirst, *pCurr;
	T_Stack <TLink*> path;

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
	void GetLine(char *_str);
	void SetLine(char *_str);

	void Reset();
	void GoNext();
	bool IsEnd();
};


#endif