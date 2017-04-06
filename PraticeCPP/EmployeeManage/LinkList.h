
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifdef __cplusplus
extern "C"{
#endif
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
	//ͷ�巨
#define HEADINSERT 0
	//β�巨
#define TAILINSERT -1

	LinkList* InitLinkList();
	int InsertLinkList(LinkList* list,int pos,void* data,int size);
	int RemoveNodeByPos(LinkList* list, int pos);
	int ClearLinkList(LinkList* list);
	int DestroyLinkList(LinkList* list);
	void TraverseLinList(LinkList* list, void(*PFUN)(void*));

#ifdef __cplusplus
}
#endif