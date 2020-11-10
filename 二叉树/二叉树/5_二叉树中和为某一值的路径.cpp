#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*

https://cuijiahua.com/blog/2017/12/basis_24.html


����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����


�������������
ʹ��ǰ�������ʹ������ȫ�ֱ���result��tmp��result��������ս����tmp���������ʱ�����
ÿ�α����������Ȱ�root��ֵѹ��tmp��Ȼ���жϵ�ǰroot�Ƿ�ͬʱ���㣺

�������ֵ���Ϊ0��
������Ϊ�գ�
������Ϊ�ա�


*/




struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {}
};
class Solution 
{
public:
	std::vector<std::vector<int> > FindPath(TreeNode* root, int expectNumber)
	{
		if (root == NULL) 
		{
			return result;
		}

		tmp.push_back(root->val);
		if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL) {
			result.push_back(tmp);
		}

		//����������
		FindPath(root->left, expectNumber - root->val);
		//����������
		FindPath(root->right, expectNumber - root->val);

		tmp.pop_back();
		return result;
	}
private:
	std::vector<std::vector<int> > result;
	std::vector<int> tmp;
};


//�˴�û�й���������������г���
void example_5()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode* pRoot1 = NULL;
	TreeNode* pRoot2 = NULL;
	Solution* s = new Solution;
	std::vector<std::vector<int> > ret;
	try
	{

		ret = s->FindPath(pRoot1,20);

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
