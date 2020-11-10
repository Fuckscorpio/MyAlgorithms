#include <exception>
#include <iostream>

/*
https://cuijiahua.com/blog/2017/11/basis_8.html

һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������

��n>2ʱ����һ������ʱ��������ֲ�ͬ��ѡ��һ�ǵ�һ��ֻ��1����
��ʱ������Ŀ���ں���ʣ�µ�n-1��̨�׵�������Ŀ����Ϊf(n-1)��
����һ��ѡ������һ����2������ʱ������Ŀ���ں���ʣ�µ�n-2��̨�׵�������Ŀ����Ϊf(n-2)��
���n��̨�׵Ĳ�ͬ����������f(n)=f(n-1)+f(n-2)��������������ǲ��ѿ�����ʵ���Ͼ���쳲����������ˡ�

*/
class Solution {
public:
	int jumpFloor(int number) 
	{
		if (number <= 0) {
			return 0;
		}
		else if (number < 3) 
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

void example_2()
{


	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->jumpFloor(10);

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

