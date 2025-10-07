#include <iostream>

#define ElemType int

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;





void PreOrder(BiTree T)
{
	if (T == NULL)
		return;
	std::cout << T->data << " ";
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}

int main()
{

}