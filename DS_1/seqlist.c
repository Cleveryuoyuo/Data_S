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
		printf("顺序表已经满了，不能放入!\n");
		printf("如果想继续插入，请选择 7 进行扩容!\n");
		return ;
	}

	mylist->arr[mylist->size++] = x;

}
void Push_Front(Seqlist* mylist, Seqtype x)
{
	assert(mylist);
	if (isfull(mylist) == 1)
	{
		printf("顺序表已经满了，不能放入!\n");
		printf("如果想继续插入，请选择 7 进行扩容!\n");
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
		printf("顺序表已经空了，不能尾删!\n");
	}
	mylist->size--;
}

void Pop_Front(Seqlist* mylist)
{
	assert(mylist);
	if (isempty(mylist) == 1)
	{
		printf("顺序表已经空了，不能头删!\n");
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
			printf("扩容成功!\n");
		}
		mylist->TotalSpace += 5;
		printf("%d/%d ", mylist->size, mylist->TotalSpace);
	}
	else
		printf("空间充足，不用扩容!\n");
}

void Order_Insert(Seqlist* mylist, Seqtype x)
{
	assert(mylist);
	if (isfull(mylist) == 1)
	{
		printf("空间已经满了，无法插入!\n");
		return;
	}
	if (f == 0)
	{
		printf("插入前请进行排序!\n");
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
		printf("空间已经满了，无法插入!想继续插入请先扩容\n");
		return;
	}
	if (index<0 || index>mylist->TotalSpace)
	{
		printf("位置违法，无法插入！\n");
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
	printf("请输入想改成的元素:> ");
	scanf("%d", &n);
	mylist->arr[index] = n;
	printf("修改成功!\n");
}

void Order_Pop(Seqlist* mylist, int index)
{
	assert(mylist);
	for (int i = index; i < mylist->size; i++)
	{
		mylist->arr[i] = mylist->arr[i + 1];
	}
	mylist->size--;
	printf("删除成功!\n");
}