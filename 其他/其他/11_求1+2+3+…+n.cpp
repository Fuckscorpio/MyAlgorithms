#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_47.html

��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����



ʹ�õݹ鼴�ɡ�
*/



class Solution {
public:
	int Sum_Solution(int n) {
		int ans = n;
		// &&�����߼��룬�߼����и���·�ص㣬ǰ��Ϊ�٣����治���㡣���ݹ���ֹ����
		ans && (ans += Sum_Solution(n - 1));
		return ans;
	}
};

void example_11()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 4,5,6,7,8,9 };

	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->Sum_Solution(11);

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
