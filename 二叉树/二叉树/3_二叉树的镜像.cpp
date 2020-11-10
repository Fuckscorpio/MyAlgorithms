#include <stack>
#include <exception>
#include <iostream>
#include <vector>
/*

https://cuijiahua.com/blog/2017/12/basis_18.html

���������Ķ�����������任ΪԴ�������ľ���

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
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if ((pRoot == NULL) || (pRoot->left == NULL && pRoot->right == NULL)) {
			return;
		}

		//�������ڵ�����ҽ��
		TreeNode *pTemp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = pTemp;

		//�ݹ�������
		if (pRoot->left) {
			Mirror(pRoot->left);
		}
		//�ݹ�������
		if (pRoot->right) {
			Mirror(pRoot->right);
		}
	}
};

//�˴�û�й���������������г���
void example_3()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode *pRoot = NULL;
	Solution* s = new Solution;
	
	try
	{

		 s->Mirror(pRoot);

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
