#include"LinkList.h"
#include"Administrator.h"

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
	ListNode* pcur = &(list->Header);
	if (pos == HEADINSERT)
	{
		pos = 0;
	}
	
	ListNode* node = (ListNode*)calloc(1, sizeof(ListNode));
	node->Data = calloc(1, size);
	memcpy(node->Data, data, size);

	if (pos == TAILINSERT)
	{
		node->Next = NULL;
		if (list->Tail == NULL)
		{
			list->Header.Next = node;//尾节点为空的话 就是链表刚初始化 直接首尾节点都设为新节点
			list->Tail = node;
		}
		else
		{    //Administrator* add = (Administrator*)list->Tail->Data;
			//add = (Administrator*)n->Data;
			//add = (Administrator*)list->Tail->Data;
			ListNode* n = list->Tail;
			n->Next = node;
			list->Tail = node;
		}
		++list->Count;
		return 1;
	}

	for (int i = 1; i < pos&&pcur->Next != NULL; ++i)
	{
		pcur = pcur->Next;
	}
	node->Next = pcur->Next;
	pcur->Next = node;
	
	++list->Count;
	++sign;
	//重新寻找尾指针
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
	//printf("count is:%d\n", list->Count);
}

int RemoveNodeByPos(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return -1;
	}

	if (pos<0 || pos>list->Count)
	{
		return -1;
	}

	ListNode* pcur = &(list->Header);
	// 1 2 3 4 5 6
	for (int i = 1; i < pos; ++i)
	{
		pcur = pcur->Next;//此循环要找到要删除节点的上一个节点 以防直接删除要删除的节点致前后节点丢失。
	}
	ListNode* tmp = pcur->Next->Next;//记录删除节点的下一个节点

	if (pcur->Next)//Next节点即要删除的节点
	{
		if (pcur->Next->Data)
		{
			free(pcur->Next->Data);
		}
		free(pcur->Next);
	}

	pcur->Next = tmp;

	if (pos == list->Count)
	{
		list->Tail = pcur;
	}

	--(list->Count);//最后count减1  要是先减1 上面的判断就不准确了。
	return 1;
}

int RemoveNodeByValue(LinkList* list, void* data, int(*CompFUN)(void*, void*))
{
	if (NULL == list || data==NULL)
	{
		return -1;
	}
	int sign = 0;
	ListNode* node = &(list->Header);
	ListNode* tail = list->Tail;
	if (CompFUN(tail->Data, data) == 1)//删除的是尾指针 这就要重新定位尾指针了。
	{
		sign = 1;
	}
	while (node->Next)
	{
		if (CompFUN(node->Next->Data, data) == 1)
		{
			ListNode* ptmp = node->Next->Next;
			free(node->Next->Data);
			free(node->Next);
			node->Next = ptmp;

			--(list->Count);
			if (sign == 1)
			{
				list->Tail = node;
			}
			return 1;
		}
		node = node->Next;
	}


	return 0;
}

ListNode* FindNodeByValue(LinkList* list, void* data, int(*FindFUN)(void*, void*))
{
	if (NULL == list || data == NULL || FindFUN == NULL)
	{
		return NULL;
	}
	ListNode* node = list->Header.Next;

	while (node !=NULL&&FindFUN(data,node->Data) != 1)
	{
		node = node->Next;
	}
	return node;
}

int ClearLinkList(LinkList** list)
{
	if (list == NULL)
	{
		return -1;
	}
	if (*list == NULL)
	{
		return -1;
	}
	ListNode* node = (*list)->Header.Next;
	while (node !=NULL)
	{
		if (node->Data)
		{
			free(node->Data);
			node->Data = NULL;
		}
		node = node->Next;
	}
	node = (*list)->Header.Next;

	while (node != NULL)
	{
		ListNode* p = node->Next;
		free(node);
		node = p;
		--((*list)->Count);
	}

	return (*list)->Count;
}

int DestroyLinkList(LinkList** list)
{
	if (*list == NULL)
	{
		return -1;
	}
	int count=ClearLinkList(list);
	free(*list);
	*list = NULL;
	return count;
}




//链表的冒泡排序
void ListBubbleSort(LinkList* list, int(*Compare)(void*, void*))
{

	if (list == NULL || list->Header.Next == NULL)
	{
		return;
	}

	ListNode* pcur = list->Header.Next;

	while (pcur != NULL)
	{
		ListNode* next = pcur->Next;
		while (next != NULL)
		{
			if (Compare(pcur->Data, next->Data) == 1)//前大于后
			{
				void * p_tmp = pcur->Data;
				pcur->Data = next->Data;
				next->Data = p_tmp;
			}
			next = next->Next;
		}
		pcur = pcur->Next;
	}






}