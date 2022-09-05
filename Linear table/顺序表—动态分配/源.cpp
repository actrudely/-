#include<iostream>
using namespace std;

#define InitSize 5
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType* data;
	int length, maxsize;
}SeqList;
//����dataָ������ʾ˳����Լ�length��ʾ��
//maxsize�ز����١���̬��������ʱ��Ҫ������󳤶�
//��InitSize�Ѿ�������˹̶���ֵ���޷��ı䣬�����Ҫһ�������maxsize��ʾ��󳤶�

Status InitList(SeqList& L)
{
	L.data = new ElemType[InitSize];
	L.length = 0;
	L.maxsize = InitSize;
	return true;
}
//��ʼ����̬����InitSize���ռ䣬����Ϊ0��ʹmaxsizeΪ��󳤶�

Status CreateList(SeqList& L, ElemType x)
{
	if (L.length == L.maxsize)
		return false;
	L.data[L.length] = x;
	L.length++;
	return true;
}
//��˳���������Ԫ�أ�ÿ���һ��Ԫ�أ�����һ

Status AddSize(SeqList& L,int i)
{
	ElemType* p = L.data;
	L.data = new ElemType[InitSize + i];
	for (int j = 0; j < L.length; j++)
		L.data[j] = p[j];
	L.maxsize = L.maxsize + i;
	return true;
}
//��L.data������Ԫ���ݴ���p�У������¸�L.data��̬����InitSize+i�Ŀռ�
//����ڽ�p�е�Ԫ���ƻ�L.data��������󳤶�
//���Ӷ�̬���鳤�ȣ���Ҫ�����ƶ�����Ԫ�أ�ʹ��Ч�ʴ�󽵵ͣ�����Ԫ�ؽ϶����
//ע�������Ҫ���ĵ�����󳤶ȣ��������ձ�ʾ��̬���ӿռ�ɹ�

Status OutPut(SeqList L)
{
	if (L.length == 0)
		return false;
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << '\t';
	cout << endl;
	return true;
}

int main()
{
	SeqList L;
	InitList(L);
	CreateList(L, 3); CreateList(L, 5); CreateList(L, 7); CreateList(L, 1); 
	CreateList(L, 9); //��������Ԫ�غ��Ѿ�ʹ˳�������
	CreateList(L, 7);//���ڿռ䲻�㣬���Ԫ���޷�����˳����У�Ҳ�������
	OutPut(L);
	if (AddSize(L, 3))
		cout << L.maxsize << endl;//����֤����̬������������ռ�ɹ�
	CreateList(L, 7);//���Ӷ�̬����ռ�֮�󣬸�Ԫ�سɹ�����˳�����
	OutPut(L);
	return 0;
}