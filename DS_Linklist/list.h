#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<assert.h>


typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SListNode;

typedef struct SList
{
	SListNode *head;  //��Ա��װ
}SList;

static SListNode*  _bynode()
{
	SListNode* s = malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = 0;
	s->next = NULL;
	return s;
}


void BuySListNode_Back(SList* mylist,int x)
{
	assert(mylist);
	SListNode* s = _bynode();
	
	s->data = x;
	
	SListNode* p = mylist->head;
	
	//β����Ҫ�ҽڵ�
 	if (p == NULL)
	{
		mylist->head = s;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	}
}

void ShowList(SList* mylist)
{
	assert(mylist);
	SListNode* p = mylist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over\n");
}

void BuySListNode_Front(SList* mylist,int x)
{
	assert(mylist);
	
	SListNode* s = _bynode();

	s->data = x;

	
	//ͷ�岻���ҽڵ� 
	s->next = mylist->head;
	mylist->head = s;

	/*
	SListNode* p = mylist->head;
	if (p == NULL)
	{
		mylist->head = s;
	}
	else
	{
		s->next = p;
		mylist->head = s;
	}*/
}

void PopSList_Back(SList* mylist)
{
	assert(mylist);
	SListNode* p = mylist->head; 
	SListNode* pre = NULL;
	if (p != NULL)
	{
		if (p->next == NULL)//����ֻ��һ���ڵ�
		{
			mylist->head = NULL;
		}
		else
		{
			while (p->next != NULL)
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;
		}
		free(p);
	}
	else
	{
		printf("����Ϊ�գ�����ɾ��!\n");
		return;
	}
}

void PopSList_Front(SList* mylist)
{
	assert(mylist);
	SListNode* p = mylist->head;
	if (p != NULL)
	{
		mylist->head = p->next;
		free(p);
	}
}

void SList_Length(SList* mylist)
{
	assert(mylist);
	SListNode* p = mylist->head;
	if (p == NULL)
	{
		printf("����Ϊ0!\n");
	}
	else
	{
		int count = 1;
		while (p->next != NULL)
		{
			p = p->next;
			count++;
		}
		printf("����Ϊ%d\n", count);
	}
}

SListNode* SList_LookUp(SList* mylist, int ret)
{
	SListNode* p = mylist->head;
	while (ret != p->data)
	{
		if (p->next != NULL)
		{
			p = p->next;
		}
		if (p->next == NULL)
			return (p = NULL);
	}
	return p;
}

void SList_Clear(SList* mylist)
{
	assert(mylist);
	SListNode* p = mylist->head;
	while (p != NULL)
	{
		mylist->head = p->next;//ͷɽ
		free(p);
		p = mylist->head;
	}
}
void SListDel_Val(SList* mylist,int ret)
{
	assert(mylist);
	SListNode* p = mylist->head;
	SListNode* per = NULL;
	while (ret != p->data&&p!=NULL)
	{
		per = p;
		p = p->next;
	}
	if (ret == p->data)
	{
		if (per == NULL)
		{
			mylist->head = p->next;
			printf("ɾ���ɹ�!\n");
		}
		else
		{
			per->next = p->next;
			printf("ɾ���ɹ�!\n");
			free(p);
		}
	}
	return;
}

SListIns_Val(SList* mylist,int x)
{
	assert(mylist);
	SListNode* s = _bynode();
	s->data = x;
	SListNode* p = mylist->head;
	SListNode* per = NULL;
	if (p == NULL)
	{
		mylist->head = s;
	}
	else
	{
		while (p != NULL&&x > p->data)
		{
			per = p;
			p = p->next;
		}
		if (per == NULL)//�������ͷ������
		{
			s->next = p;
			mylist->head = s;
		}
		else
		{
			s->next = p;
			per->next = s;
		}
	}
}

void SList_Reverse(SList* mylist)
{
	assert(mylist);
	SListNode* p = mylist->head;
	if (p == NULL)
	{
		printf("û�������޷�����!\n");
		return;
	}
	else if (p->next == NULL)
	{
		printf("ֻ��һ�������޷�����!\n");
		return;
	}
	else
	{
		SListNode* per = p->next;
		mylist->head->next = NULL;

		SListNode* qer = per;

		while (qer != NULL)
		{
			qer = qer->next;
			per->next = p;
			mylist->head = per;
			per = qer;
			p = mylist->head;
		}
		printf("ת�óɹ�!\n");
	}
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//��ͷ�ڵ��ͷ��
/*
void HeadFoundList_NoHead(List* mylist)
{
	*mylist = NULL;

	*mylist = (ListNode*)malloc(sizeof(ListNode));
	assert(*mylist != NULL);
	(*mylist)->data = 1;
	(*mylist)->next = NULL;

	ListNode* p = *mylist;
	p->next = NULL;

	for (int i = 2; i <= 10; i++)
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;


		s->next = *mylist;
		*mylist = s;
	}
}*/


// ��ͷ�ڵ��β�崴����
/*
void TailFoundList_NoHead(List* mylist)
{
	*mylist = NULL;

	*mylist = (ListNode*)malloc(sizeof(ListNode));
	assert(*mylist != NULL);
	(*mylist)->data = 1;

	ListNode* p = *mylist;
	for (int i = 2; i <= 10; i++)
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}
*/
