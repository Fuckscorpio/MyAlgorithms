#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
/*


https://cuijiahua.com/blog/2018/01/basis_62.html

����һ�Ŷ��������������ҳ����еĵ�k��Ľ�㡣���磬����ͼ�У��������ֵ��С˳�����������ֵΪ4��


//����������
ÿ�����ڵ㶼�������ӽڵ㣨�ӽڵ����Ϊ�գ������ӽڵ�ȸ��ڵ�С�����ӽڵ�ȸ��ڵ��
�����ֵ<������ֵ<�ҽ���ֵ


ʹ�������������õ�������ʽΪ{2,3,4,5,6,7,8}����ˣ�ֻ��Ҫ���������һ�ö������������ͺ������ҳ����ĵ�k���㡣
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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k == 0) {
			return NULL;
		}
		return KthNodeCore(pRoot, k);
	}
private:
	TreeNode* KthNodeCore(TreeNode* pRoot, int &k) {
		TreeNode* target = NULL;
		// �ȱ�������
		if (pRoot->left != NULL) {
			target = KthNodeCore(pRoot->left, k);
		}
		// ���û���ҵ�target���������Сk�����k����1��˵�����˵�k�����
		if (target == NULL) {
			if (k == 1) {
				target = pRoot;
			}
			k--;
		}
		// ���û���ҵ�target���������ҽ��
		if (pRoot->right != NULL && target == NULL) {
			target = KthNodeCore(pRoot->right, k);
		}
		return target;
	}
};

//�˴�δ�������������������ͨ����δ����
void main()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode*   pRoot1 = NULL;

	Solution* s = new Solution;
	TreeNode* ret;
	try
	{

		ret = s->KthNode(pRoot1,3);

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
