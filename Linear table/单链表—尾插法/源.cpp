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
	L->next = NULL;
	return true;
}

Status CreateLList_Tail(LinkList& L)
{
	LNode* p, * r;
	r = L;
	int x;
	cout << "Ԫ��������";
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		p = new LNode;
		cout << "Ԫ�أ�";
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	return true;
}
//β�巨������������Ҫ������һ��βָ������ʼ��ָ���βԪ��
//��βָ���ָ��ָ���������߼���ϵ������˳�������˳����ͬ
//������һ��ʼ��Ҫ����r����ʼ��rָ��L����˲���ʹ�õݹ����ֱ������ֵ�ķ�ʽ����
//����ÿ�β��붼�Ǳ�βԪ�أ����ʹp->nextָ��NULL���������޸�rָ���ָ�򼴿�

//��Ȼ������������βָ��r��
//��βָ��r����L������ȫ�ֱ�����û����ÿһ������������ָ��β���
//������ʵ�ϣ�����ɾ�������ҵȲ�����ͷ�巨������û������
//β�巨������Ψһ���������ڴ���ʱ��ͷ�巨��������Щ��ͬ

Status OutPutL(LinkList L)
{
	if (L->next == NULL)
		return false;
	LNode* p = L->next;
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	return true;
}

int main()
{
	LinkList L;
	InitLList(L);
	CreateLList_Tail(L);
	OutPutL(L);
	return 0;
}