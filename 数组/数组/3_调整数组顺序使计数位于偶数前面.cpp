

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <deque>
/*
https://cuijiahua.com/blog/2017/11/basis_13.html
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣

//����˫����У��������飬����ǰ���룬ż������롣���ʹ��assign����ʵ�ֲ�ͬ���������ݵ����͸�ֵ��
*/

class Solution {
public:
	void reOrderArray(std::vector<int> &array)
	{
		std::deque<int> result;
		size_t num = array.size();
		for (size_t i = 0; i < num; i++) 
		{
			//�����Ӻ����
			if (array[num - i - 1] % 2 == 1) 
			{
				result.push_front(array[num - i - 1]);
			}
			//ż����ǰ����
			if (array[i] % 2 == 0) {
				result.push_back(array[i]);
			}
		}
		//ʵ�ֲ�ͬ���������ݵ����͸�ֵ��
		array.assign(result.begin(), result.end());
	}
};
void example_3()
{

	//�˴�Ӧд������
	std::vector<int> array = { 9,7,8,3,4,5 };
	Solution* s = new Solution;
	int result =0;
	try
	{
		result = 0;
		s->reOrderArray(array);
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
