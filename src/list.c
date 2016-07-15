#include "list.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int initLIst(SeqList &L)
{
	L.data = (DataType*)malloc(sizeof(DataType) * INITSIZE);
	if(L.data == NULL)
	{
		printf("malloc error\n");
		return -1;
	}
	L.maxSize = INITSIZE;
	L.n = 0;

	return 0;
}

void clearList(SeqList &L)
{
	L.n = 0;
}

int Length(SeqList &L)
{
	return L.n;
}

int isFull(SeqList &L)
{
	return(L.n == L.maxSize)?1:0;
}

int isEmpty(SeqList &L)
{
	return(L.n == 0)?1:0;
}

int Search(SeqList &L, DataType x)
{
	for(int i = 0; i < L.n; i ++)
	{
		if(L.data == x)
			return i + 1;
	}

	return 0;
}

void Copy(SeqList &L1, SeqList &L2)
{
	L1.maxSize = L2.maxSize;
	L1.n = L2.n;
	if(!L1.data)
	{
		L1.data = (DataType *)malloc(sizeof(DataType) * L1.maxSize)
		if(L1.data == NULL)
		{
			printf("malloc error\n");
			return -1;
		}
	}
}















int main()
{
	printf("list.c\n");
	printf("list.c\n");
	return 0;
}