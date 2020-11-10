#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_42.html

����һ����������������һ������S���������в�����������
�ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�

���������
��Ӧÿ�����԰����������������С���������


����һ�����飬���ǿ��Զ�������ָ�룬һ���������ұ�����pleft������һ���������������pright����
��ô���ĺô��ǣ�Ҳ��֤�˳˻���С��

*/



class Solution {
public:
	std::vector<int> FindNumbersWithSum(std::vector<int> array, int sum) {
		std::vector<int> result;
		std::size_t length = array.size();
		if (length < 1) {
			return result;
		}
		int pright = static_cast<int>(length - 1);
		int pleft = 0;

		while (pright > pleft) {
			int curSum = array[pleft] + array[pright];
			if (curSum == sum) {
				result.push_back(array[pleft]);
				result.push_back(array[pright]);
				break;
			}
			else if (curSum < sum) {
				pleft++;
			}
			else {
				pright--;
			}
		}
		return result;
	}
};


void example_8()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	Solution* s = new Solution;
	std::vector<int> ret;
	try
	{

		ret = s->FindNumbersWithSum(pRoot1,21);

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
