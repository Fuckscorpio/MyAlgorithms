#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable: 4800)
/*

����һ�ö��������жϸö������Ƿ���ƽ���������


ƽ��������Ķ����ǣ���ν��ƽ��֮�⣬������������һ��������������������ĸ߶Ȳ���� 1��


�ظ�������Σ�
�ڱ�������ÿ������ʱ�򣬵��ú���TreeDepth�õ�����������������ȡ����ÿ���������������������������1��
������һ��ƽ��Ķ����������ַ�����ȱ���ǣ������жϸ�����ǲ���ƽ��ģ���Ҫʹ��TreeDepth���������������ȣ�
Ȼ����Ҫ�����ж������ǲ���ƽ��ģ�������Ҫʹ��TreeDepth���������������������ȣ������͵����˴������ظ�������

ֻ����һ�Σ�

�ظ�������Ӱ���㷨�����ܣ����Ժ��б�Ҫ���ղ���Ҫ�ظ������ķ�������������ú�������ķ�ʽ������������ÿһ����㣬
�ڱ�����һ�����֮ǰ���Ǿ��Ѿ���������������������ֻҪ�ڱ���ÿ������ʱ���¼������ȣ�ĳһ������ȵ�������Ҷ����·���ĳ��ȣ���
���ǾͿ���һ�߱���һ���ж�ÿ������ǲ���ƽ��ġ�

*/





struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

//����һ��
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) 
	{
		int depth = 0;
		return IsBalanced(pRoot, &depth);
	}
private:
	int IsBalanced(TreeNode* pRoot, int* depth) 
	{
		if (pRoot == NULL) 
		{
			*depth = 0;
			return true;
		}
		int left, right;
		if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)) 
		{
			int diff = left - right;
			if (diff <= 1 && diff >= -1) 
			{
				*depth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false;
	}
};



//�������
/*
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL) {
			return true;
		}
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		int diff = left - right;
		if (diff > 1 || diff < -1) {
			return false;
		}
		return IsBalanced_Solution(pRoot->right) && IsBalanced_Solution(pRoot->left);
	}
private:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL) {
			return 0;
		}
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return (left > right) ? (left + 1) : (right + 1);
	}
};

*/

//�˴�û�й���������������г���
void example_7()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode* pRoot1 = NULL;
	TreeNode* pRoot2 = NULL;
	Solution* s = new Solution;
	bool ret;
	try
	{

		ret = s->IsBalanced_Solution(pRoot1);

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
