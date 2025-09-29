#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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













//-------------------------------------------------------------------
//-------------------------------------------------------------------

/*
 1.  从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删除的元素。空出的位置由最后一个元素填补，若顺序表为空，显示错误信息并退出运行

 //算法思想：
 遍历顺序表，找到最小元素在顺序表中的下标，然后用最后一个元素覆盖，最后顺序表长度减一
*/

bool DelMinValue(SeqList & L, ElemType &e)
{
	if (L.length == 0)
		return false;
	int index = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[index] > L.data[i])
			index = i;
	}
	e = L.data[index];
	L.data[index] = L.data[L.length - 1];
	L.length--;

	return true;
}


/*
* 2. 设计一个高效算法，将顺序表L的所有元素逆置， 要求算法的空间复杂度为 O(1)
* 
* //算法思想：
* 顺序扫描L的前半部分元素，对于L.data[i] (0 <= i <= L.length/2) 将其与后半部分元素 L.data[L.length -i -1]进行交换
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
* 
* //算法思想:
* 
*/

void Del_x(SeqList& L, ElemType x)
{
	int j = 0;
	for (int i = 0; i < L.length; i++)
	{
		
	}
}

/*
* 4. 给定一个顺序表，删除值在 s和t之间的所有元素（包括s和t, 且 s<t）,若s和t不合理或者顺序表为空，则显示错误信息并退出运行
*/


/*
* 5. 从有序顺序表中删除所有值重复的元素。使表中所有元素均不相同
* 
* //算法思想:
*/

void DelSameValue(SeqList& L)
{
	 
}

// 暴力解法
void BruteForce(SeqList& L)
{
	int pos = 0;
	for (int i = 1; i < L.length; i++)
	{
		if (L.data[i] != L.data[pos] && (i-pos)>1)
		{
			//向前移动 i-pos-1 个距离
			int offset = i - pos - 1;
			for (int j = i; j < L.length; j++)
			{
				L.data[j - offset] = L.data[j];
			}
		}
		pos = i; //更新pos的值
		L.length = L.length - (i - pos - 1);
	}
}

/*
* 6. 将两个有序顺序表合并成一个新的有序顺序表，并由函数返回这个顺序表
*/

/*
* 7. 一维数组A[m+n]中依次存放两个线性表(a1, a2, ,, am) (b1, b2,,,,,bn), 请将两个线性表的位置互换
* 
* 算法思想：
* 先将整个数组A逆转， 得到 (bn, bn-1, bn-2,,,,b1)(am, am-1, am-2,,,,a1)
* 再将b和a的部分分别逆转，得到(b1, b2, b3，，，，bn)(a1, a2, a3, ,,,am)
*/

void ExchangePosition(ElemType A[], int length, int m, int n)
{
	//先整体逆转
	for (int i = 0; i < length/2; i++)
	{
		ElemType temp = A[i];
		A[i] = A[length - i - 1];
		A[length - i - 1] = temp;
	}

	//再将b逆转
	for (int i = 0; i < n; i++)
	{
		ElemType temp = A[i];
		A[i] = A[n - i - 1];
		A[n - i - 1] = temp;
	}

	//再将a逆转
	for (int i = n; i < length; i++)
	{
		ElemType temp = A[i];
		A[i] = A[length - i - 1];
		A[length - i - 1] = temp;
	}
}

/*
* 8.  顺序表（a1, a2, a3, a4,,,an）中的元素递增有序，设计一个时间上高效的算法，在表中查找值为x的元素，若找到，则与其后继元素交换位置，
*		若找不到，则插入到顺序表中，使顺序表仍然递增有序
*/


/*
* 9. 给定无重复元素的三个序列A, B, C; 已知这三个序列长度均为N且有序递增， 请设计一个时间上高效的算法，找出这三个序列的交集,并逐行输出它们
*	例如 A(1, 2, 3); B(2, 5, 6); C(0, 2, 7);   ABC的交集为2.
*  
* //拓展：如何查找 n 个序列的交集并逐行输出它们
* 
* 
* //算法思想:
*/

void FindsameValue()
{

}



/*
* 13. 给定一个含n个整数的数组（n>=1）; 找出数组中未出现的最小正整数， 确保时间上尽可能高效
* 例如{-5， 3， 2， 3}中，未出现的最小正整数为1
* {1，2，3}中未出现的最小正整数为4
* 
* //算法思想：
* n个整数的数组，为出现的最小正整数的最小值为1，最大值为n+1;
*/


int FindMinPositiveNum(int Array[], int length)
{
	int* Temp = (int*)malloc(sizeof(int) * length);
	memset(Temp, 0, sizeof(int) * length);
	for (int i = 0; i < length; i++)
	{
		if (Array[i] <= length)
			Temp[Array[i]-1] = 1;
	}

	for (int i = 0; i < length; i++)
	{
		if (Temp[i] == 0)
			return i+1;
	}
	return length + 1;
}

/*
* 14. 三元组(a, b, c)
*/
