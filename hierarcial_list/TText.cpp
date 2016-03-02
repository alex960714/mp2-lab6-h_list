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
	if (pCurr!=NULL)
	if (!path.IsEmpty())
		pCurr=path.Pop();
}

void TText::GoFirstLink()
{
	if (pCurr!=NULL)
	while (!path.IsEmpty())
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
	if(!path.IsEmpty())
	{
		pCurr=path.Pop();
		if(pCurr->pNext!=NULL)
			path.Push(pCurr->pNext);
		if(pCurr->pDown!=NULL)
			path.Push(pCurr->pDown);
	}
}

bool TText::IsEnd() {return path.IsEmpty();}

TLink* TText::ReadSection(ifstream& ifs)
{
	string _str;
	TLink *pHead, *ptemp;
	pHead = new TLink;
	ptemp = pHead;
	while (!ifs.eof())
	{
		getline(ifs, _str);
		if (_str[0] == '}')
			break;
		if (_str[0] == '{')
			ptemp->pDown = ReadSection(ifs);
		else
		{
			TLink *p = new TLink(_str.c_str());
			ptemp->pNext = p;
			ptemp = p;
		}
	}
	if (pHead->pDown == NULL)
	{
		ptemp = pHead->pNext;
		delete pHead;
		pHead = ptemp;
	}
	return pHead;
}

void TText::Load(string f_name)
{
	ifstream ifs(f_name);
	pFirst = ReadSection(ifs);
}

void TText::PrintSection(TLink *ptemp)
{
	if (ptemp != NULL)
	{
		cout << ptemp->str << endl;
		if (ptemp->pDown != NULL)
		{
			cout << '{' << endl;
			PrintSection(ptemp->pDown);
			cout << '}' << endl;
		}
		PrintSection(ptemp->pNext);
	}
}

void TText::PrintText() { PrintSection(pFirst); }

void TText::SaveSection(TLink *ptemp, ofstream& ofs)
{
	if (ptemp != NULL)
	{
		ofs << ptemp->str << endl;
		if (ptemp->pDown != NULL)
		{
			ofs << '{' << endl;
			SaveSection(ptemp->pDown);
			ofs << '}' << endl;
		}
		SaveSection(ptemp->pNext);
	}
}

void TText::SaveText(string f_name)
{
	ofstream ofs(f_name);
	SaveSection(pFirst, ofs);
}