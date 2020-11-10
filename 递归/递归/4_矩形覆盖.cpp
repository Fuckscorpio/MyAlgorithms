#include <exception>
#include <iostream>

/*
https://cuijiahua.com/blog/2017/11/basis_10.html

���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

�����ŷŵ�ʱ���ұ߻�ʣ��2x7��������������µĸ��Ƿ�����Ϊf(7)�����������Ǻ��ŷŵ��������1x2��С���κ��ŷ������Ͻǵ�ʱ�����½Ǻͺ��ŷ�һ��1x2��С���Σ�
�����ұ߻�ʣ��2x6��������������µĸ��Ƿ�����Ϊf(6)�����f(8)=f(7)+f(6)����ʱ���ǿ��Կ���������Ȼ��쳲��������С�

*/
class Solution {
public:
	int rectCover(int number)
	{
		if (number <= 2)
		{
			return number;
		}
		int first = 1, second = 2, third = 0;
		for (int i = 3; i <= number; i++)
		{
			third = first + second;
			first = second;
			second = third;
		}
		return third;
	}
};

void main()
{


	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->rectCover(10);

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

