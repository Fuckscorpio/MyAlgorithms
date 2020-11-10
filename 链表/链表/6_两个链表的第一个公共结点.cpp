

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

https://cuijiahua.com/blog/2018/01/basis_36.html
�������������ҳ����ǵĵ�һ��������㡣

�������ðѳ��������ͷ��������������������ͬ��������
ͬʱ����Ҳ���ҵ�������㡣��ʱ��ʱ�临�Ӷ�O(m+n)���ռ临�Ӷ�ΪO(MAX(m,n))��

*/

namespace example_space_6
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

using namespace example_space_6;

class Solution 
{
public:
	
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
	{
		// �����һ������Ϊ�գ��򷵻ؽ��Ϊ��
		if (pHead1 == NULL || pHead2 == NULL) {
			return NULL;
		}
		// �����������ĳ���
		unsigned int len1 = GetListLength(pHead1);
		unsigned int len2 = GetListLength(pHead2);
		
		// Ĭ�� pHead1 ���� pHead2�̣�������ǣ��ٸ���
		ListNode* pHeadLong = pHead1;
		ListNode* pHeadShort = pHead2;
		int LengthDif = len1 - len2;
		// ��� pHead1 �� pHead2 С
		if (len1 < len2) {
			ListNode* pHeadLong = pHead2;
			ListNode* pHeadShort = pHead1;
			int LengthDif = len2 - len1;
		}
		// ���������ǰ�沿��ȥ����ʹ��������ȳ�
		for (int i = 0; i < LengthDif; i++) {
			pHeadLong = pHeadLong->next;
		}

		while (pHeadLong != NULL && pHeadShort != NULL && pHeadLong != pHeadShort) {
			pHeadLong = pHeadLong->next;
			pHeadShort = pHeadShort->next;
		}
		return pHeadLong;
	}
private:
	// ���������
	unsigned int GetListLength(ListNode* pHead) 
	{
		if (pHead == NULL) 
		{
			return 0;
		}
		unsigned int length = 1;
		while (pHead->next != NULL) 
		{
			pHead = pHead->next;
			length++;
		}
		return length;
	}
};

void example_6()
{

	//�˴�Ӧд������
	//�����������Ҫ��
	//Ĭ������ͷ��һ��0
	LinkList* list = Create_LinkList();
	Insert_LinkList(list, &ListNode(3));
	Insert_LinkList(list, &ListNode(5));
	Insert_LinkList(list, &ListNode(7));
	Insert_LinkList(list, &ListNode(9));


	LinkList* list1 = Create_LinkList();
	Insert_LinkList(list, &ListNode(11));
	Insert_LinkList(list, &ListNode(13));
	Insert_LinkList(list, &ListNode(15));
	Insert_LinkList(list, &ListNode(17));

	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	ListNode *ret;


	try
	{
		ret = s->FindFirstCommonNode((ListNode*)list, (ListNode*)list1);
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
