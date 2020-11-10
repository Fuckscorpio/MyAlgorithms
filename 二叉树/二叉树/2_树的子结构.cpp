#include <stack>
#include <exception>
#include <iostream>
#include <vector>
/*

https://cuijiahua.com/blog/2017/12/basis_17.html

�������Ŷ�����A��B���ж�B�ǲ���A���ӽṹ����PS������Լ��������������һ�������ӽṹ����

ǰ��������ȷ��ʸ���㣬�ٷ������ӽ�㣬���������ӽ�㡣
����������ȷ������ӽ�㣬�ٷ��ʸ���㣬���������ӽ�㡣
����������ȷ������ӽ�㣬�ٷ������ӽ�㣬�����ʸ���㡣


��һ������A���ҵ���B�ĸ�����ֵһ���Ľ��R��
�ڶ������ж���A����RΪ���ڵ�������ǲ��ǰ�������Bһ���Ľṹ��
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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL && pRoot2 != NULL) 
		{
			if (pRoot1->val == pRoot2->val) {
				result = DoesTree1HasTree2(pRoot1, pRoot2);
			}
			if (!result) {
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!result) {
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}
private:
	bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL) {
			return true;
		}
		if (pRoot1 == NULL) {
			return false;
		}
		if (pRoot1->val != pRoot2->val) {
			return false;
		}
		return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};


//�˴�û�й���������������г���
void example_2()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode* pRoot1 = NULL;
	TreeNode* pRoot2 = NULL;
	Solution* s = new Solution;
	bool ret;
	try
	{

		ret = s->HasSubtree(pRoot1, pRoot2);

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
