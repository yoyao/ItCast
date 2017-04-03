#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>

using namespace std;

typedef struct _linknode LinkNode;

struct _linknode{
	int data;
	LinkNode* Next;
};


typedef struct _node Node;
struct _node{
	Node* Next;
};


//逆置
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
//遍历
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
判断两个链表是否相交，相交是指两个节点地址相同，不是值相等。
基本思路：
如果两个链表有相交的节点，就是说从相交开始的节点至最后一个节点，地址都是相同的。即 都指向了同一个节点。
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



void TestLinkList()
{
	LinkNode node5 = { 5, NULL };
	LinkNode node4 = { 4, &node5 };
	LinkNode node3 = { 3, &node4 };
	LinkNode node2 = { 2, &node3 };
	LinkNode node1 = { 1, &node2 };
	LinkNode node0 = { 0, &node1 };

	LinkNode node8 = { 8, &node4 };
	LinkNode node7 = { 7, &node8 };
	LinkNode node6 = { 6, &node7 };
	//
	/*
	Traverse(&node1);
	Reverse(&node1);
	Traverse(&node5);
	LinkNode* inters=IsIntersect(&node6, &node0);
	*/
}

void ArrayT(int*p[])
{

}

int main()
{
	int *arr[5] = { 0 };
	ArrayT(arr);
	//TestLinkList();

	freopen("f:\\struct.txt", "r", stdin);

	char buf[1024] = { 0 };
	scanf("%s", buf);
	printf("%s", buf);
	fclose(stdin);


	//system("pause");
	return EXIT_SUCCESS;
}