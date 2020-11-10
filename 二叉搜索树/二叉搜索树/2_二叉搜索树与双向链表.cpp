#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
/*


https://cuijiahua.com/blog/2017/12/basis_26.html

����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��


//����������
ÿ�����ڵ㶼�������ӽڵ㣨�ӽڵ����Ϊ�գ������ӽڵ�ȸ��ڵ�С�����ӽڵ�ȸ��ڵ��
�����ֵ<������ֵ<�ҽ���ֵ


ʹ�ö�����������������������ݵ����򣬾��������˳��
*/


struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		//���ڼ�¼˫������β���
		TreeNode* pLastNodeInList = NULL;

		//��ʼת�����
		ConvertNode(pRootOfTree, &pLastNodeInList);

		//pLastNodeInListָ��˫�������β��㣬������Ҫ���·���ͷ���
		TreeNode* pHeadOfList = pLastNodeInList;
		while (pHeadOfList != NULL && pHeadOfList->left != NULL) {
			pHeadOfList = pHeadOfList->left;
		}
		return pHeadOfList;
	}

	void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList) {
		//Ҷ���ֱ�ӷ���
		if (pNode == NULL) {
			return;
		}
		TreeNode* pCurrent = pNode;
		//�ݹ�������
		if (pCurrent->left != NULL)
			ConvertNode(pCurrent->left, pLastNodeInList);

		//��ָ��
		pCurrent->left = *pLastNodeInList;
		//��ָ��
		if (*pLastNodeInList != NULL) {
			(*pLastNodeInList)->right = pCurrent;
		}
		//����˫������β���
		*pLastNodeInList = pCurrent;
		//�ݹ�������
		if (pCurrent->right != NULL) {
			ConvertNode(pCurrent->right, pLastNodeInList);
		}
	}
};

//�˴�δ�������������������ͨ����δ����
void example_2()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode*   pRoot1 = NULL;

	Solution* s = new Solution;
	TreeNode* ret;
	try
	{

		ret = s->Convert(pRoot1);

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
