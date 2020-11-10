#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*


https://cuijiahua.com/blog/2018/01/basis_57.html

����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣


���һ�����������������ô������һ�������������������������ӽ�㡣

û�������������Ρ��������������������ӽ�㣬��ô������һ�����������ĸ����


���һ������û�������������������Ǹ��������ӽ�㣬
����ָ�򸸽���ָ��һֱ���ϱ�����ֱ���ҵ�һ���������������ӽ��Ľ�㡣
��������Ľ����ڣ���ô������ĸ�����������Ҫ�ҵ���һ����㡣
*/








struct TreeLinkNode 
{
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL) {
			return NULL;
		}
		TreeLinkNode* pNext = NULL;
		// ��ǰ���������������ô������һ�������������������������ӽ��
		if (pNode->right != NULL) {
			TreeLinkNode* pRight = pNode->right;
			while (pRight->left != NULL) {
				pRight = pRight->left;
			}
			pNext = pRight;
		}
		// ��ǰ�����������������Ҫ�ҵ�һ���������������������Ľ��
		else if (pNode->next != NULL) {
			// ��ǰ���
			TreeLinkNode* pCur = pNode;
			// ���ڵ�
			TreeLinkNode* pPar = pNode->next;
			while (pPar != NULL && pCur == pPar->right) {
				pCur = pPar;
				pPar = pCur->next;
			}
			pNext = pPar;
		}
		return pNext;
	}
};


//�˴�û�й���������������г���
void example_8()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeLinkNode*  pRoot1 = NULL;
	
	Solution* s = new Solution;
	TreeLinkNode* ret;
	try
	{

		ret = s->GetNext(pRoot1);

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
