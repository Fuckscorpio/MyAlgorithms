#include <iostream>
#include <vector>

using namespace std;


/*
https://cuijiahua.com/blog/2017/12/algorithm_3.html


ϣ��(Shell)�����ֳ�Ϊ��С������������һ�ֲ�����������ֱ�Ӳ��������㷨��һ��������ǿ�档
ϣ������Ҳ�Ƶݼ����������㷨�����������ϣ����Donald Shell�����������������㷨�� 1959 �깫����

*/
vector<int> ShellSort(vector<int> list) {
	vector<int> result = list;
	int n = static_cast<int>(result.size());
	for (int gap = n >> 1; gap > 0; gap >>= 1) {
		for (int i = gap; i < n; i++) {
			int temp = result[i];
			int j = i - gap;
			while (j >= 0 && result[j] > temp) {
				result[j + gap] = result[j];
				j -= gap;
			}
			result[j + gap] = temp;
		}
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

void example_3() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	
	vector<int> result;
	result = ShellSort(test);
	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}