#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <functional> // gather less
/*


https://cuijiahua.com/blog/2018/02/basis_64.html

����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}��


ʹ��һ��˫�˶���deque���� 
Ӧ���ڶ����������������������±꣬��������ֵ��
��һ�����ֵ��±��뵱ǰ��������ֵ��±�֮����ڻ�������ڻ������ڴ�Сʱ����������Ѿ��Ӵ����л��������ԴӶ�����ɾ����
*/

class Solution {
public:
	std::vector<int> maxInWindows(const std::vector<int>& num, unsigned int size)
	{
		std::vector<int> maxInWindows;
		// �����СҪ���ڵ��ڴ��ڴ�С�����Ҵ��ڴ�С���ڵ���1
		if (num.size() >= size && size >= 1) 
		{
			std::deque<int> index;
			for (unsigned int i = 0; i < size; i++) 
			{
				// ���index�ǿգ���������ӵ����ִ��ڵ��ڶ�������С�����֣���ɾ����������С������
				while (!index.empty() && num[i] >= num[index.back()]) 
				{
					index.pop_back();
				}
				index.push_back(i);
			}
			for (unsigned int i = size; i < num.size(); i++) 
			{
				maxInWindows.push_back(num[index.front()]);
				while (!index.empty() && num[i] >= num[index.back()]) 
				{
					index.pop_back();
				}
				// ���ƴ��ڴ�СΪsize
				if (!index.empty() && index.front() <= int(i - size)) 
				{
					index.pop_front();
				}
				index.push_back(i);
			}
			maxInWindows.push_back(num[index.front()]);
		}
		return maxInWindows;
	}
};

void main()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 2,3,4,2,6,2,5,1 };

	
	Solution* s = new Solution;

	

	std::vector<int> ret;
	try
	{

		ret = s->maxInWindows(pRoot1,3);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << " "<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
