#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



// 单链表定义
#define ElemType int
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
} LNode, *LinkList;



//单链表的初始化
bool InitList(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
}



//求表长操作
int Length(LinkList L)
{
	int len = 0;
	LNode* temp = L;

	while (temp->next != NULL)
	{
		len++;
		temp = temp->next;
	}
	return len;
}

//按序号查找节点
//返回第i个节点的指针
LNode* GetElem(LinkList L, int i)
{
	LNode* p = L;
	int j = 0;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

//按值查找节点
LNode* LocateElem(LinkList L, ElemType e)
{
	LNode* p = L->next;
	while (p != NULL)
	{
		if (p->data == e)
			break;
		p = p->next;
	}
	return p;
}


//插入节点操作
bool ListInsert(LinkList& L, int pos, ElemType e)
{
	if (L == NULL && pos < 1)
		return false;
	
	LNode* p = L;
	int i = 0;
	while (p != NULL && i < pos - 1)
	{
		p = p->next;
		i++;
	}

	if (p == NULL) 
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}

//删除节点操作
