#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*


https://cuijiahua.com/blog/2018/01/basis_54.html

��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��

���ֽ�������������ͨ����ϣ��ͳ���ַ�����ÿ���ַ����ֵĴ�����
˳�㽫�ַ���������string�У�Ȼ���ٱ���string���ӹ�ϣ�����ҵ���һ������һ�ε��ַ���
*/



class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		s += ch;
		count[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		std::size_t length = s.size();
		for (int i = 0; i < length; i++) {
			if (count[s[i]] == 1) {
				return s[i];
			}
		}
		return '#';
	}
private:
	std::string s;
	int count[256] = { 0 };
};


void example_13()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	std::vector<int>  pRoot1 = { 4,5,6,7,8,9 };

	Solution* s = new Solution;
	s->Insert('g');
	s->Insert('o');
	s->Insert('o');
	s->Insert('g');
	s->Insert('l');
	s->Insert('e');



	char ret;
	try
	{

		ret = s->FirstAppearingOnce();

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << ret << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
