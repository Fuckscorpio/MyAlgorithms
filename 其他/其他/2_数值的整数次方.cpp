#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
/*


https://cuijiahua.com/blog/2017/11/basis_12.html

����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���

����ֱ���õȺţ�==���ж�����С���Ƿ���ȡ��������С���Ĳ�ľ���ֵ��С������С��0.0000001���Ϳ�����Ϊ������ȡ�

*/

class Solution {
public:
	double Power(double base, int exponent) {
		if (equal(base, 0.0)) {
			return 0.0;
		}
		unsigned int absExponent = 0;
		if (exponent > 0) {
			absExponent = (unsigned int)(exponent);
		}
		else {
			absExponent = (unsigned int)(-exponent);
		}
		double result = PowerWithUnsignedExponent(base, absExponent);
		if (exponent < 0) {
			result = 1.0 / result;
		}
		return result;
	}

private:
	bool equal(double num1, double num2) {
		if (num1 - num2 > -0.0000001 && (num1 - num2) < 0.0000001) {
			return true;
		}
		else {
			return false;
		}
	}

	double PowerWithUnsignedExponent(double base, unsigned int exponent) {
		if (exponent == 0) {
			return 1;
		}
		if (exponent == 1) {
			return base;
		}
		double result = PowerWithUnsignedExponent(base, exponent >> 1);
		result *= result;
		if ((exponent & 0x1 )== 1) {
			result *= base;
		}
		return result;
	}
};



void example_2()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	//int  pRoot1 = 25;

	Solution* s = new Solution;
	double ret;
	try
	{

		ret = s->Power(10.5,6);

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
