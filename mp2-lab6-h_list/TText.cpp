#include "TText.h"

TText::TText(TLink *p)
{
	if (p==NULL)
	{
		TLink *tmp=new TLink;
		pFirst=tmp;
	}
	else pFirst=p;
}

void TText::GoNextLink()
{
	if (pCurr!=NULL)
		if (pCurr->pNext!=NULL)
		{
			path.Push(pCurr);
			pCurr=pCurr->pNext;
		}
}

void TText::GoDownLink()
{
	if (pCurr!=NULL)
		if (pCurr->pDown!=NULL)
		{
			path.Push(pCurr);
			pCurr=pCurr->pDown;
		}
}

void TText::GoPrevLink()
{
	if (!path.Empty())
		pCurr=path.Pop();
}

void TText::GoFirstLink()
{
	while (!path.Empty())
		path.Pop();
	pCurr=pFirst;
}

void TText::InsNextLine(char *_str)
{
	if(pCurr!=NULL)
	{
		TLink *tmp=new TLink(_str);
	    tmp->pNext=pCurr->pNext;
	    pCurr->pNext=tmp;
	}
}

void TText::InsNextSection(char *_str)
{
	if(pCurr!=NULL)
	{
		TLink *tmp=new TLink(_str);
	    tmp->pDown=pCurr->pNext;
	    pCurr->pDown=tmp;
	}
}

void TText::InsDownLine(char*_str)
{
	if(pCurr!=NULL)
	{
		TLink *tmp=new TLink(_str);
	    tmp->pNext=pCurr->pDown;
	    pCurr->pDown=tmp;
	}
}

void TText::InsDownSection(char *_str)
{
	if(pCurr!=NULL)
	{
		TLink *tmp=new TLink(_str);
	    tmp->pDown=pCurr->pDown;
	    pCurr->pDown=tmp;
	}
}

void TText::DelNextLine()
{
	if(pCurr!=NULL)
		if (pCurr->pNext!=NULL)
		{
			TLink *tmp=pCurr->pNext;
			pCurr->pNext=pCurr->pNext->pNext;
			delete tmp;
		}
}

void TText::DelDownLine()
{
	if(pCurr!=NULL)
		if(pCurr->pDown!=NULL)
		{
			TLink *tmp=pCurr->pDown;
			pCurr->pDown=pCurr->pDown->pNext;
			delete tmp;
		}
}

void TText::GetLine(char *_str)
{
	if(pCurr!=NULL)
		strcpy(_str,pCurr->str);
}

void TText::SetLine(char *_str)
{
	if(pCurr!=NULL)
		strcpy(pCurr->str,_str);
}

void TText::Reset()
{
	path.Clear;
	pCurr=pFirst;
	if(pCurr!=NULL)
	{
		if(pCurr->pNext!=NULL)
			path.Push(pCurr->pNext);
		if(pCurr->pDown!=NULL)
			path.Push(pCurr->pDown);
	}
}

void TText::GoNext()
{
	if(!path.Empty())
	{
		pCurr=path.Pop();
		if(pCurr->pNext!=NULL)
			path.Push(pCurr->pNext);
		if(pCurr->pDown!=NULL)
			path.Push(pCurr->pDown);
	}
}

bool TText::IsEnd() {return path.Empty();}