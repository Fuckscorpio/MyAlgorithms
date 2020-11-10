#include <iostream>
#include <vector>

using namespace std;
/*
https://cuijiahua.com/blog/2017/12/algorithm_4.html
����������һ�ֽ�����������C. A. R. Hoare��1962�������


��������Ļ���˼���ǣ�ͨ��һ������Ҫ��������ݷָ�ɶ����������֣��ָ����߶��Ǳ���С�������ұ߶��Ǳ����������

Ȼ���ٰ��˷����������������ݷֱ���п�����������������̿��Եݹ���У��Դ˴ﵽ�������ݱ���������С�
*/
int division(vector<int> &list, int left, int right) {
	// ������ߵ���(left)Ϊ��׼
	int base = list[left];
	while (left < right) {
		// �������Ҷ˿�ʼ�����������ֱ���ҵ�С��base����
		while (left < right && list[right] >= base)
			right--;
		// �ҵ��˱�baseС��Ԫ�أ������Ԫ�طŵ�����ߵ�λ��
		list[left] = list[right];

		// ��������˿�ʼ�����ұ�����ֱ���ҵ�����base����
		while (left < right && list[left] <= base)
			left++;
		// �ҵ��˱�base���Ԫ�أ������Ԫ�طŵ����ұߵ�λ��
		list[right] = list[left];
	}

	// ���base�ŵ�leftλ�á���ʱ��leftλ�õ������ֵӦ�ö���leftС��
	// ��leftλ�õ��Ҳ���ֵӦ�ö���left��
	list[left] = base;
	return left;
}

// ��������
void QuickSort(vector<int> &list, int left, int right) {
	// ���±�һ��С�����±꣬�����Խ����
	if (left < right) {
		// ��������зָȡ���´ηָ�Ļ�׼���
		int base = division(list, left, right);

		// �ԡ���׼��š�����һ����ֵ���еݹ���и�����ڽ���Щ��ֵ����������
		QuickSort(list, left, base - 1);

		// �ԡ���׼��š��Ҳ��һ����ֵ���еݹ���и�����ڽ���Щ��ֵ����������
		QuickSort(list, base + 1, right);
	}
}

void example_4() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result = test;
	QuickSort(result, 0, static_cast<int>(result.size() - 1));
	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}