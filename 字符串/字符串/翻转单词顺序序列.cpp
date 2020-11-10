
#include <string>
#include <iostream>
#include <algorithm>

/*
https://cuijiahua.com/blog/2018/01/basis_44.html
�۲��ַ����仯���ɣ���ᷢ�������ܼ򵥡�ֻ��Ҫ��ÿ����������ת��Ȼ������������ת�͵õ�����ȷ�Ľ����
*/
class Solution {
public:
	std::string ReverseSentence(std::string str) {
		std::string result = str;
		std::size_t length = result.size();
		if (length == 0) {
			return "";
		}
		// ׷��һ���ո���Ϊ��ת��־λ
		result += ' ';
		int mark = 0;
		// ���ݿո񣬷�ת���е���
		for (int i = 0; i < length + 1; i++) {
			if (result[i] == ' ') {
				Reverse(result, mark, i - 1);
				mark = i + 1;
			}
		}
		// ȥ����ӵĿո�
		result = result.substr(0, length);
		// ���巴ת
		Reverse(result, 0, static_cast<int>(length - 1));

		return result;
	}
private:
	//��ת�ַ�
	void Reverse(std::string &str, int begin, int end) {
		while (begin < end) {
			std::swap(str[begin++], str[end--]);
		}
	}
};

void example_5()
{

	//�˴�Ӧд������
	std::string str = "student. a am I";

	Solution* s = new Solution;
	std::string result;
	try
	{
		result = s->ReverseSentence(str);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << result << std::endl;
	delete s;
	system("pause");
	return;
}
