#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
/*


https://cuijiahua.com/blog/2017/12/basis_23.html

����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes���������No���������������������������ֶ�������ͬ��

//����������
ÿ�����ڵ㶼�������ӽڵ㣨�ӽڵ����Ϊ�գ������ӽڵ�ȸ��ڵ�С�����ӽڵ�ȸ��ڵ��

//�������
���Ҹ�

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
	bool VerifySquenceOfBST(std::vector<int> sequence) {
		return bst(sequence, 0, static_cast<int>(sequence.size() - 1));
	}
private:
	bool bst(std::vector<int> seq, int begin, int end) {
		if (seq.empty() || begin > end) {
			return false;
		}

		//�����
		int root = seq[end];

		//�ڶ������������������Ľ��С�ڸ����
		int i = begin;
		for (; i < end; ++i) {
			if (seq[i] > root) {
				break;
			}
		}

		//�ڶ������������������Ľ����ڸ����
		for (int j = i; j < end; ++j) {
			if (seq[j] < root) {
				return false;
			}
		}

		//�ж��������ǲ��Ƕ���������
		bool left = true;
		if (i > begin) {
			left = bst(seq, begin, i - 1);
		}

		//�ж��������ǲ��Ƕ���������
		bool right = true;
		if (i < end - 1) {
			right = bst(seq, i, end - 1);
		}

		return left && right;
	}
};


void example_1()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>   pRoot1 = {5,7,6,9,11,10,8};

	Solution* s = new Solution;
	bool ret;
	try
	{

		ret = s->VerifySquenceOfBST(pRoot1);

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
