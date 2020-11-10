#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*

https://cuijiahua.com/blog/2018/01/basis_38.html


����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�


�����������ȡ������ǵݹ�ķ���������DFS�����������������
��һ�ַ����ǰ��ղ�α���������BFS�����������������

*/





struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

//DFS,�ݹ� �����������
class Solution 
{
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL) 
		{
			return 0;
		}
		//�������нڵ�
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return (left > right) ? (left + 1) : (right + 1);
	}
};


//BFS�����������
/*
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL) 
		{
			return 0;
		}
		std::queue<TreeNode*> que;
		int depth = 0;
		que.push(pRoot);
		
		//ÿ����һ���1
		while (!que.empty()) 
		{
			int size = que.size();
			depth++;
			for (int i = 0; i < size; i++) 
			{
				TreeNode* node = que.front();
				que.pop();
				if (node->left) 
				{
					que.push(node->left);
				}
				if (node->right) 
				{
					que.push(node->right);
				}
			}
		}
		return depth;
	}
};
*/
//�˴�û�й���������������г���
void example_6()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode* pRoot1 = NULL;
	TreeNode* pRoot2 = NULL;
	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->TreeDepth(pRoot1);

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
