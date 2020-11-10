

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
/*
https://cuijiahua.com/blog/2017/12/basis_28.html
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

///���Կ����ڱ��������ʱ�򱣴�����ֵ��һ���������һ�����֣�һ���Ǵ�����
///�����Ǳ�������һ�����ֵ�ʱ�������һ�����ֺ�����֮ǰ�����������ͬ���������1��
///�����һ�����ֺ�����֮ǰ��������ֲ�ͬ���������1���������Ϊ�㣬������Ҫ������һ�����֣����Ѵ�����Ϊ1��
///��������Ҫ�ҵ����ֳ��ֵĴ����������������ֳ��ֵĴ���֮�ͻ�Ҫ�࣬��ôҪ�ҵ����ֿ϶������һ�ΰѴ�����Ϊ1ʱ��Ӧ�����֡�
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(std::vector<int> numbers) {
		if (numbers.empty()) {
			return 0;
		}
		// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1
		int result = numbers[0];
		int times = 1;
		for (size_t i = 1; i < numbers.size(); ++i)
		{
			if (times == 0) 
			{
				// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
				result = numbers[i];
				times = 1;
			}
			else if (numbers[i] == result) 
			{
				times++;
			}
			else 
			{
				times--;
			}
		}
		// �ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��
		times = 0;
		for (size_t i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == result) {
				times++;
			}
		}
		return (times > (numbers.size() >> 1)) ? result : 0;
	}
};
void example_4()
{

	//�˴�Ӧд������
	std::vector<int> array = { 1,2,3,2,2,2,5,4,2 };
	Solution* s = new Solution;
	int result = 0;
	try
	{
		result = s->MoreThanHalfNum_Solution(array);
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
