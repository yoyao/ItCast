#include"LinkList.h"

LinkList* InitLinkList()
{
	LinkList* list = calloc(1, sizeof(LinkList));
	if (NULL != list)
	{
		list->Count = 0;
		list->Header.Data = NULL;
		list->Header.Next = NULL;
		list->Tail = NULL;
	}
	return list;
}


int InsertLinkList(LinkList* list, int pos, void* data, int size)
{
	int sign = 0;
	ListNode* pcur = list->Header.Next;
	if (pos == HEADINSERT)
	{
		pos = 0;
	}
	
	ListNode* node = (ListNode*)calloc(1, sizeof(ListNode));
	node->Data = calloc(1, size);
	memcpy(node->Data, data, size);

	if (pcur == NULL)//头节点的下一个节点为NULL的话 就是刚初始化 还没有任何数据
	{
		node->Next = NULL;
		pcur = node;
		list->Tail = pcur;
		++list->Count;
		return 1;
	}


	if (pos == TAILINSERT)
	{
		node->Next = NULL;
		list->Tail->Next = node;
		list->Tail = node;
		++list->Count;
		return 1;
	}

	for (int i = 0; i < pos&&pcur->Next != NULL; ++i)
	{
		pcur = pcur->Next;
	}

	node->Next = pcur->Next;
	pcur->Next = node;

	
	++list->Count;
	++sign;


	for (int i = pos; i < list->Count&&pcur->Next != NULL; ++i)
	{
		pcur = pcur->Next;
	}
	list->Tail = pcur;

	return sign;
}


void TraverseLinList(LinkList* list, void(*PFUN)(void*))
{
	ListNode* node = list->Header.Next;
	while (node)
	{
		PFUN(node->Data);
		node = node->Next;
	}
}
int RemoveNodeByPos(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}

}
int ClearLinkList(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	ListNode* node = list->Header.Next;
	while (node)
	{
		if (node->Data)
		{
			free(node->Data);
		}
		ListNode* p = node->Next;
		free(node);
		node = p;
	}

}
int DestroyLinkList(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	ClearLinkList(list);
	free(list);
}