

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_37.html
ͳ��һ�����������������г��ֵĴ�����
���Ƕ�����data���ж��֣���������м������С��k��˵��kӦ�ó������м�λ�õ��ұߣ�
��������м�����ִ���k��˵��kӦ�ó������м�λ�õ���ߣ�
��������м�����ֵ���k�������м�λ�õ�ǰһ�����ֲ�����k��˵������м����־�������k���ֵĵ�һ��λ�á�

*/

class Solution {
public:
	//����Ϊ�������У���С�������������
	int GetNumberOfK(std::vector<int> data, int k) {
		size_t length = data.size();
		if (length == 0) {
			return 0;
		}
		int first = GetFirstK(data, k, 0, static_cast<int>(length - 1));
		int last = GetLastK(data, k, 0, static_cast<int>(length - 1));
		if (first != -1 && last != -1) {
			return last - first + 1;
		}
		return 0;
	}
private:
	// ����ʵ���ҵ���һ��K
	int GetFirstK(std::vector<int> data, int k, int begin, int end) {
		if (begin > end) {
			return -1;
		}
		int middleIndex = (begin + end) >> 1;
		int middleData = data[middleIndex];

		if (middleData == k) {
			if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0) {
				return middleIndex;
			}
			else {
				end = middleIndex - 1;
			}
		}
		else if (middleData > k) {
			end = middleIndex - 1;
		}
		else {
			begin = middleIndex + 1;
		}
		return GetFirstK(data, k, begin, end);
	}
	// ѭ��ʵ���ҵ����һ��K
	int GetLastK(std::vector<int> data, int k, int begin, int end) {
		size_t length = data.size();
		int middleIndex = (begin + end) >> 1;
		int middleData = data[middleIndex];

		while (begin <= end) {
			if (middleData == k) {
				if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1) {
					return middleIndex;
				}
				else {
					begin = middleIndex + 1;
				}
			}
			else if (middleData > k) {
				end = middleIndex - 1;
			}
			else {
				begin = middleIndex + 1;
			}
			middleIndex = (begin + end) >> 1;
			middleData = data[middleIndex];
		}
		return -1;
	}
};

void example_8()
{

	//�˴�Ӧд������
	std::vector<int> array = { 4,5,6,7 };
	Solution* s = new Solution;
	int result;
	try
	{
		result = s->GetNumberOfK(array,7);
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
