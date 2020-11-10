#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
/*


https://cuijiahua.com/blog/2017/12/basis_19.html

����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ������
array[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}
�����δ�ӡ�����飺1��2��3��4��8��12��16��15��14��13��9��5��6��7��11��10��

���������vector���飬�����ң��ٴ��ϵ��£��ٴ��ҵ��������µ��ϱ�����

*/

class Solution {
public:
	std::vector<int> printMatrix(std::vector<std::vector<int> > matrix) {
		std::size_t rows = matrix.size();			//����
		std::size_t cols = matrix[0].size();		//����
		std::vector<int> result;

		if (rows == 0 && cols == 0) {
			return result;
		}
		int left = 0, right = static_cast<int>(cols - 1), top = 0, bottom = static_cast<int>(rows - 1);

		while (left <= right && top <= bottom) {
			//������
			for (int i = left; i <= right; ++i) {
				result.push_back(matrix[top][i]);
			}
			//���ϵ���
			for (int i = top + 1; i <= bottom; ++i) {
				result.push_back(matrix[i][right]);
			}
			//���ҵ���
			if (top != bottom) {
				for (int i = right - 1; i >= left; --i) {
					result.push_back(matrix[bottom][i]);
				}
			}
			//���µ���
			if (left != right) {
				for (int i = bottom - 1; i > top; --i) {
					result.push_back(matrix[i][left]);
				}
			}
			left++, top++, right--, bottom--;
		}
		return result;
	}
};



void example_3()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<std::vector<int> >  pRoot1 = { {1,2,3,4} ,{5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	
	Solution* s = new Solution;
	std::vector<int> ret;
	try
	{

		ret = s->printMatrix(pRoot1);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
