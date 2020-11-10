#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
/*


https://cuijiahua.com/blog/2017/11/basis_11.html

����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��



*/

class Solution
{
public:
	int  NumberOf1(int n) 
	{
		int count = 0;
		while (n) 
		{
			++count;
			n = (n - 1) & n;
		}
		return count;
	}
};
//�˴�û�й���������������г���
void example_1()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	int  pRoot1 = 25;

	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->NumberOf1(pRoot1);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << ret << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
