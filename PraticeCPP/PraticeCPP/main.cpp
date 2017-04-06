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
//递归实现链表的逆置
void RecursionReverse(LinkNode* Head)
{
	if (Head == NULL || Head->Next == NULL || Head->Next->Next == NULL)
	{
		return;
	}

	LinkNode* newhead=DoReverse(Head->Next, Head->Next->Next);
	Head->Next = newhead;
}

//是否有环
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
		/*//此两条语句可以放上面也可以放下面，放上面可以少一次循环。
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

LinkNode* LinkListSort(LinkNode* Head, LinkNode* Tail, int(*PFUN)(int, int))
{
	LinkNode*p_fast = Head->Next->Next;
	LinkNode*p_back = Tail;
	LinkNode* pcur = Head->Next;

	while (p_fast)
	{
		if (PFUN(pcur->data, p_fast->data) > 0)
		{
			LinkNode* tmp = pcur->Next;
			pcur->Next = p_fast->Next;
		}
	}


	return NULL;
}

int MyCompare(int a, int b)
{
	return a - b;
}


/*
那么在有环的基础上，怎么找到这个环的入口呢，一般网上也会给出解释，可能是我的理解力比较底，网上的解释中，总是用移动

了s步，又是长度的，总是弄的我很晕，于是，给出我自己的解释好了，所有的都用移动了多少步来说明。

走一步的指针叫slow，走两步的叫fast。

相遇的时候，slow共移动了s步，fast共移动了2s步，这个是显而易见的。

定义a如下： 链表头移动a步到达入口点。

定义x如下： 入口点移动x步到达相遇点。

定义r如下： 从环中的某一点移动r步，又到达的这一点，也就是转了一圈的意思。

定义t如下：　从相遇点移动到入口点的移动步数

定义L如下： 从链表头移动L步，又到达了相遇点。也就是遍历完链表之后，通过最后一个节点的指针，又移动到了链表中的某一点。

其中Ｌ　＝　a + r  =  a + x + t

那么slow和fast相遇了，fast必然比slow多走了n个圈，也就是 n*r 步，那么

s = a + x

2s = s + n*r ， 可得  s = n*r

将s=a+x，带入s =n*r，可得 a+x = n*r, 也就是 a+x = (n-1)*r + r 　　

从表头移动到入口点，再从入口点移动到入口点，也就是移动了整个链表的距离，即是 L =  a + r , 所以r = L - a

所以   a+x = (n-1)*r + L - a ,   于是 a  = (n-1)*r + L - a - x = (n-1)*r + t

也就是说，从表头到入口点的距离，等于从相遇点继续遍历又到表头的距离。

所以，从表头设立一个指针，从相遇点设立一个指针，两个同时移动，必然能够在入口点相遇，这样，就求出了相遇点。


想象1，
a同向绕圈追赶b,路程差s,速度差v,则经过t=s/v,a追上b
简化了想，就是b原地不动,a以v的速度跑完s跟b汇合。
v相当于pq指针速度差（p慢q快），s相当于pq 都进入环时，q顺时针到p的距离。

然而，具体到链表环路，这个速度差，有讲究。再次想象2，
飞行棋最后一个环节，从1走到6结束，骰子每次都投中2，这样永远到不了终点。1,3,5,7（7相当于回到1），1到7循环，就是走不到6。所以速度差V取1，比较稳妥，怎么都能走到终点（ab能重合）。
*/
//查找环的入口点 很复杂 不理解
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


// 5, 4, 1, 9, 6, 3, 7, 10, 2, 11,8
int Quick_Sort(int arr[],int front,int back)
{
	int curval = arr[front];
	//int pos = front;

	while (front < back)
	{
		while (arr[back] > curval &&front < back)
		{
			--back;
		}
		if (front < back)
		{
			arr[front] = arr[back];
			//arr[front] = ;
			//pos = back;
		}


		while (arr[front] < curval &&front < back)
		{
			++front;
		}
		if (front < back)
		{
			arr[back] = arr[front];
			//arr[pos] = arr[front + 1];
			//pos = front + 1;
		}
	}
	
	arr[front] = curval;


	return front;
}

void DoQuick_Sort(int arr[], int front, int back)
{
	if (front <back)
	{
		int i = Quick_Sort(arr, front, back);//先成挖坑填数法调整s[]  
		DoQuick_Sort(arr, front, i - 1); // 递归调用   
		DoQuick_Sort(arr, i + 1, back);
	}
}

void quicksort(int v[], int left, int right){
	if (left < right){
		int key = v[left];
		int low = left;
		int high = right;
		while (low < high){
			while (low < high && v[high] > key){
				high--;
			}
			v[low] = v[high];
			while (low < high && v[low] < key){
				low++;
			}
			v[high] = v[low];
		}
		v[low] = key;
		quicksort(v, left, low - 1);
		quicksort(v, low + 1, right);
	}
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

	node0 = { 4, &node1 };
	node1 = { 1, &node2 };
	node2 = { 2, &node3 };
	node3 = { 7, &node4 };
	node4 = { 8, &node5 };
	node5 = { 5, &node6 };
	node6 = { 9, &node7 };
	node7 = { 3, &node8 };
    node8 = { 6, &node4 };


	LinkNode head = { -1, &node0 };
	//LinkNode* entrance=FindLoopEntrance(&head);
	
	
	Traverse(&node0);
	/*Reverse(&node1);
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

	TestLinkList();

	int arr_int[11] = { 5, 4, 1, 9, 6, 3, 7, 10, 2, 11,8 };
	DoQuick_Sort(arr_int, 0, 10);
	//quicksort(arr_int, 0, 10);

	for (int i = 0; i < 11; ++i)
	{
		printf("%d ", arr_int[i]);
	}
	printf("\n");
	//system("pause");
	return EXIT_SUCCESS;
}