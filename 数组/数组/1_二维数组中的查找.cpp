

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
/*
https://cuijiahua.com/blog/2017/11/basis_1.html
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

*/

class Solution {
public:
	bool Find(int target, std::vector<std::vector<int>> array) {
		size_t rows = array.size();
		size_t cols = array[0].size();
		if (!array.empty() && rows > 0 && cols > 0) {
			size_t row = 0;
			size_t col = cols - 1;
			while (row < rows && col >= 0) {
				if (array[row][col] == target) {
					return true;
				}
				else if (array[row][col] > target) {
					--col;
				}
				else {
					++row;
				}
			}
		}
		return false;
	}
};

void example_1()
{

	//�˴�Ӧд������
	std::vector<std::vector<int>> array = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	Solution* s = new Solution;
	bool result;
	try
	{
		result = s->Find(7,array);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
