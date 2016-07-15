#ifndef LIST_H
#define LIST_H

#define MAXSIZE 100
#define INITSIZE 100



typedef int DataType;

typedef struct{
	DataType data[MAXSIZE];
	int n,maxSize;
}SeqList;


#endif
