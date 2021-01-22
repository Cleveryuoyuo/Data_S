#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<assert.h>


#define Seqtype int
#define Init  8

typedef struct Seqlist
{
	Seqtype* arr;
	size_t TotalSpace;
	size_t size;
}Seqlist;


void Push_Back(Seqlist* mylist, Seqtype x);
void Push_Front(Seqlist* mylist, Seqtype x);
void Show_Mylist(Seqlist* mylist);
void Pop_Back(Seqlist* mylist);
void Pop_Front(Seqlist* mylist);
size_t Length(Seqlist* mylist);
void Check_Capacity(Seqlist* mylist);
void Order_Insert(Seqlist* mylist, Seqtype ret);
void Index_Insert(Seqlist* mylist, Seqtype ret, Seqtype index);
void Bubble_sort(Seqlist* mylist);

int Look_Up(Seqlist* mylist, int ret);

void Put_Right(Seqlist* mylist, int index);

void Order_Pop(Seqlist* mylist, int ret);



