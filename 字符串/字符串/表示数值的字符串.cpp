
#include <string>
#include <iostream>
#include <algorithm>

/*
https://cuijiahua.com/blog/2018/01/basis_53.html
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ��
����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
*/
class Solution {
public:
	// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ��
	// ����A��C���������������������ţ�Ҳ����û�У�
	// ��B��һ���޷�������
	bool isNumeric(char* string)
	{
		// �Ƿ����봦��
		if (string == NULL || *string == '\0') {
			return false;
		}
		// �������ж�
		if (*string == '+' || *string == '-') {
			++string;
		}
		bool numeric = true;
		scanDigits(&string);
		if (*string != '\0') {
			// С���ж�
			if (*string == '.') {
				++string;
				scanDigits(&string);
				if (*string == 'e' || *string == 'E') {
					numeric = isExponential(&string);
				}
			}
			// �����ж�
			else if (*string == 'e' || *string == 'E') {
				numeric = isExponential(&string);
			}
			else {
				numeric = false;
			}
		}
		return numeric && *string == '\0';
	}
private:
	// ɨ�����֣����ںϷ����֣�ֱ������
	void scanDigits(char** string) {
		while (**string != '\0' && **string >= '0' && **string <= '9') {
			++(*string);
		}
	}
	// ���������ѧ��������ʾ����ֵ�Ľ�β�����Ƿ�Ϸ�
	bool isExponential(char** string) {
		++(*string);
		if (**string == '+' || **string == '-') {
			++(*string);
		}
		if (**string == '\0') {
			return false;
		}
		scanDigits(string);
		// �ж��Ƿ��β�����û�н�β��˵�����������Ƿ��ַ���
		return (**string == '\0') ? true : false;
	}
};

void main()
{

	//�˴�Ӧд������
	char str[] = "-1E-16";
	

	Solution* s = new Solution;
	bool result;
	try
	{
		result = s->isNumeric(str);
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
