#include <exception>
#include <iostream>

/*
https://cuijiahua.com/blog/2017/11/basis_9.html

һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������

��n=1ʱ�����Ϊ1��
��n=2ʱ�����Ϊ2��
��n=3ʱ�����Ϊ4��
�Դ����ƣ�����ʹ����ѧ���ɷ����ѷ��֣�����f(n)=2^(n-1)��

*/
class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 0) {
			return 0;
		}
		int total = 1;
		for (int i = 1; i < number; i++) {
			total *= 2;
		}
		return total;
	}
};

void example_3()
{


	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->jumpFloorII(10);

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

