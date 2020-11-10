#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*


https://cuijiahua.com/blog/2018/01/basis_58.html

��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�


ǰ�������������
���Զ���һ�������㷨���ȱ������ӽ���ٱ������ӽ�㣬���ҳ���Ϊǰ������ĶԳƱ�����
����ҲҪ����NULLָ��
*/



struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL) {
			return true;
		}
		return isSymmetriacalCor(pRoot, pRoot);
	}
private:
	bool isSymmetriacalCor(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot1 == NULL && pRoot2 == NULL) {
			return true;
		}
		if (pRoot1 == NULL || pRoot2 == NULL) {
			return false;
		}
		if (pRoot1->val != pRoot2->val) {
			return false;
		}
		return isSymmetriacalCor(pRoot1->left, pRoot2->right) && isSymmetriacalCor(pRoot1->right, pRoot2->left);
	}
};

//�˴�û�й���������������г���
void example_9()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode*   pRoot1 = NULL;

	Solution* s = new Solution;
	bool ret;
	try
	{

		ret = s->isSymmetrical(pRoot1);

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
