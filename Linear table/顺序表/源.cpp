#include<iostream>
using namespace std;

#define MAXSIZE 5
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;
//���Ͷ��壬����һ����ΪMAXSZIE���鳤�ȵ�����ռ䣬�Լ�length��ʾ����

Status InitList(SqList &L)
{
	L.length = 0;
	return true;
}
//��ʼ��������dataΪ��̬���䣬�����жϣ�data��ֱ�ӽ�����Ϊ0���ɳ�ʼ��

Status SqCreateList(SqList& L, ElemType x)
{
	if (L.length == MAXSIZE)
		return false;
	L.data[L.length] = x;
	L.length++;
	return true;
}
//��˳�����Ԫ�أ���ֵ��Ҫ��+1
//��ջ�Ĳ����������(�ǿ�ʱlengthָ��ʼ��ָ���βԪ����һ��λ��)

Status InsertList(SqList& L, ElemType x, int i)
{
	if (L.length == MAXSIZE)
		return false;
	if (i<1 || i>L.length)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = x;
	L.length++;
	return true;
}
//��λ����Ԫ�أ�˳�������������Ҫ����������Ԫ�غ���һ��λ�ò���+1

Status DeleteList(SqList& L, ElemType& x, int i)
{
	if (L.length == 0)
		return false;
	if (i<1 || i > L.length)
		return false;
	x = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}
//��λɾ��Ԫ�أ���iλ��i-1�����±�Ԫ��ɾ������֮�������Ԫ��ǰ��һ��λ�ã���-1

ElemType LocateElem(SqList L, int i)
{
	if (L.length != 0)
		return L.data[i - 1];
}
//��λ���ң�����Ϊ0��ֱ�ӷ���L.data[i-1]����
//���ϰ�λ����������������˳���������ȡ�ԣ�������ɾ������Ҫǰ�ƺ��ƣ�Q(n)

Status GetElem(SqList L, ElemType x)
{
	if (L.length == 0)
		return false;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == x)
			cout << i << '\t';
	}
	cout << endl;
	return true;
}
//��ֵ����,����Ϊ���,����λ��

Status DestroyList(SqList& L)
{
	if (L.length != 0)
		L.length = 0;
	return true;
}
//���ٲ����������Ǿ�̬���䣬ֻ�轫length��Ϊ0�����ɣ�ϵͳ���Զ�����

Status OutPutList(SqList L)
{
	if (L.length == 0)
		return NULL;
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << '\t';
	cout << endl;
	return true;
}
//��ʾ���Ա�ȫ��Ԫ�أ�������������Ƿ�ɹ�

int main()
{
	SqList L;
	InitList(L);
	SqCreateList(L, 3); SqCreateList(L, 5);
	InsertList(L, 3, 2);
	OutPutList(L);
	int x = -1;
	if (DeleteList(L, x, 2))
		cout << x << endl;
	else
		return false;
	OutPutList(L);
	GetElem(L, 3);
	cout << LocateElem(L, 1) << endl;
	DestroyList(L);
	return 0;
}