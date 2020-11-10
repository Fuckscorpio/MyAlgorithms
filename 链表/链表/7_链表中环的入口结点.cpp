

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

/*

https://cuijiahua.com/blog/2018/01/basis_55.html
һ�������а����������ҳ�������Ļ�����ڽ�㡣

˫ָ����У�

//ȷ�����Ľڵ�
����ʹ�ÿ���ָ�룬һ��ÿ����һ����һ��ÿ�����������������ָ�����������������д��ڻ�����������ָ�������Ľ��һ���ڻ��С�
������Ǿʹ�������������н�������һ�߼�����ǰ�ƶ�һ�߼��������ٴλص�������ʱ���Ϳ��Եõ����н����Ŀ�ˡ�
*/

namespace example_space_7
{
	struct ListNode
	{
		int val;
		struct ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	struct LinkList
	{
		ListNode head;
		int size;
	};

	LinkList* Create_LinkList() {
		LinkList* list = (LinkList*)malloc(sizeof(LinkList));
		list->size = 0;
		list->head.next = NULL;
		return list;
	}

	bool Insert_LinkList(LinkList* list, ListNode* data)
	{

		//�嵽β��
		int pos = list->size;
		ListNode* pCurrent = &(list->head);

		for (int i = 0; i < pos; i++)
		{
			pCurrent = pCurrent->next;
		}

		data->next = pCurrent->next;

		//pCurrent->val= data->val;
		pCurrent->next = data;
		(list->size)++;
		return true;
	}
}

using namespace example_space_7;

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL) {
			return NULL;
		}
		ListNode* meetingnode = MeetingNode(pHead);
		if (meetingnode == NULL) {
			return NULL;
		}
		// �ػ����������
		int nodesloop = 1;
		// �ҵ����н�����
		ListNode* pNode1 = meetingnode;
		while (pNode1->next != meetingnode)
		{
			pNode1 = pNode1->next;
			nodesloop++;
		}
		pNode1 = pHead;
		// ��һ��ָ����ǰ�ƶ�nodesloop��
		for (int i = 0; i < nodesloop; i++) 
		{
			pNode1 = pNode1->next;
		}
		// ����ָ��ͬʱ�ƶ����ҵ������
		ListNode* pNode2 = pHead;
		while (pNode1 != pNode2) {
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		return pNode1;
	}
private:
	// ʹ�ÿ���ָ�룬�ҵ������һ�����н��
	ListNode* MeetingNode(ListNode* pHead) 
	{
		ListNode* pSlow = pHead->next;
		if (pSlow == NULL) {
			return NULL;
		}
		ListNode* pFast = pSlow->next;
		while (pFast != NULL && pSlow != NULL) {
			if (pFast == pSlow) {
				return pFast;
			}
			pSlow = pSlow->next;
			pFast = pFast->next;
			if (pFast != NULL) {
				pFast = pFast->next;
			}
		}
		return NULL;
	}
};

void example_7()
{

	//�˴�Ӧд������
	//�����������Ҫ��
	//Ĭ������ͷ��һ��0
	LinkList* list = Create_LinkList();
	Insert_LinkList(list, &ListNode(3));
	Insert_LinkList(list, &ListNode(5));
	Insert_LinkList(list, &ListNode(7));
	Insert_LinkList(list, &ListNode(9));


	

	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	ListNode *ret;


	try
	{
		ret = s->EntryNodeOfLoop((ListNode*)list);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << " " << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
