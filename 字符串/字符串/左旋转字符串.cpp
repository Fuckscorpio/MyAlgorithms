



#include <string>
#include <iostream>
#include <algorithm>

/*
https://cuijiahua.com/blog/2018/01/basis_43.html
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����

�����ַ���"abcdefg"������2���ú�������������ת2λ�õ��Ľ��"cdefgab";

��һ������ת�ַ�����ab�����õ�"ba"��
�ڶ�������ת�ַ���"cdefg"���õ�"gfedc"��
����������ת�ַ���"bagfedc"���õ�"cdefgab"��
*/
class Solution {
public:
	std::string LeftRotateString(std::string str, int n) {
		std::string result = str;
		std::size_t length = result.size();
		if (length < 0) {
			return NULL;
		}
		if ( n >=0 && n <= length) {
			int pFirstBegin = 0, pFirstEnd = n - 1;
			int pSecondBegin = n, pSecondEnd = static_cast<int>(length) - 1;
			ReverseString(result, pFirstBegin, pFirstEnd);
			ReverseString(result, pSecondBegin, pSecondEnd);
			ReverseString(result, pFirstBegin, pSecondEnd);
		}
		return result;
	}
private:
	void ReverseString(std::string &str, int begin, int end) {
		while (begin < end) {
			std::swap(str[begin++], str[end--]);
		}
	}
};

void example_4()
{

	//�˴�Ӧд������
	std::string str = "abcXYZdef";

	Solution* s = new Solution;
	std::string result;
	try
	{
		result = s->LeftRotateString(str,3);
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

