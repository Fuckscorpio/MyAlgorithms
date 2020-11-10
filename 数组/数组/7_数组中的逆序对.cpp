

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_35.html
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P%1000000007��


*/

class Solution {
public:
	int InversePairs(std::vector<int> data)
	{
		if (data.size() == 0)
		{
			return 0;
		}
		// ����ĸ�������
		std::vector<int> copy;
		for (int i = 0; i < data.size(); ++i) 
		{
			copy.push_back(data[i]);
		}
		return InversePairsCore(data, copy, 0, static_cast<int>(data.size() - 1)) % 1000000007;
	}

	long InversePairsCore(std::vector<int> &data, std::vector<int> &copy, int begin, int end)
	{
		// ���ָ����ͬλ�ã���û������ԡ�
		if (begin == end) {
			copy[begin] = data[end];
			return 0;
		}
		// ���е�
		int mid = (end + begin) >> 1;
		// ʹdata�������򣬲�������������Ե���Ŀ
		long leftCount = InversePairsCore(copy, data, begin, mid);
		// ʹdata�Ұ�����򣬲������Ұ������Ե���Ŀ
		long rightCount = InversePairsCore(copy, data, mid + 1, end);

		int i = mid; // i��ʼ��Ϊǰ������һ�����ֵ��±�
		int j = end; // j��ʼ��Ϊ�������һ�����ֵ��±�
		int indexcopy = end; // �������鸴�Ƶ���������һ�����ֵ��±�
		long count = 0; // ����������Եĸ�����ע������

		while (i >= begin && j >= mid + 1) 
		{
			if (data[i] > data[j])
			{
				copy[indexcopy--] = data[i--];
				count += j - mid;
			}
			else 
			{
				copy[indexcopy--] = data[j--];
			}
		}
		for (; i >= begin; --i) 
		{
			copy[indexcopy--] = data[i];
		}
		for (; j >= mid + 1; --j) 
		{
			copy[indexcopy--] = data[j];
		}
		return leftCount + rightCount + count;
	}
};
void example_7()
{

	//�˴�Ӧд������
	std::vector<int> array = { 7,6,5,4 };
	Solution* s = new Solution;
	int result;
	try
	{
		result = s->InversePairs(array);
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
