

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
/*
https://cuijiahua.com/blog/2018/01/basis_50.html
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}��
��ô��Ӧ������ǵ�һ���ظ�������2��


*/

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		// �Ƿ�����
		if (numbers == NULL || length <= 0) {
			return false;
		}
		// �Ƿ�����
		for (int i = 0; i < length; i++) {
			if (numbers[i] < 0 || numbers[i] > length - 1) {
				return false;
			}
		}
		// �������ҵ�һ���ظ�����
		for (int i = 0; i < length; i++)
		{
			while (numbers[i] != i) 
			{
				if (numbers[i] == numbers[numbers[i]]) 
				{
					*duplication = numbers[i];
					return true;
				}
				std::swap(numbers[i], numbers[numbers[i]]);
			}
		}
		return false;
	}
};

void example_10()
{

	//�˴�Ӧд������
	//�����������Ҫ��
	//std::vector<int> array = { 2,4,3,6,3,2,5,5 };
	Solution* s = new Solution;
	int array[] = { 2,3,1,0,2,5,3 };
	int *num = new int;
	try
	{
		s->duplicate(array, 7, num);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << *num << " "<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	delete num;
	
	system("pause");
	return;
}
