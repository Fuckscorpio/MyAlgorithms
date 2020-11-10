

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_40.html
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��


��򣺲�ͬ��Ϊ1����ͬ��Ϊ0
*/

class Solution {
public:
	void FindNumsAppearOnce(std::vector<int> data, int* num1, int *num2) {
		size_t length = data.size();
		if (length < 2) {
			return;
		}

		// ��ԭʼ����ÿ��Ԫ�������
		int resultExclusiveOR = 0;
		for (int i = 0; i < length; ++i) {
			resultExclusiveOR ^= data[i];
		}

		unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

		*num1 = *num2 = 0;
		for (int j = 0; j < length; j++) {
			if (IsBit1(data[j], indexOf1)) {
				*num1 ^= data[j];
			}
			else {
				*num2 ^= data[j];
			}
		}
	}
private:
	// �ҵ���������num��һ��Ϊ1��λ��������0010����һ��Ϊ1��λ����2��
	unsigned int FindFirstBitIs1(int num) {
		unsigned int indexBit = 0;
		// ֻ�ж�һ���ֽڵ�
		while ((num & 1) == 0 && (indexBit < 8 * sizeof(unsigned int))) {
			num = num >> 1;
			indexBit++;
		}
		return indexBit;
	}
	// �жϵ�indexBitλ�Ƿ�Ϊ1
	bool IsBit1(int num, unsigned int indexBit) {
		num = num >> indexBit;
		return (num & 1);
	}
};

void example_9()
{

	//�˴�Ӧд������
	std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	int *num1=new int, *num2=new int;
	try
	{
		s->FindNumsAppearOnce(array, num1, num2);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << *num1<<" "<<*num2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	delete num1;
	delete num2;
	system("pause");
	return;
}
