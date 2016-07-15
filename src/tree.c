#include <list.h>
#include <tree.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int count = 0;

//���򴴽�������
int CreateBiTree(BiTree *T)
{
	ElemType ch;
	ElemType temp;

	scanf("%d", &ch);
	temp = getchar();

	if (ch == 0)
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!(*T))
		{
			printf("malloc error\n");
			return -1;
		}
		(*T)->data = ch;
		printf("Input %d left  child: ", ch);
		CreateBiTree(&(*T)->lChild);
		printf("Input %d right child: ", ch);
		CreateBiTree(&(*T)->rChild);
	}
	return 1;
}

//�������������
void TraverseBiTree(BiTree T)
{
	if (T == NULL)
		return ;
	printf("%d ", T->data);
	TraverseBiTree(T->lChild);
	TraverseBiTree(T->rChild);
}

//�������ǵݹ��������

//�������������
void InOrderBiTree(BiTree T)
{
	if (T == NULL)
		return ;
	InOrderBiTree(T->lChild);
	printf("%d ", T->data);
	InOrderBiTree(T->rChild);
}

//�������������
void PostOrderBiTree(BiTree T)
{
	if (T == NULL)
		return ;
	PostOrderBiTree(T->lChild);
	PostOrderBiTree(T->rChild);
	printf("%d ", T->data);
}

//�����������
int TreeDeep(BiTree T)
{
	int dep = 0;
	if(T)
	{
		int leftdep = TreeDeep(T->lChild);
		int rightdep = TreeDeep(T->rChild);
		dep = leftdep>=rightdep?leftdep+1:rightdep+1;
	}
	return dep;
}

//�������Ҷ�ӽ�����
int Leafcount(BiTree T)
{
	if(T)
	{
		if(T->lChild ==NULL && T->rChild==NULL)
			count++;
		Leafcount(T->lChild);
		Leafcount(T->rChild);
	}
	return count;
}

//�Թ�������ʽ���������
void printBinTree(BiTree T)
{
	if(T != NULL)
	{
		printf("%d",T->data);
		if(T->lChild != NULL || T->rChild != NULL)
		{
			printf("(");
			if(T->lChild != NULL)
			{
				printBinTree(T->lChild);
			}
			if(T->lChild != NULL || T->rChild != NULL)
			{
				printf(",");
			}
			if(T->rChild != NULL)
			{
				printBinTree(T->rChild);
			}
			printf(")");
		}
	}
}

//����һ��������
void clearBiTree(BiTree T)
{
	if(T != NULL)
	{
		clearBiTree(T->lChild);
		clearBiTree(T->rChild);
		free(T);
		T = NULL;
	}
}

//������
int main(void)
{
	BiTree T;
	int deepth,num = 0;
	
	BiTree *p = (BiTree*)malloc(sizeof(BiTree));

	printf("�������һ������ֵ,0��ʾû��Ҷ���:\n");
	CreateBiTree(&T);
	
	printf("�������������:\n");
	TraverseBiTree(T);
	printf("\n");
	
	printf("�������������:\n");
	InOrderBiTree(T);
	printf("\n");
	
	printf("�������������:\n");
	PostOrderBiTree(T);
	printf("\n");
	
	deepth = TreeDeep(T);
	printf("�������Ϊ:%d",deepth);
	printf("\n");
	
	num = Leafcount(T);
	printf("����Ҷ�ӽ�����Ϊ:%d",num);
	printf("\n");
	
	printf("�Թ�������ʽ���������");
	printBinTree(T);
	printf("\n");
	
	//���ٶ�����
	clearBiTree(T);
	
	return 0;
}