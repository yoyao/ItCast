#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Tools\memwatch.h"

#ifdef __cplusplus
extern "C"{
#endif

	//头插法
#define HEADINSERT 0
	//尾插法
#define TAILINSERT -1

	typedef struct _listnode ListNode;

	struct _listnode{
		void* Data;
		ListNode* Next;
	};

	typedef struct _linklist LinkList;

	struct _linklist{
		ListNode Header;
		int Count;
		ListNode* Tail;
	};


	/*
	初始化（即创建）一个链表
	*/
	LinkList* InitLinkList();
	/*
	向一个链表的指定位置插入节点
	*/
	int InsertLinkList(LinkList* list,int pos,void* data,int size);
	/*
	通过位置移除一个节点
	*/
	int RemoveNodeByPos(LinkList* list, int pos);
	/*
	通过Vlaue移除一个节点 通过函数指针返回此两个值比较是否相等
	*/
	int RemoveNodeByValue(LinkList* list, void* value, int(*CompFUN)(void*, void*));
	/*
	通过Value寻找符合回掉函数的值。
	*/
	ListNode* FindNodeByValue(LinkList* list, void* value, int(*FindFUN)(void*, void*));
	/*
	清空节点，只保留头节点*/
	int ClearLinkList(LinkList** list);
	/*
	销毁节点 节点最后置空
	*/
	int DestroyLinkList(LinkList** list);
	/*
	通过给定的函数指针 遍历节点
	*/
	void TraverseLinList(LinkList* list, void(*PFUN)(void*));

#ifdef __cplusplus
}
#endif