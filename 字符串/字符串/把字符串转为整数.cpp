
#include <string>
#include <iostream>
#include <algorithm>

/*
https://cuijiahua.com/blog/2018/01/basis_49.html

��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
����������
����һ���ַ���,����������ĸ����,����Ϊ��
���������
����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0

*/
class Solution {
public:
	enum Status { kValid = 0, kInValid };
	//g_nstatus��ʾ�Ƿ��쳣���
	int g_nStatus = kValid;
	int StrToInt(std::string str) {
		g_nStatus = kInValid;
		long long num = 0;
		const char* cstr = str.c_str();
		// �ж��Ƿ�Ϊָ����Ƿ�Ϊ���ַ���
		if (cstr != NULL && *cstr != '\0') {
			// �����ű�־λ��Ĭ���ǼӺ�
			//������ʾ����
			bool minus = false;
			if (*cstr == '+') {
				cstr++;
			}
			else if (*cstr == '-') {
				minus = true;
				cstr++;
			}
			if (*cstr != '\0') {
				num = StrToIntCore(cstr, minus);
			}
		}
		return (int)num;
	}
private:
	long long StrToIntCore(const char* cstr, bool minus) 
	{
		long long num = 0;
		while (*cstr != '\0') 
		{
			// �ж��Ƿ��ǷǷ�ֵ
			if (*cstr >= '0' && *cstr <= '9') 
			{
				int flag = minus ? -1 : 1;
				num = num * 10 + flag * (*cstr - '0');
				// �ж��Ƿ����,32λ
				if ((!minus && num > /*0x7fffffff*/INT_MAX) || (minus && num < (signed int)/*0x80000000*/INT_MIN))
				{
					num = 0;
					break;
				}
				cstr++;
			}
			else 
			{
				num = 0;
				break;
			}
		}
		// �ж��Ƿ���������
		if (*cstr == '\0') {
			g_nStatus = kValid;
		}
		return num;
	}
};

void example_6()
{

	//�˴�Ӧд������
	std::string str = "+2147483647846168456132154213215154213518641321324532132";

	Solution* s = new Solution;
	int result;
	try
	{
		result = s->StrToInt(str);
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
