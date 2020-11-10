#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_41.html

С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22��
���ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!

�趨����ָ�룬һ��ָ���һ������һ��ָ�����һ������
�ڴ�֮ǰ��Ҫ�趨��һ���������һ������ֵ���������������У����Կ��԰ѵ�һ������Ϊ1�����һ����Ϊ2

*/



class Solution {
public:
	std::vector<std::vector<int> > FindContinuousSequence(int sum) {
		std::vector<std::vector<int> > result;
		// ��λָ��͵�λָ��
		int phigh = 2, plow = 1;

		// ��ֹ������phigh����sum
		while (phigh > plow) {
			// ��ǰ�ͣ�ʹ����͹�ʽs = (a+b) * n / 2
			int curSum = (plow + phigh) * (phigh - plow + 1) >> 1;
			if (curSum < sum) {
				phigh++;
			}
			if (curSum == sum) {
				std::vector<int> temp;
				for (int i = plow; i <= phigh; i++) {
					temp.push_back(i);
				}
				result.push_back(temp);
				plow++;
			}
			if (curSum > sum) {
				plow++;
			}
		}
		return result;
	}
};


void example_7()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	Solution* s = new Solution;
	std::vector<std::vector<int> > ret;
	try
	{

		ret = s->FindContinuousSequence(100);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
