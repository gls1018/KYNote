#include <stdio.h>
#include <stdlib.h>
// ˳���Ķ���

#define InitSize 100
#define ElemType int


typedef struct {
	ElemType* data;
	int MaxSize;
	int length;
} SeqList;


// ˳������ʵ��

//��ʼ��
void InitList(SeqList& L)
{
	L.data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
	L.length = 0;
	L.MaxSize = InitSize;
}

//�������
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

//ɾ������
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

// ��ֵ����
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
 1.  ��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�������ɺ������ر�ɾ����Ԫ�ء��ճ���λ�������һ��Ԫ�������˳���Ϊ�գ���ʾ������Ϣ���˳�����
*/


/*
* 2. ���һ����Ч�㷨����˳���L������Ԫ�����ã� Ҫ���㷨�Ŀռ临�Ӷ�Ϊ O(1)
* 
* //�㷨˼�룺
* ˳��ɨ��L��ǰ�벿��Ԫ�أ�����L.data[i] (0 <= i <= L.length/2) �������벿��Ԫ�� L.data[L.length -i -1]���н���
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
* 3. �Գ���Ϊn��˳���L, ��дһ��ʱ�临�Ӷ�Ϊ o(n),�ռ临�Ӷ�Ϊ o(1)���㷨�����㷨ɾ��˳���������ֵΪ x ������Ԫ��
*/

void Del_x(SeqList& L, ElemType x)
{
	int j = 0;
	for (int i = 0; i < L.length; i++)
	{
		
	}
}


/*
* 5. ������˳�����ɾ������ֵ�ظ���Ԫ�ء�ʹ��������Ԫ�ؾ�����ͬ
*/


/*
* 6. ����������˳���ϲ���һ���µ�����˳������ɺ����������˳���
*/

/*
* 7. һά����A[m+n]�����δ���������Ա�(a1, a2, ,, am) (b1, b2,,,,,bn), �뽫�������Ա��λ�û���
*/



/*
* 8
*/