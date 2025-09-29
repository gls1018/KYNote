#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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













//-------------------------------------------------------------------
//-------------------------------------------------------------------

/*
 1.  ��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�������ɺ������ر�ɾ����Ԫ�ء��ճ���λ�������һ��Ԫ�������˳���Ϊ�գ���ʾ������Ϣ���˳�����

 //�㷨˼�룺
 ����˳����ҵ���СԪ����˳����е��±꣬Ȼ�������һ��Ԫ�ظ��ǣ����˳����ȼ�һ
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
* 2. ���һ����Ч�㷨����˳���L������Ԫ�����ã� Ҫ���㷨�Ŀռ临�Ӷ�Ϊ O(1)
* 
* //�㷨˼�룺
* ˳��ɨ��L��ǰ�벿��Ԫ�أ�����L.data[i] (0 <= i <= L.length/2) �������벿��Ԫ�� L.data[L.length -i -1]���н���
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
* 
* //�㷨˼��:
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
* 4. ����һ��˳���ɾ��ֵ�� s��t֮�������Ԫ�أ�����s��t, �� s<t��,��s��t���������˳���Ϊ�գ�����ʾ������Ϣ���˳�����
*/


/*
* 5. ������˳�����ɾ������ֵ�ظ���Ԫ�ء�ʹ��������Ԫ�ؾ�����ͬ
* 
* //�㷨˼��:
*/

void DelSameValue(SeqList& L)
{
	 
}

// �����ⷨ
void BruteForce(SeqList& L)
{
	int pos = 0;
	for (int i = 1; i < L.length; i++)
	{
		if (L.data[i] != L.data[pos] && (i-pos)>1)
		{
			//��ǰ�ƶ� i-pos-1 ������
			int offset = i - pos - 1;
			for (int j = i; j < L.length; j++)
			{
				L.data[j - offset] = L.data[j];
			}
		}
		pos = i; //����pos��ֵ
		L.length = L.length - (i - pos - 1);
	}
}

/*
* 6. ����������˳���ϲ���һ���µ�����˳������ɺ����������˳���
*/

/*
* 7. һά����A[m+n]�����δ���������Ա�(a1, a2, ,, am) (b1, b2,,,,,bn), �뽫�������Ա��λ�û���
* 
* �㷨˼�룺
* �Ƚ���������A��ת�� �õ� (bn, bn-1, bn-2,,,,b1)(am, am-1, am-2,,,,a1)
* �ٽ�b��a�Ĳ��ֱַ���ת���õ�(b1, b2, b3��������bn)(a1, a2, a3, ,,,am)
*/

void ExchangePosition(ElemType A[], int length, int m, int n)
{
	//��������ת
	for (int i = 0; i < length/2; i++)
	{
		ElemType temp = A[i];
		A[i] = A[length - i - 1];
		A[length - i - 1] = temp;
	}

	//�ٽ�b��ת
	for (int i = 0; i < n; i++)
	{
		ElemType temp = A[i];
		A[i] = A[n - i - 1];
		A[n - i - 1] = temp;
	}

	//�ٽ�a��ת
	for (int i = n; i < length; i++)
	{
		ElemType temp = A[i];
		A[i] = A[length - i - 1];
		A[length - i - 1] = temp;
	}
}

/*
* 8.  ˳���a1, a2, a3, a4,,,an���е�Ԫ�ص����������һ��ʱ���ϸ�Ч���㷨���ڱ��в���ֵΪx��Ԫ�أ����ҵ�����������Ԫ�ؽ���λ�ã�
*		���Ҳ���������뵽˳����У�ʹ˳�����Ȼ��������
*/


/*
* 9. �������ظ�Ԫ�ص���������A, B, C; ��֪���������г��Ⱦ�ΪN����������� �����һ��ʱ���ϸ�Ч���㷨���ҳ����������еĽ���,�������������
*	���� A(1, 2, 3); B(2, 5, 6); C(0, 2, 7);   ABC�Ľ���Ϊ2.
*  
* //��չ����β��� n �����еĽ����������������
* 
* 
* //�㷨˼��:
*/

void FindsameValue()
{

}



/*
* 13. ����һ����n�����������飨n>=1��; �ҳ�������δ���ֵ���С�������� ȷ��ʱ���Ͼ����ܸ�Ч
* ����{-5�� 3�� 2�� 3}�У�δ���ֵ���С������Ϊ1
* {1��2��3}��δ���ֵ���С������Ϊ4
* 
* //�㷨˼�룺
* n�����������飬Ϊ���ֵ���С����������СֵΪ1�����ֵΪn+1;
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
* 14. ��Ԫ��(a, b, c)
*/
