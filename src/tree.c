#include <list.h>
#include <tree.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int count = 0;

//先序创建二叉树
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

//先序遍历二叉树
void TraverseBiTree(BiTree T)
{
	if (T == NULL)
		return ;
	printf("%d ", T->data);
	TraverseBiTree(T->lChild);
	TraverseBiTree(T->rChild);
}

//二叉树非递归先序遍历

//中序遍历二叉树
void InOrderBiTree(BiTree T)
{
	if (T == NULL)
		return ;
	InOrderBiTree(T->lChild);
	printf("%d ", T->data);
	InOrderBiTree(T->rChild);
}

//后序遍历二叉树
void PostOrderBiTree(BiTree T)
{
	if (T == NULL)
		return ;
	PostOrderBiTree(T->lChild);
	PostOrderBiTree(T->rChild);
	printf("%d ", T->data);
}

//二叉树的深度
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

//求二叉树叶子结点个数
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

//以广义表的形式输出二叉树
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

//销毁一个二叉树
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

//主函数
int main(void)
{
	BiTree T;
	int deepth,num = 0;
	
	BiTree *p = (BiTree*)malloc(sizeof(BiTree));

	printf("请输入第一个结点的值,0表示没有叶结点:\n");
	CreateBiTree(&T);
	
	printf("先序遍历二叉树:\n");
	TraverseBiTree(T);
	printf("\n");
	
	printf("中序遍历二叉树:\n");
	InOrderBiTree(T);
	printf("\n");
	
	printf("后序遍历二叉树:\n");
	PostOrderBiTree(T);
	printf("\n");
	
	deepth = TreeDeep(T);
	printf("树的深度为:%d",deepth);
	printf("\n");
	
	num = Leafcount(T);
	printf("树的叶子结点个数为:%d",num);
	printf("\n");
	
	printf("以广义表的形式输出二叉树");
	printBinTree(T);
	printf("\n");
	
	//销毁二叉树
	clearBiTree(T);
	
	return 0;
}