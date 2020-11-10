#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <functional> // gather less
/*


https://cuijiahua.com/blog/2018/02/basis_63.html

��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��

ʹ�����Ѻ���С��ʵ�֡�

���ѣ������ļ�ֵ�����жѽ���ֵ������ߣ���ÿ������ֵ�����亢�ӵ�ֵ��
��С�ѣ������ļ�ֵ�����жѽ���ֵ����С�ߣ���ÿ������ֵ�����亢�ӵ�ֵС��

��֤��С�ѵ����ݴ������ѡ�

û��ô����
*/

namespace example_space_14
{
	class Solution
	{
	public:
		void Insert(int num)
		{
			// �����������Ϊż�����������С��
			if (((max.size() + min.size()) & 1) == 0)
			{
				// ������������С����������������������ֲ�������
				// ���������е��������ֲ��뵽��С��
				//�������ƺͱ���ļ����ˣ������С��ȷ�����������ռ�����
				//std::cout << max.size() << " " << min.size() << std::endl;
				if (max.size() > 0 && num < max[0])
				{
					// �������ݲ��뵽��������
					max.push_back(num);
					// ��������
					push_heap(max.begin(), max.end(), std::less<int>());
					// �ó������е������
					num = max[0];
					// ɾ�����ѵ�ջ��Ԫ��
					pop_heap(max.begin(), max.end(), std::less<int>());
					max.pop_back();
				}

				// �����ݲ�����С������
				min.push_back(num);
				// ������С��
				push_heap(min.begin(), min.end(), std::greater<int>());
			}
			// ��������Ϊ���������������
			else
			{
				if (min.size() > 0 && num > min[0])
				{
					// �����ݲ�����С��
					min.push_back(num);
					// ������С��
					push_heap(min.begin(), min.end(), std::greater<int>());
					// �ó���С�ѵ���С��
					num = min[0];
					// ɾ����С�ѵ�ջ��Ԫ��
					pop_heap(min.begin(), min.end(), std::greater<int>());
					min.pop_back();
				}
				// �����ݲ�������
				max.push_back(num);
				push_heap(max.begin(), max.end(), std::less<int>());
			}
		}

		double GetMedian()
		{
			// ͳ�����ݴ�С
			int size = static_cast<int>(min.size() + max.size());
			if (size == 0)
			{
				return 0;
			}
			// �������Ϊż��
			if ((size & 1) == 0)
			{
				return (min[0] + max[0]) / 2.0;
			}
			// ����
			else
			{
				return min[0];
			}
		}

	private:
		// ʹ��vector�������Ѻ���С��,min����С������,max����������
		std::vector<int> min;
		std::vector<int> max;
	};
}//example_space_14

void example_14()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 4,5,6,7,8,9 };

	using namespace  example_space_14;
	Solution* s = new Solution;

	s->Insert(7);
	s->Insert(11);
	s->Insert(13);
	s->Insert(17);
	s->Insert(19);
	s->Insert(23);



	double ret;
	try
	{

		ret = s->GetMedian();

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
