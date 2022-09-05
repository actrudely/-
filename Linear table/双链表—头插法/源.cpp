#include<iostream>
using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct DNode
{
	ElemType data;
	int length;
	struct DNode* next, * prior;
}DNode, * DLinkList;

Status InitDList(DLinkList& L)
{
	L = new DNode;
	L->length = 0;
	L->next = NULL;
	L->prior = NULL;
	return true;
}
//������˫���������Ҫ����ǰ���ͺ������ָ�룬����ͷ��㣬����L��ָ�붼ָ��NULL
//����һ����ͷ���Ŀ�˫������˫�����п�ΪL->next,L->priorָ��NULL

Status CreateDList_Head(DLinkList& L, ElemType x)
{
	DNode* p;
	p = new DNode;
	p->data = x;
	p->next = L->next;
	L->next = p;
	if (L->length == 0)
		p->prior = L;
	else
		p->next->prior = p;
	return true;
}
//��ͷ�巨��������Ψһ��ͬ���ǣ���Ҫ�޸�p->priorָ���ָ��˫��������

DNode* LocateDList(DLinkList L, int k)
{
	DNode* p = L, * q;
	int i = 0;
	while (p && i < k)
	{
		p = p->next;
		i++;
	}
	return p;
}
//DNode*�ܹ�����ָ���������λ���ҡ���ΪElemType,�򷵻ص���ֵ

Status InsertDList(DLinkList& L, ElemType x, int k)
{
	if (L->next == NULL)
		return false;
	DNode* p, * q;
	p = LocateDList(L, k - 1);
	if (!p)
		return false;
	q = new DNode;
	q->data = x;
	q->next = p->next;
	p->next = q;
	q->prior = p;
	return true;
}
//�ȵ��������q->priorָ���ָ���޸�,���벻��Ҫ�����Ƿ�Ϊ���һ��
//���迼���Ƿ�nextΪNULL���޷��޸�NULL��priorָ��

Status DeleteDList(DLinkList& L, ElemType& x, int k)
{
	DNode* p, * q;
	p = LocateDList(L, k - 1);
	if (!p)
		return false;
	q = new DNode;
	q = p->next;
	x = q->data;
	if (!q->next)
	{
		p->next = q->next;
	}
	else
	{
		q->next->prior = p;
		p->next = q->next;
	}
	return true;
}
//��Ҫ�޸�q->next->priorָ���ָ��ɾ����Ҫ�����Ƿ�ɾ�������һ��
//��ɾ�����һ������nextָ��ָ�����NULL��NULL�����޸�ǰ��ָ�룬������

Status OutPutD(DLinkList& L)
{
	if (L->next == NULL)
		return false;
	DNode* p=L->next;
	while (p)
	{
		cout << p->data << '\t';
		p =p->next;
	}
	cout << endl;
	return true;
}

int main()
{
	DLinkList L;
	InitDList(L);
	CreateDList_Head(L, 5); CreateDList_Head(L, 3); CreateDList_Head(L, 1);
	OutPutD(L);
	InsertDList(L, 7, 1);
	OutPutD(L);
	int x = -1;
	if (DeleteDList(L, x, 4))
		cout << x << endl;
	else
		return false;
	OutPutD(L);
	return 0;
}