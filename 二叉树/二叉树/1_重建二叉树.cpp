#include <stack>
#include <exception>
#include <iostream>
#include <vector>
/*

https://cuijiahua.com/blog/2017/11/basis_4.html

����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�

https://blog.csdn.net/qq_34840129/article/details/80619761
ǰ��������ȷ��ʸ���㣬�ٷ������ӽ�㣬���������ӽ�㡣
����������ȷ������ӽ�㣬�ٷ��ʸ���㣬���������ӽ�㡣
����������ȷ������ӽ�㣬�ٷ������ӽ�㣬�����ʸ���㡣


ǰ����������У���һ�������������ĸ�����ֵ����������������У�
������ֵ�����е��м䣬�������Ľ���ֵλ�ڸ�����ֵ����ߣ����������Ľ���ֵλ�ڸ�����ֵ���ұߡ�
*/

//Definition for binary tree
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
		if (pre.size() == 0) {					//���Ϊ�գ�����NULL
			return NULL;
		}
		//������ǰ�������������ǰ�����������������������������������������
		std::vector<int> left_pre, right_pre, left_vin, right_vin;
		//ǰ�������һ���ڵ�һ��Ϊ���ڵ�
		TreeNode* head = new TreeNode(pre[0]);
		//�ҵ���������ĸ��ڵ�
		int root = 0;
		//�����ҵ�����������ڵ�����ֵ
		for (int i = 0; i < pre.size(); i++) {
			if (pre[0] == vin[i]) {
				root = i;
				break;
			}
		}
		//������������ĸ��ڵ㣬�Զ������ڵ���й鲢
		for (int i = 0; i < root; i++) {
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]);			//ǰ�������һ��Ϊ���ڵ�
		}

		for (int i = root + 1; i < pre.size(); i++) {
			right_vin.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}

		//�ݹ飬�ٶ�������������в��裬��������������������������ֱ��Ҷ�ڵ�
		head->left = reConstructBinaryTree(left_pre, left_vin);
		head->right = reConstructBinaryTree(right_pre, right_vin);
		return head;
	}
};
void example_1()
{

	std::vector<int> array1 = { 1,2,4,7,3,5,6,8};
	std::vector<int> array2 = { 4,7,2,1,5,3,8,6};

	Solution* s = new Solution;
	TreeNode* ret;
	try
	{

		ret = s->reConstructBinaryTree(array1, array2);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout <<" " << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
