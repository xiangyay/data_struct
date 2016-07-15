#ifndef TREE_H
#define TREE_H


typedef int  ElemType; //数据类型

//定义二叉树结构
typedef struct node{
	ElemType  data; //数据
	struct node *lChild, *rChild; //左右子树
}BiTNode, *BiTree;

#endif
