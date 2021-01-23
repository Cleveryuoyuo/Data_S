#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

static void Meau()
{
	printf("##############################################\n");
	printf("#  0.Quit                    2.ShowSList     #\n");
	printf("#  1.BuySListNode_Back                       #\n");
	printf("#  3.BuySListNode_Front      4.PopSList_Back #\n");
	printf("#  5.PopSList_Front          6.SList_Length  #\n");
	printf("#  7.SList_LookUp            8.SList_Clear   #\n");
	printf("#  9.SListDel_Val           10.SListIns_Val  #\n");
	printf("# 11.SList_Reverse        //12.SList_Sort    #\n");
	printf("##############################################\n");
}
static void SlistInit(SList* mylist)
{
	mylist->head = NULL;
}
static void SList_Destroy(SList* mylist)
{
	SList_Clear(mylist);
}


int main()
{
	SList mylist;

	SListNode* p = NULL;
	SlistInit(&mylist);
	int select = 0;
	int ret = 0;
	//TailFoundList_NoHead(&mylist);
	//HeadFoundList_NoHead(&mylist);
	int quit = 1;
	while (quit == 1)
	{
		Meau();
		printf("��ѡ�����:> ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("����-1��ֹ����!\n");
			while (scanf("%d", &ret), ret != -1)
			{
				BuySListNode_Back(&mylist,ret);
			}
			break;
		case 2:
			ShowList(&mylist);
			break;
		case 3:
			printf("������-1��ֹ����:> \n");
			while (scanf("%d", &ret), ret != -1)
			{
				BuySListNode_Front(&mylist,ret);
			}
			break;
		case 4:
			PopSList_Back(&mylist);
			break;
		case 5:
			PopSList_Front(&mylist);
			break;
		case 6:
			SList_Length(&mylist);
			break;
		case 7:
			printf("������Ҫ���ҵ�ֵ:> ");
			scanf("%d", &ret);
			p = SList_LookUp(&mylist, ret);
			if (p == NULL)
				printf("Ҫ���ҵĲ�����!\n");
			else
				printf("Ҫ���ҵ�%d���ڣ�\n", p->data);
			break;
		case 8:
			SList_Clear(&mylist);
			break;
		case 9:
			printf("��������Ҫɾ����ֵ:> ");
			scanf("%d", &ret);
			SListDel_Val(&mylist,ret);
			break;
		case 10:
			printf("��������Ҫ�����ֵ:> ");
			scanf("%d", &ret);
			SListIns_Val(&mylist,ret);
			break;
		case 11:
			SList_Reverse(&mylist);
			break;
		case 12:
			//SList_Sort(&mylist);
			break;
		case 0:
			quit = -1;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");

	}
	
	SList_Destroy(&mylist);
	return 0;
}