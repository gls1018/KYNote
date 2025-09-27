#include <stdio.h>
#include <stdlib.h>
// 顺序表的定义

#define InitSize 100
#define ElemType int


typedef struct {
	ElemType* data;
	int MaxSize;
	int length;
} SeqList;


// 顺序表基本实现

//初始化
void InitList(SeqList& L)
{
	L.data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
	L.length = 0;
	L.MaxSize = InitSize;
}

//插入操作
bool ListInsert(SeqList& L, int i, ElemType e)
{
	if (i <= 0 || i > L.length + 1)
		return false;
	if (L.length >= L.MaxSize)
		return false;

	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//删除操作
static bool ListDelete(SeqList& L, int i, ElemType& e)
{
	if (i > L.length || i <= 0)
		return false;

	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}

	L.length--;
	return true;
}

// 按值查找
int LocateElem(SeqList L, ElemType e)
{
	
	for (int i = 0; i < L.length; i++)
	{
		if (e == L.data[i])
			return i + 1;
	}

	return 0;
}


/*
 1.  从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删除的元素。空出的位置由最后一个元素填补，若顺序表为空，显示错误信息并退出运行
*/


/*
* 2. 设计一个高效算法，将顺序表L的所有元素逆置， 要求算法的空间复杂度为 O(1)
* 
* //算法思想：
* 顺序扫描L的前半部分元素，对于L.data[i] (0 <= i <= L.length/2) 将其与后半部分元素 L.data[L.length -i -1]进行交换
* 
*/

void ReverseSeqList(SeqList &L)
{
	for (int i = 0; i < L.length / 2; i++)
	{
		ElemType temp;
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}


/*
* 3. 对长度为n的顺序表L, 编写一个时间复杂度为 o(n),空间复杂度为 o(1)的算法，该算法删除顺序表中所有值为 x 的数据元素
*/

void Del_x(SeqList& L, ElemType x)
{
	int j = 0;
	for (int i = 0; i < L.length; i++)
	{
		
	}
}


/*
* 5. 从有序顺序表中删除所有值重复的元素。使表中所有元素均不相同
*/


/*
* 6. 将两个有序顺序表合并成一个新的有序顺序表，并由函数返回这个顺序表
*/

/*
* 7. 一维数组A[m+n]中依次存放两个线性表(a1, a2, ,, am) (b1, b2,,,,,bn), 请将两个线性表的位置互换
*/



/*
* 8
*/