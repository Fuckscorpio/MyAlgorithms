

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
/*
https://cuijiahua.com/blog/2017/12/basis_30.html
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,
������ȫΪ������ʱ��,����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��᲻�ᱻ������ס��(�������ĳ���������1)


*/

class Solution {
public:
	int FindGreatestSumOfSubArray(std::vector<int> array) {
		if (array.empty()) {
			return 0;
		}
		// ��ʼ��������maxSumΪ���ͣ�curSumΪ��ǰ��
		int maxSum = array[0];
		int curSum = array[0];
		// ��������Ԫ��
		for (size_t i = 1; i < array.size(); i++) {
			// �����ǰ��С�ڵ���0��˵��֮ǰ���Ǹ�����������ǰ��ĺͣ����¼���
			if (curSum <= 0) {
				curSum = array[i];
			}
			// ���û�����⣬ֱ���ۼ�
			else {
				curSum += array[i];
			}
			// ��������
			if (curSum > maxSum) {
				maxSum = curSum;
			}
		}
		return maxSum;
	}
};
void example_5()
{

	//�˴�Ӧд������
	std::vector<int> array = { 1,-2,3,10,-4,7,2,-5};
	Solution* s = new Solution;
	int result = 0;
	try
	{
		result = s->FindGreatestSumOfSubArray(array);
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
