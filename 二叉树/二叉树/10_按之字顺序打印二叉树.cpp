#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
/*


https://cuijiahua.com/blog/2018/01/basis_59.html

��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
�ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�


��Ҫʹ������ջ�������ڴ�ӡĳһ�н��ʱ������һ����ӽ�㱣�浽��Ӧ��ջ�
�����ǰ��ӡ���������㣨��һ�㡢������ȣ������ȱ�������������ٱ�����������㵽��һ��ջ�
�����ǰ��ӡ����ż���㣨�ڶ��㡢���Ĳ�ȣ��������ȱ�������������ٱ�����������㵽�ڶ���ջ�
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
	std::vector<std::vector<int> > Print(TreeNode* pRoot) {
		std::vector<std::vector<int> > result;
		if (pRoot == NULL) {
			return result;
		}
		std::stack<TreeNode* > s[2];
		s[0].push(pRoot);
		while (!s[0].empty() || !s[1].empty()) {
			std::vector<int> v[2];
			// ż����
			while (!s[0].empty()) {
				v[0].push_back(s[0].top()->val);
				if (s[0].top()->left != NULL) {
					s[1].push(s[0].top()->left);
				}
				if (s[0].top()->right != NULL) {
					s[1].push(s[0].top()->right);
				}
				s[0].pop();
			}
			if (!v[0].empty()) {
				result.push_back(v[0]);
			}
			// ������
			while (!s[1].empty()) {
				v[1].push_back(s[1].top()->val);
				if (s[1].top()->right != NULL) {
					s[0].push(s[1].top()->right);
				}
				if (s[1].top()->left != NULL) {
					s[0].push(s[1].top()->left);
				}
				s[1].pop();
			}
			if (!v[1].empty()) {
				result.push_back(v[1]);
			}
		}
		return result;
	}
};

//�˴�û�й���������������г���
void example_10()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode*   pRoot1 = NULL;

	Solution* s = new Solution;
	std::vector<std::vector<int> > ret;
	try
	{

		ret = s->Print(pRoot1);

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
