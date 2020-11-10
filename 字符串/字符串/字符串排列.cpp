
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/*

https://cuijiahua.com/blog/2017/12/basis_27.html
�ֱ�ѵ�һ���ַ�a�ͺ����b��c���ַ����������Ρ����ȹ̶���һ���ַ�������������ַ������С����ʱ�������԰Ѻ���������ַ���Ϊ�����֣�
������ַ��ĵ�һ���ַ����Լ�����ַ�֮��������ַ���Ȼ��ѵ�һ���ַ���һ����������ַ�������
*/
class Solution {
public:
	vector<string> Permutation(string str) {
		//�ж�����
		if (str.length() == 0) {
			return result;
		}
		PermutationCore(str, 0);
		//�Խ����������
		sort(result.begin(), result.end());
		return result;
	}

private:
	void PermutationCore(string str, int begin) {
		//�ݹ��������������һλ�����һλ�������
		if (begin == str.length()) {
			result.push_back(str);
			return;
		}
		for (int i = begin; i < str.length(); i++) {
			//����ַ�����ͬ���򲻽���
			if (i != begin && str[i] == str[begin]) {
				continue;
			}
			//λ�ý���
			swap(str[begin], str[i]);
			//�ݹ���ã�ǰ��begin+1��λ�ò��䣬������ַ���ȫ����
			PermutationCore(str, begin + 1);
		}
	}
	vector<string> result;
};

void example_2()
{

	//�˴�Ӧд������
	string str = "cdefg";

	Solution* s = new Solution;
	vector<string> result;
	try
	{
		result=s->Permutation(str);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete s;
	system("pause");
	return;
}