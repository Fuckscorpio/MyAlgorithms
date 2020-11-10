

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_32.html
����һ�����������飬����������������ƴ�������ų�һ������
��ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}��
���ӡ���������������ųɵ���С����Ϊ321323��


*/

class Solution {
public:
	std::string PrintMinNumber(std::vector<int> numbers) {
		size_t length = numbers.size();
		if (length == 0) {
			return "";
		}
		sort(numbers.begin(), numbers.end(), cmp);
		std::string res;
		for (size_t i = 0; i < length; i++) {
			res += std::to_string(numbers[i]);
		}
		return res;
	}
private:
	// ��������
	static bool cmp(int a, int b) {
		std::string A = std::to_string(a) + std::to_string(b);
		std::string B = std::to_string(b) + std::to_string(a);
		return A < B;
	}
};
void example_6()
{

	//�˴�Ӧд������
	std::vector<int> array = { 3,32,321 };
	Solution* s = new Solution;
	std::string result;
	try
	{
		result = s->PrintMinNumber(array);
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
