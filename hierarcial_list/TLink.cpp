#include "TLink.h"

TLink::TLink(const char *_str, TLink *_pNext, TLink *_pDown)
{
	pNext=_pNext;
	pDown=_pDown;
	if(_str!=NULL)
		strcpy_s(str,_str);
	else str[0]='\0';
}