#ifndef _TLINK_H_
#define _TLINK_H_

#include <string>
using namespace std;

const int MaxLen=81;

class TLink
{
public:
	char str[MaxLen];
	TLink *pNext;
	TLink *pDown;

	TLink(const char *_str=NULL, TLink *_pNext=NULL, TLink *_pDown=NULL);
	~TLink() {};
};

#endif