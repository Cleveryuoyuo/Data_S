#define _CRT_SECURE_NO_WARNINGS 1

#include"seqlist.h"

static int f = 0;

static Find_Location(Seqlist* mylist, Seqtype x)
{
	for (int i = 0; i < mylist->size; i++)
	{
		if (x >= mylist->arr[i])
		{
			return i;
		}
	}
}

static int isfull(Seqlist* mylist)
{
	if (mylist->size == Init)
		return 1;
	else
		return -1;
}

static int isempty(Seqlist* mylist)
{
	if (mylist->size == 0)
		return 1;
	else
		return -1; 
}

void Show_Mylist(Seqlist* mylist)
{
	for (size_t i = 0; i < mylist->size; i++)
	{
		printf("%d ", mylist->arr[i]);
	}
	printf("\n");
}


void Push_Back(Seqlist* mylist,int x)
{
	assert(mylist);
	if (isfull(mylist)==1)
	{
		printf("˳����Ѿ����ˣ����ܷ���!\n");
		printf("�����������룬��ѡ�� 7 ��������!\n");
		return ;
	}

	mylist->arr[mylist->size++] = x;

}
void Push_Front(Seqlist* mylist, Seqtype x)
{
	assert(mylist);
	if (isfull(mylist) == 1)
	{
		printf("˳����Ѿ����ˣ����ܷ���!\n");
		printf("�����������룬��ѡ�� 7 ��������!\n");
		return ;
	}
	for (int i = mylist->size; i >= 0; i--)
	{
		mylist->arr[i + 1] = mylist->arr[i];
	}
	mylist->arr[0] = x;

	mylist->size++;

}

void Pop_Back(Seqlist* mylist)
{
	assert(mylist);
	if (isempty(mylist) == 1)
	{
		printf("˳����Ѿ����ˣ�����βɾ!\n");
	}
	mylist->size--;
}

void Pop_Front(Seqlist* mylist)
{
	assert(mylist);
	if (isempty(mylist) == 1)
	{
		printf("˳����Ѿ����ˣ�����ͷɾ!\n");
	}
	for (size_t i = 0; i < mylist->size; i++)
	{
		mylist->arr[i] = mylist->arr[i + 1];
	}
	mylist->size--;
}

size_t Length(Seqlist* mylist)
{
	return mylist->size;
}

void Check_Capacity(Seqlist* mylist)
{
	assert(mylist);
	if (isfull(mylist) == 1)
	{
		Seqtype* new_arr = (Seqtype*)realloc(mylist->arr, sizeof(Seqtype)* (Init+5));
		if (new_arr != NULL)
		{
			mylist->arr = new_arr;
			printf("���ݳɹ�!\n");
		}
		mylist->TotalSpace += 5;
		printf("%d/%d ", mylist->size, mylist->TotalSpace);
	}
	else
		printf("�ռ���㣬��������!\n");
}

void Order_Insert(Seqlist* mylist, Seqtype x)
{
	assert(mylist);
	if (isfull(mylist) == 1)
	{
		printf("�ռ��Ѿ����ˣ��޷�����!\n");
		return;
	}
	if (f == 0)
	{
		printf("����ǰ���������!\n");
		return;
	}
	int pos = Find_Location(mylist,x);
	for (int i = mylist->size; i >= pos; i--)
	{
		mylist->arr[i + 1] = mylist->arr[i];
	}
	mylist->arr[pos] = x;
	mylist->size++;
}


void Bubble_sort(Seqlist* mylist)
{
	assert(mylist);
	int ret = 0;
	for (size_t i = 0; i < mylist->size - 1; i++)
	{
		for (size_t j = 0; j < mylist->size - 1 - i; j++)
		{
			if (mylist->arr[j]>mylist->arr[j + 1])
			{
				ret = mylist->arr[j + 1];
				mylist->arr[j + 1] = mylist->arr[j];
				mylist->arr[j] = ret;
			}
		}
	}
	f = 1;
}


void Index_Insert(Seqlist* mylist, Seqtype ret, Seqtype index)
{
	assert(mylist);
	if (isfull(mylist) == 1)
	{
		printf("�ռ��Ѿ����ˣ��޷�����!�����������������\n");
		return;
	}
	if (index<0 || index>mylist->TotalSpace)
	{
		printf("λ��Υ�����޷����룡\n");
	}
	else
	{
		for (int i = mylist->size; i > index; i--)
		{
			mylist->arr[i + 1] = mylist->arr[i];
		}
		mylist->arr[index] = ret;
		mylist->size++;
	}
}

int Look_Up(Seqlist* mylist, int ret)
{
	assert(mylist);
	for (int i = 0; i < mylist->size; i++)
	{
		if (mylist->arr[i] == ret)
			return i;
	}
	return -1;
}

void Put_Right(Seqlist* mylist, int index)
{
	assert(mylist);
	int n = 0;
	printf("��������ĳɵ�Ԫ��:> ");
	scanf("%d", &n);
	mylist->arr[index] = n;
	printf("�޸ĳɹ�!\n");
}

void Order_Pop(Seqlist* mylist, int index)
{
	assert(mylist);
	for (int i = index; i < mylist->size; i++)
	{
		mylist->arr[i] = mylist->arr[i + 1];
	}
	mylist->size--;
	printf("ɾ���ɹ�!\n");
}