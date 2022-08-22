#include<iostream>
using namespace std;

#define InitSize 5
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType* data;
	int length, MAXSIZE;
}SeqList;
//����dataָ������ʾ˳����Լ�length��ʾ��
//MAXSIZE�ز����١���̬��������ʱ��Ҫ����󳤶����ӣ�InitSize�̶���ֵ�޷��ı�

Status InitList(SeqList& L)
{
	L.data = new ElemType[InitSize];
	L.length = 0;
	L.MAXSIZE = InitSize;
	return true;
}
//��ʼ����̬���䣬����Ϊ0��ʹMAXSIZEΪ��󳤶�

Status IncreaseSize(SeqList& L,int i)
{
	ElemType* p = L.data;
	L.data = new ElemType[L.MAXSIZE + i];
	for (int i = 0; i < L.length; i++)
		L.data[i] = p[i];
	//InitSize = InitSize + i;InitSize�̶��޷�����
	L.MAXSIZE = L.MAXSIZE + i;
	delete p;
	return true;
}
//���Ӷ�̬���鳤�ȣ���Ҫ�����ƶ�����Ԫ�أ���������󳤶�

int main()
{
	SeqList L;
	InitList(L);
	IncreaseSize(L, 3);
	return 0;
}