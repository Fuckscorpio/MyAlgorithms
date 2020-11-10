#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_33.html

��ֻ��������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ����������7��
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������

����Ӧ������һ����������2��3����5�Ľ����1���⣩��������ǿ��Դ���һ�����飬
������������ź���ĳ�����ÿһ����������ǰ��ĳ�������2��3����5�õ��ġ�

*/


//1��2��3��4��5��6���ǳ��������Ե�indexС��7��ʱ��ֱ�ӷ���index���ɡ�
class Solution {
public:
	int GetUglyNumber_Solution(int index)
	{
		if (index < 7) {
			return index;
		}
		std::vector<int> res(index);
		for (int i = 0; i < 6; i++) 
		{
			res[i] = i + 1;
		}
		int t2 = 3, t3 = 2, t5 = 1;
		for (int i = 6; i < index; i++) 
		{
			res[i] = std::min(res[t2] * 2, std::min(res[t3] * 3, res[t5] * 5));
			while (res[i] >= res[t2] * 2) 
			{
				t2++;
			}
			while (res[i] >= res[t3] * 3)
			{
				t3++;
			}
			while (res[i] >= res[t5] * 5)
			{
				t5++;
			}
		}
		return res[index - 1];
	}
};


void example_6()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->GetUglyNumber_Solution(7);

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
