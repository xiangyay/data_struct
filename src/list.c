#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTNCREMENT 10
typedef struct
{
    int *elem;
    int length;
    int listsize;
}Sqlist;
Sqlist InitSList();
void InsertSList(Sqlist L,int i,int e);
void DeleteSList(Sqlist L,int i);
void FindList(Sqlist L,int i);
void NiZhiList(Sqlist L);
/***************************������**********************/
void main()
{
    int i,m,e;
    Sqlist L;
    L=InitSList();
    printf("���������\n");
    scanf("%d",&L.length);
    printf("���е�Ԫ����:");
    for(i=0;i<L.length;i++)
        scanf("%d",&L.elem[i]);

	while(1)
	{
	    printf("��ѡ��:");
	    printf("\n");
	    printf("1:����Ԫ��:\n");
	    printf("2:ɾ��Ԫ��:\n");
	    printf("3:����Ԫ��:\n");
	    printf("4:˳�������:\n");	    
		scanf("%d",&m);
	    switch(m)
	    {
	    case 1:
	            printf("���������Ԫ�ص�λ��i:\n");
	            scanf("%d",&i);
	            printf("������������Ԫ��e:\n");
	            scanf("%d",&e);
	            InsertSList(L,i,e);
	            printf("�µ�˳����е�Ԫ����:\n");
	            for(i=0;i<L.length+1;i++)
	                printf("%d",L.elem[i]);
				printf("\n");
	            break;
	    case 2:
	            printf("������ɾ��Ԫ�ص�λ�ã�\n");
	            scanf("%d",&i);
	             DeleteSList(L,i);
	             printf("�µ�˳����е�Ԫ����:\n");
	             for(i=0;i<L.length-1;i++)
	                 printf("%d",L.elem[i]);
				 printf("\n");
	            break;
	    case 3:
	        printf("���������Ԫ�ص�λ��i:\n");
	        scanf("%d",&i);
	        FindList(L,i);
	        break;
	    case 4:
	        NiZhiList(L);
	        break;  
	    default:
	        printf("ERROR");
	    }
	}
}
/********************����˳���**********************/
Sqlist InitSList()
{
    Sqlist L;
    L.elem=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L.elem)exit(0);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return L;
}
/*************************ɾ��Ԫ��************************/
void DeleteSList(Sqlist L,int i)
{
    int *p,q;
    if((i<1)||(i>L.length))
        printf("ERROR");
    p=&(L.elem[i-1]);
    q=L.elem+L.length-1;
    for(++p;p<=q;++p)
        *(p-1)=*p;
    --L.length;
}
/*************************����Ԫ��**********************/
void InsertSList(Sqlist L,int i,int e)
{
    int*newbase;
    int *q,*p;
    if(i<1||i>L.length+1)
        printf("error");
    if(L.length>=L.listsize)
    {
        newbase=(int*)realloc(L.elem,(L.listsize+LISTNCREMENT)*sizeof(int));
        if(!newbase)exit(0);
        L.elem=newbase;
        L.listsize+=LISTNCREMENT;
    }
    q=&(L.elem[i-1]);
    for(p=&(L.elem[L.length-1]);p>=q;--p)
        *(p+1)=*p;
    *q=e;
    ++L.length;
}
/********************����Ԫ��**************************/
void FindList(Sqlist L,int i)
{
    int *p,e;
    printf("���������Ԫ�ص�λ��:\n");
    scanf("%d",&i);
    p=&(L.elem[i-1]);
    e=*p;
    printf("�������λ�õ�Ԫ��:\n");
    printf("%d",e);
}
/************************˳�������***********************/
void NiZhiList (Sqlist L)
{
    int *s,i;
    for(i=0;i<L.length/2;i++)
    {
        s=L.elem[i];
        L.elem[i]=L.elem[L.length-i-1];
        L.elem[L.length-i-1]=s;
    }
    printf("�µ�˳����е�Ԫ����:\n");
    for(i=0;i<L.length;i++)
        printf("%d",L.elem[i]);
	printf("\n");
}

