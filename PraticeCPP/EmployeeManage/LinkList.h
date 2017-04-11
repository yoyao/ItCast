#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Tools\memwatch.h"

#ifdef __cplusplus
extern "C"{
#endif

	//ͷ�巨
#define HEADINSERT 0
	//β�巨
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
	��ʼ������������һ������
	*/
	LinkList* InitLinkList();
	/*
	��һ�������ָ��λ�ò���ڵ�
	*/
	int InsertLinkList(LinkList* list,int pos,void* data,int size);
	/*
	ͨ��λ���Ƴ�һ���ڵ�
	*/
	int RemoveNodeByPos(LinkList* list, int pos);
	/*
	ͨ��Vlaue�Ƴ�һ���ڵ� ͨ������ָ�뷵�ش�����ֵ�Ƚ��Ƿ����
	*/
	int RemoveNodeByValue(LinkList* list, void* value, int(*CompFUN)(void*, void*));
	/*
	ͨ��ValueѰ�ҷ��ϻص�������ֵ��
	*/
	ListNode* FindNodeByValue(LinkList* list, void* value, int(*FindFUN)(void*, void*));
	/*
	��սڵ㣬ֻ����ͷ�ڵ�*/
	int ClearLinkList(LinkList** list);
	/*
	���ٽڵ� �ڵ�����ÿ�
	*/
	int DestroyLinkList(LinkList** list);
	/*
	ͨ�������ĺ���ָ�� �����ڵ�
	*/
	void TraverseLinList(LinkList* list, void(*PFUN)(void*));

#ifdef __cplusplus
}
#endif