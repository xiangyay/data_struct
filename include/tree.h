#ifndef TREE_H
#define TREE_H


typedef int  ElemType; //��������

//����������ṹ
typedef struct node{
	ElemType  data; //����
	struct node *lChild, *rChild; //��������
}BiTNode, *BiTree;

#endif
