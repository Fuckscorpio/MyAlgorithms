

#include <stddef.h>
#include <vector>
#include <iostream>
#include <exception>
/*
https://cuijiahua.com/blog/2017/11/basis_6.html
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

*/

class Solution {
public:
	int minNumberInRotateArray(std::vector<int> rotateArray) {
		size_t size = rotateArray.size();							//���鳤��
		if (size == 0) {
			return 0;
		}
		size_t left = 0;											//��ָ��
		size_t right = size - 1;									//��ָ��
		size_t mid = 0;											//�м�ָ��
		while (rotateArray[left] >= rotateArray[right]) {			//ȷ����ת
			if (right - left == 1) {								//����ָ������
				mid = right;
				break;
			}
			mid = left + (right - left) / 2;					//�����м�ָ��λ��
																//�������������޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ��������飬ֻ��˳�����
			if (rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left]) {
				return MinInOrder(rotateArray, left, right);
			}
			//�м�Ԫ��λ��ǰ��ĵ��������飬��ʱ��СԪ��λ���м�Ԫ�صĺ���
			if (rotateArray[mid] >= rotateArray[left]) {
				left = mid;
			}
			//�м�Ԫ��λ�ں���ĵ��������飬��ʱ��СԪ��λ���м�Ԫ�ص�ǰ��
			else {
				right = mid;
			}
		}
		return rotateArray[mid];
	}
private:
	//˳��Ѱ����Сֵ
	int MinInOrder(std::vector<int> &num, size_t left, size_t right) {
		int result = num[left];
		for (size_t i = left + 1; i < right; i++) {
			if (num[i] < result) {
				result = num[i];
			}
		}
		return result;
	}
};

void example_2()
{

	//�˴�Ӧд������
	std::vector<int> array = {9,7,8,3,4,5};
	Solution* s = new Solution;
	int result;
	try
	{
		result = s->minNumberInRotateArray( array);
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
