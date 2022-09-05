#include<iostream>
using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;
//ע������LNode��*LinkList�������Լ�ע��next����ķ�ʽ
//ͨ����LinkList���嵥����ǿ���������ĳ�������ͷָ�룻
//��LNode*����ָ���������������ָ�����������Ԫ�ص�ָ�룩��߿ɶ���

Status InitLList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return true;
}
//LΪͷָ�룬ΪL��̬����һ���ռ䲢ʹL->nextָ��ռ���ʼ��һ����ͷ���Ŀ�����

Status CreateLList_Head(LinkList& L, ElemType x)
{
	LNode* p;
	p = new LNode;
	p->data = x;
	p->next = L->next;
	L->next = p;
	if (L->next == NULL)
		return false;
	return true;
}
//ͷ�巨����������Ҫ�����Ƿ���ͷ��㣬��ͷ�������Ԫ���ͺ�������һ�£�����һ��
//��ͷ�巨����������Ϊ������Ҫ��������˳��

Status LocateLList(LinkList& L, int k)
{
	LNode* p = L;
	int i = 0;
	while (p && i < k-1)
	{
		p = p->next;
		i++;
	}
	cout << p->data << endl;
	if (p == NULL || i == k)
		return false;
	return true;
}
//���Ҳ���������ֻ��˳����ң���ͷָ�뿪ʼ������������ҵ�ǰԪ�أ�O(n)
//pҲ���Դ�L>next��ʼ�������鷳һЩ

Status InsertLList(LinkList& L, ElemType x, int k)
{
	LNode* p = L, * q;
	q = new LNode;
	int i = 0;
	while (p && i < k - 1)
	{
		p = p->next;
		i++;
	}
	if (!p || i == k)
		return false;
	q->data = x;
	q->next = p->next;
	p->next = q;
	return true;
}
//������Ĳ���ͬ����Ҫ�Ȳ���ǰ����㣬Ȼ���ٽ���ָ����޸�
//�ڴ�����£�һ��Ҫ�ǵ���ʹq->next=p->next�����򽫻�ʹq->nextָ��q����
//����������ȡ���÷���ռ�����ԣ�����Ԫ�ز���Ҫ�����Ƿ�����

Status DeleteLList(LinkList& L, ElemType& x,int k)
{
	if (L->next == NULL)
		return false;
	LNode* p = L, * q;
	int i = 0;
	while (p && i < k - 1)
	{
		p = p->next;
		i++;
	}
	//�ҵ�ǰ�����
	if (p == NULL || i == k)
		return false;
	q = p->next;
	x = q->data;
	p->next = q->next;
	delete q;
	return true;
}
//�������ɾ��������Ҫ�ҵ�ǰ����㣬�ٶ�����ɾ����λ�ý���ָ���޸�
//��Ҫ�жϵ������Ƿ�Ϊ��

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
	cout << endl;
	return true;
}

Status DestroyLList(LinkList& L)
{
	int x = -1;
	if (!L->next)
		DeleteLList(L, x, 1);
	delete L;
	L = NULL;
	return true;
}
//����̬���䣬�Ƚ�����Ԫ��ɾ������delete L����

int main()
{
	LinkList L;
	InitLList(L);
	CreateLList_Head(L, 7); CreateLList_Head(L, 5); CreateLList_Head(L, 3);
	OutPutL(L);
	int x = -1;
	if (DeleteLList(L, x, 2))
		cout << x << endl;
	else
		return false;
	InsertLList(L, 2, 2);
	OutPutL(L);
	DestroyLList(L);
	OutPutL(L);
	return 0;
}