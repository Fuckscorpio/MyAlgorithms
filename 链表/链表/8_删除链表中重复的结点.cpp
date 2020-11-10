

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

https://cuijiahua.com/blog/2018/01/basis_56.html
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5��


*/

namespace example_space_8
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

using namespace example_space_8;

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL) {
			return NULL;
		}
		// ָ��ǰ���ǰ������ʹ��Ĳ��ظ����
		ListNode* pPre = NULL;
		// ָ��ǰ����Ľ��
		ListNode* pCur = pHead;
		// ָ��ǰ������Ľ��
		ListNode* pNext = NULL;

		while (pCur != NULL)
		{
			// �����ǰ�������һ�������ͬ
			if (pCur->next != NULL && pCur->val == pCur->next->val) 
			{
				pNext = pCur->next;
				// �ҵ����ظ������һ�����λ��
				while (pNext->next != NULL && pNext->next->val == pCur->val) 
				{
					pNext = pNext->next;
				}
				// ���pCurָ�������е�һ��Ԫ�أ�pCur -> ... -> pNext ->... 
				// Ҫɾ��pCur��pNext, ��ָ�������һ��Ԫ�ص�ָ��pHeadָ��pNext->next��
				if (pCur == pHead) 
				{
					pHead = pNext->next;
				}
				// ���pCur��ָ�������е�һ��Ԫ�أ�pPre -> pCur ->...->pNext ->... 
				// Ҫɾ��pCur��pNext����pPre->next = pNext->next
				else 
				{
					pPre->next = pNext->next;
				}
				// ��ǰ�ƶ�
				pCur = pNext->next;
			}
			// �����ǰ�������һ����㲻��ͬ
			else 
			{
				pPre = pCur;
				pCur = pCur->next;
			}
		}
		return pHead;
	}
};

void main()
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
		ret = s->deleteDuplication((ListNode*)list);
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
