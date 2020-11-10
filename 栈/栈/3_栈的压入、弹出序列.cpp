#include <stack>
#include <exception>
#include <iostream>
#include <vector>
/*

https://cuijiahua.com/blog/2017/12/basis_21.html

���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳��
����4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�

*/
namespace example_space_3
{
	class Solution {
	public:
		bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) 
		{
			if (pushV.size() == 0) 
			{
				return false;
			}
			for (int i = 0, j = 0; i < pushV.size(); i++) 
			{
				stackData.push(pushV[i]);
				while (j < popV.size() && stackData.top() == popV[j]) 
				{
					stackData.pop();
					j++;
				}
			}
			return stackData.empty();
		}
	private:
		std::stack<int> stackData;
	};
}

void main()
{
	using namespace example_space_3;
	std::vector<int> array1 = { 1,2,3,4,5};
	std::vector<int> array2 = { 4,5,3,2,1 };
	
	Solution* s = new Solution;
	bool ret;
	try
	{
		
		ret = s->IsPopOrder(array1, array2);

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
