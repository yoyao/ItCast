#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<vector>
#include"dlllib.h"
#include"staticlib.h"

using namespace std;

#pragma comment(lib,"./staticlib.lib")
#pragma comment(lib,"./dlllib.dll")

typedef struct _linknode LinkNode;

struct _linknode{
	int data;
	LinkNode* Next;
};


typedef struct _node Node;
struct _node{
	Node* Next;
};


//����
void Reverse(LinkNode* head)
{
	LinkNode* p_head_tmp = head;
	LinkNode* p_sec_tmp = head->Next;
	LinkNode* p_thr = NULL;
	if (p_sec_tmp != NULL&&p_sec_tmp->Next != NULL)
	{
		p_thr = p_sec_tmp->Next;
	}

	while (NULL != p_thr)
	{
		p_sec_tmp->Next = p_head_tmp;
		p_head_tmp = p_sec_tmp;
		p_sec_tmp = p_thr;
		p_thr = p_thr->Next;
	}
	p_sec_tmp->Next = p_head_tmp;
	head->Next = NULL;
}
//����
void Traverse(LinkNode* head)
{
	while (NULL != head)
	{
		printf("%d ", head->data);
		head = head->Next;
	}
	printf("\n");
}


/*---------------------------------------------------------
�ж����������Ƿ��ཻ���ཻ��ָ�����ڵ��ַ��ͬ������ֵ��ȡ�
����˼·��
��������������ཻ�Ľڵ㣬����˵���ཻ��ʼ�Ľڵ������һ���ڵ㣬��ַ������ͬ�ġ��� ��ָ����ͬһ���ڵ㡣
-----------------------------------------------------------------------------------------*/
LinkNode* IsIntersect(LinkNode* head1, LinkNode* head2)
{
	LinkNode* p1 = head1, *p2 = head2;
	int len1 = 0, len2 = 0;
	while (p1 != NULL)
	{
		++len1;
		p1 = p1->Next;
	}
	while (p2!= NULL)
	{
		++len2;
		p2 = p2->Next;
	}
	if (p1 != p2)
	{
		return NULL;
	}

	if (len1 == len2)
	{
		return head1;
	}
	int diff = abs(len1 - len2);

	LinkNode* p_len = head1;
	LinkNode* p_sec = head2;
	if (len1 <len2)
	{
		p_len = head2;
		p_sec = head1;
	}
	while (diff>0)
	{
		p_len = p_len->Next;
		diff--;
	}
	while (p_len != p_sec)
	{
		p_len = p_len->Next;
		p_sec = p_sec->Next;
	}

	return p_len;
}


LinkNode* DoReverse(LinkNode* front, LinkNode* back)
{
	LinkNode* record = NULL;
	if (back->Next != NULL)
	{
		record=DoReverse(back, back->Next);
	}
	if (back->Next == NULL)
	{
		record = back;
	} 
	back->Next = front;
	front->Next = NULL;
	
	
	return record;
}
//�ݹ�ʵ�����������
void RecursionReverse(LinkNode* Head)
{
	if (Head == NULL || Head->Next == NULL || Head->Next->Next == NULL)
	{
		return;
	}

	LinkNode* newhead=DoReverse(Head->Next, Head->Next->Next);
	Head->Next = newhead;
}

//�Ƿ��л�
LinkNode* LinkListIsLoop(LinkNode* Head)
{
	LinkNode* sign = NULL;
	if (Head == NULL || Head->Next == NULL)
	{
		return sign;
	}
	LinkNode* Slow = Head->Next;
	LinkNode* Fast = Head->Next;

	while (NULL != Fast->Next&&Slow != NULL)
	{
		Slow = Slow->Next;
		Fast = Fast->Next->Next;
		if (Slow == Fast)
		{
			sign = Fast;
			break;
		}
		/*//�����������Է�����Ҳ���Է����棬�����������һ��ѭ����
		Slow = Slow->Next;
		Fast = Fast->Next->Next;
		*/
	}


	return sign;
}


int LinkListLoopLength(LinkNode* Head)
{
	int len = 0;
	LinkNode* loop=LinkListIsLoop(Head);
	if (loop == NULL)
	{
		return 0;
	}


	LinkNode* curloop = loop->Next;
	while (curloop != loop)
	{
		++len;
		curloop = curloop->Next;
	}

	return len;
}

/*
��ô���л��Ļ����ϣ���ô�ҵ������������أ�һ������Ҳ��������ͣ��������ҵ�������Ƚϵף����ϵĽ����У��������ƶ�

��s�������ǳ��ȵģ�����Ū���Һ��Σ����ǣ��������Լ��Ľ��ͺ��ˣ����еĶ����ƶ��˶��ٲ���˵����

��һ����ָ���slow���������Ľ�fast��

������ʱ��slow���ƶ���s����fast���ƶ���2s����������Զ��׼��ġ�

����a���£� ����ͷ�ƶ�a��������ڵ㡣

����x���£� ��ڵ��ƶ�x�����������㡣

����r���£� �ӻ��е�ĳһ���ƶ�r�����ֵ������һ�㣬Ҳ����ת��һȦ����˼��

����t���£������������ƶ�����ڵ���ƶ�����

����L���£� ������ͷ�ƶ�L�����ֵ����������㡣Ҳ���Ǳ���������֮��ͨ�����һ���ڵ��ָ�룬���ƶ����������е�ĳһ�㡣

���У̡�����a + r  =  a + x + t

��ôslow��fast�����ˣ�fast��Ȼ��slow������n��Ȧ��Ҳ���� n*r ������ô

s = a + x

2s = s + n*r �� �ɵ�  s = n*r

��s=a+x������s =n*r���ɵ� a+x = n*r, Ҳ���� a+x = (n-1)*r + r ����

�ӱ�ͷ�ƶ�����ڵ㣬�ٴ���ڵ��ƶ�����ڵ㣬Ҳ�����ƶ�����������ľ��룬���� L =  a + r , ����r = L - a

����   a+x = (n-1)*r + L - a ,   ���� a  = (n-1)*r + L - a - x = (n-1)*r + t

Ҳ����˵���ӱ�ͷ����ڵ�ľ��룬���ڴ���������������ֵ���ͷ�ľ��롣

���ԣ��ӱ�ͷ����һ��ָ�룬������������һ��ָ�룬����ͬʱ�ƶ�����Ȼ�ܹ�����ڵ�������������������������㡣


����1��
aͬ����Ȧ׷��b,·�̲�s,�ٶȲ�v,�򾭹�t=s/v,a׷��b
�����룬����bԭ�ز���,a��v���ٶ�����s��b��ϡ�
v�൱��pqָ���ٶȲp��q�죩��s�൱��pq �����뻷ʱ��q˳ʱ�뵽p�ľ��롣

Ȼ�������嵽����·������ٶȲ�н������ٴ�����2��
���������һ�����ڣ���1�ߵ�6����������ÿ�ζ�Ͷ��2��������Զ�������յ㡣1,3,5,7��7�൱�ڻص�1����1��7ѭ���������߲���6�������ٶȲ�Vȡ1���Ƚ����ף���ô�����ߵ��յ㣨ab���غϣ���
*/
//���һ�����ڵ� �ܸ��� �����
LinkNode* FindLoopEntrance(LinkNode* Head)
{
	LinkNode* loop=NULL;
  loop=LinkListIsLoop(Head);
  LinkNode* node = Head->Next;

  while (node != loop)
	{
	  node = node->Next;
		loop = loop->Next;
	}
	return loop;
}

void LinkListSort()
{

}

void Quick_Sort(int arr[],int len)
{
	int front = 0;
	int back = len - 1;




}
void TestLinkList()
{
	LinkNode node0;
	LinkNode node1;
	LinkNode node2;
	LinkNode node3;
	LinkNode node4;
	LinkNode node5;
	LinkNode node6;
	LinkNode node7;
	LinkNode node8;

	node0 = { 0, &node1 };
	node1 = { 1, &node2 };
	node2 = { 2, &node3 };
	node3 = { 3, &node4 };
	node4 = { 4, &node5 };
	node5 = { 5, &node6 };
	node6 = { 6, &node7 };
	node7 = { 7, &node8 };
    node8 = { 8, &node4 };


	LinkNode head = { -1, &node0 };
	LinkNode* entrance=FindLoopEntrance(&head);

	/*
	Traverse(&node1);
	Reverse(&node1);
	Traverse(&node5);
	LinkNode* inters=IsIntersect(&node6, &node0);
	*/
}


typedef int(*MYADD)(int, int);

struct mystru{
	int operator()(int a, int b)
	{
		return a - b;
	}
};


void mytestfun(int(*funp)(int, int))
{

}





int main()
{
	struct mystru myst;
	int a = myst(4, 2);
	int ret = StaticSum(45, 54);
	ret = DllSum(65, 3);
	LPCWSTR path = L"./dlllib.dll";
 	HMODULE handle= LoadLibrary(path);
	LPCSTR funname = "DllSum";
	MYADD myadd = (MYADD)GetProcAddress(handle, funname);

	ret = myadd(1, 2);


	std::cout << ret << std::endl;

	//TestLinkList();

	int arr_int[11] = { 45, 89, 74, 20, 36, 12, 87, 25, 41, 37, 61 };

	for (int i = 0; i < 11; ++i)
	{
		printf("%d ", arr_int[i]);
	}
	printf("\n");
	//system("pause");
	return EXIT_SUCCESS;
}