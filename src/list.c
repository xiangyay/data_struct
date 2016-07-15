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
/***************************主函数**********************/
void main()
{
    int i,m,e;
    Sqlist L;
    L=InitSList();
    printf("请输入表长：\n");
    scanf("%d",&L.length);
    printf("表中的元素是:");
    for(i=0;i<L.length;i++)
        scanf("%d",&L.elem[i]);

	while(1)
	{
	    printf("请选择:");
	    printf("\n");
	    printf("1:插入元素:\n");
	    printf("2:删除元素:\n");
	    printf("3:查找元素:\n");
	    printf("4:顺序表逆置:\n");	    
		scanf("%d",&m);
	    switch(m)
	    {
	    case 1:
	            printf("请输入插入元素的位置i:\n");
	            scanf("%d",&i);
	            printf("请输入插入的新元素e:\n");
	            scanf("%d",&e);
	            InsertSList(L,i,e);
	            printf("新的顺序表中的元素是:\n");
	            for(i=0;i<L.length+1;i++)
	                printf("%d",L.elem[i]);
				printf("\n");
	            break;
	    case 2:
	            printf("请输入删除元素的位置：\n");
	            scanf("%d",&i);
	             DeleteSList(L,i);
	             printf("新的顺序表中的元素是:\n");
	             for(i=0;i<L.length-1;i++)
	                 printf("%d",L.elem[i]);
				 printf("\n");
	            break;
	    case 3:
	        printf("请输入查找元素的位置i:\n");
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
/********************创建顺序表**********************/
Sqlist InitSList()
{
    Sqlist L;
    L.elem=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L.elem)exit(0);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return L;
}
/*************************删除元素************************/
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
/*************************插入元素**********************/
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
/********************查找元素**************************/
void FindList(Sqlist L,int i)
{
    int *p,e;
    printf("请输入查找元素的位置:\n");
    scanf("%d",&i);
    p=&(L.elem[i-1]);
    e=*p;
    printf("请输出该位置的元素:\n");
    printf("%d",e);
}
/************************顺序表逆置***********************/
void NiZhiList (Sqlist L)
{
    int *s,i;
    for(i=0;i<L.length/2;i++)
    {
        s=L.elem[i];
        L.elem[i]=L.elem[L.length-i-1];
        L.elem[L.length-i-1]=s;
    }
    printf("新的顺序表中的元素是:\n");
    for(i=0;i<L.length;i++)
        printf("%d",L.elem[i]);
	printf("\n");
}

