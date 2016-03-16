#ifndef _TLINK_H_
#define _TLINK_H_

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "TText.h"
#include <iostream>
using namespace std;

const int MaxLen = 181;

class TLink;
class TText;
struct TTextMem
{
	TLink *pFirst, *pLast, *pFree;
};

class TLink
{
public:
	char str[MaxLen];
	TLink *pNext;
	TLink *pDown;
	static TTextMem TextMem;

	TLink(const char *_str = NULL, TLink *_pNext = NULL, TLink *_pDown = NULL);
	~TLink() {};

	void* operator new(size_t size);
	void operator delete(void* p);
	static void InitMem(int size);
	static void MemClean(TText &txt);
	static void PrintFree();
};


#endif