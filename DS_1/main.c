#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

static void Menu()
{
	printf("##############################################\n");
	printf("#  0 sign_out                 13 order_pop    #\n");//�˳�   �м�ɾ��
	printf("#  1 push_back                 2 push_front   #\n");//β��   ͷ��
	printf("#  3 show_list                 4 pop_back     #\n");//��ʾ   βɾ
	printf("#  5 pop_front                 6 length       #\n");//ͷɾ   ����
	printf("#  7 check_capacity            8 order_insert #\n");//����   ˳�����
	printf("#  9 bubble_sort              10 index_insert #\n");//����   �±����
	printf("# 11 look_up                  12 put_right    #\n");//����   ����
	printf("##############################################\n");
}

static void Open_up_space(Seqlist* mylist)
{
	assert(mylist);
	mylist->arr = (Seqtype*)malloc(sizeof(Seqtype)*Init);
	assert(mylist->arr != NULL);
	memset(mylist->arr, 0, sizeof(Seqtype)*Init);
	mylist->TotalSpace = Init;
	mylist->size = 0;
}

int main()
{
	Seqlist mylist;
	Open_up_space(&mylist);
	int quit = 1;
	int ret = 0;
	int select;
	int index = 0;
	while (quit>0)
	{
		Menu();
		printf("��ѡ�����:> ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("�����������-1��������!\n");
			while (ret != -1)
			{
				scanf("%d", &ret);
				if (ret != -1)
					Push_Back(&mylist, ret);
			}
			ret = 0;
			break;
		case 2:
			scanf("%d", &ret);
			if (ret != -1)
				Push_Front(&mylist, ret);
			break;
		case 3:
			Show_Mylist(&mylist);
			break;
		case 4:
			Pop_Back(&mylist);
			break;
		case 5:
			Pop_Front(&mylist);
			break;
		case 6:
			printf("%d\n", Length(&mylist));
			break;
		case 7:
			Check_Capacity(&mylist);
			break;
		case 8:
			printf("����������������:> ");
			scanf("%d", &ret);
			Order_Insert(&mylist,ret);
		case 9:
			Bubble_sort(&mylist);
			break;
		case 10:
			printf("����������������:> ");
			scanf("%d", &ret);
			printf("�������������±�:> ");
			scanf("%d", &index);
			Index_Insert(&mylist, ret,index);
			break;
		case 11:
			printf("����������ҵ�Ԫ��:> ");
			scanf("%d", &ret);
			if (Look_Up(&mylist, ret) == -1)
				printf("�Ҳ���!\n");
			else
				printf("�ҵ��ˣ��±���%d\n", Look_Up(&mylist, ret));
			break;
		case 12:
			printf("�������������Ԫ��:> ");
			scanf("%d", &ret);
			index = Look_Up(&mylist, ret);
			if (index == -1)
				printf("�Ҳ�����Ҫ�޸ĵ�Ԫ��!\n");
			else
				Put_Right(&mylist, index);
			break;
		case 13:
			printf("��������ɾ����Ԫ��:> ");
			scanf("%d", &ret);
			index = Look_Up(&mylist, ret);
			if (index == -1)
				printf("�Ҳ���!\n");
			else
				Order_Pop(&mylist, index);
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


	return 0;
}