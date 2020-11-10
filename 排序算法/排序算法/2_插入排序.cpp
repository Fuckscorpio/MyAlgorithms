#include <iostream>
#include <vector>


/*
https://cuijiahua.com/blog/2017/12/algorithm_2.html

ÿһ�˽�һ��������ļ�¼��������ؼ��ֵĴ�С���뵽������еĺ���λ���֪��ȫ��������ɡ�

*/
using namespace std;


vector<int> insertSort(vector<int> list)
{
	vector<int> result;
	if (list.empty()) 
	{
		return result;
	}
	result = list;
	// ��1�����϶�������ģ��ӵ�2������ʼ���������β�����������
	for (int i = 1; i < result.size(); i++) 
	{
		// ȡ����i��������ǰi-1�����ȽϺ󣬲������λ��
		int temp = result[i];
		// ��Ϊǰi-1�������Ǵ�С������������У�����ֻҪ��ǰ�Ƚϵ���(list[j])��temp�󣬾Ͱ����������һλ
		int j = i - 1;
		for (j; j >= 0 && result[j] > temp; j--) 
		{
			result[j + 1] = result[j];
		}
		result[j + 1] = temp;
	}
	return result;
}



void example_2() 
{
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ" << endl;
	
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;
	
	vector<int> result;
	result = insertSort(test);
	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}