#include<iostream>
using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

Status InitLList(LinkList& L)
{
	L = new LNode;
	L = NULL;
	return true;
}
//��ʼ��һ������ͷ���Ŀ�����

/*Status CreateLList_Head(LinkList& L, ElemType x)
{
	LNode* p;
	p = new LNode;
	p->data = x;
	p->next = L;
	L = p;
	return true;
}*/
//ͷ�巨ֱ�Ӵ����������ʹ�ͷ�ڵ���������Lָ���ָ��

Status CreateLList_Head(LinkList& L)
{
	LNode* p;
	p = new LNode;
	cout << "������Ԫ��(��9999����)��";
	cin >> p->data;
	if (p->data != 9999)
	{
		p->next = L;
		L = p;
		CreateLList_Head(L);
	}
	return true;
}
//����ͷ���ݹ�ͷ�巨�����������ݹ����Ϊp->data=9999
//��ʹp->nextָ��L��Ȼ���ٽ�Lָ���ƶ�ָ��p�����㵥������߼���ϵ�����迼����Ԫ���

Status OutPutL(LinkList L)
{
	if (L == NULL)
		return false;
	LNode* p = L;
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}//���ͷ���Ĳ�֮ͬ������������ݣ���Ϊ��ʱ��p=L������Ԫ���
	return true;
}

int main()
{
	LinkList L;
	InitLList(L);
	CreateLList_Head(L);
	/*CreateLList_Head(L, 3); CreateLList_Head(L, 5); CreateLList_Head(L, 7);*/
	OutPutL(L);
	return 0;
}