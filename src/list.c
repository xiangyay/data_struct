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

















int main()
{
	printf("list.c\n");
	printf("list.c\n");
	return 0;
}