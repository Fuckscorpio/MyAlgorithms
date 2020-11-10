#include <exception>
#include <iostream>

/*
https://cuijiahua.com/blog/2017/11/basis_7.html

��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���n<=39��

*/
class Solution {
public:
	int Fibonacci(int n) 
	{
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		int first = 0, second = 1, third = 0;
		for (int i = 2; i <= n; i++) 
		{
			third = first + second;
			first = second;
			second = third;
		}
		return third;
	}
};

void example_1()
{
	
	
	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->Fibonacci(10);

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

