#include <stack>
#include <exception>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
/*


https://cuijiahua.com/blog/2018/01/basis_61.html

��ʵ�������������ֱ��������л��ͷ����л���������

ʹ��ǰ����������л��ͷ����л����ɡ�ֻҪ�Լ�д�ĳ����ʽ��Ӧ�ϼ��ɡ�
����ʹ��$���ű�ʾNULL��ͬʱÿ�����֮�䣬��Ҫ��Ӷ��ţ���','���зָ���

*/

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	char* Serialize(TreeNode *root) 
	{
		if (!root) 
		{
			return NULL;
		}
		std::string str;
		SerializeCore(root, str);
		// ��str����ת��Ϊ�ַ�������
		std::size_t length = str.length();
		char* res = new char[length + 1];
		// ��str����ת��Ϊ�ַ�������
		for (int i = 0; i < length; i++) 
		{
			res[i] = str[i];
		}
		res[length] = '\0';
		return res;
	}
	TreeNode* Deserialize(char *str) 
	{
		if (!str) 
		{
			return NULL;
		}
		TreeNode* res = DeserializeCore(&str);
		return res;
	}
	void SerializeCore(TreeNode* root, std::string& str)
	{
		// ���ָ��Ϊ�գ���ʾ���ӽڵ�����ӽڵ�Ϊ�գ�������������#��ʾ
		if (!root) 
		{
			str += '#';
			return;
		}
		std::string tmp = std::to_string(root->val);
		str += tmp;
		// �Ӷ��ţ���������ÿ�����
		str += ',';
		SerializeCore(root->left, str);
		SerializeCore(root->right, str);
	}
	// �ݹ�ʱ�ı���strֵʹ��ָ���������У����Ҫ����Ϊchar**
	TreeNode* DeserializeCore(char** str)
	{
		// ����Ҷ�ڵ�ʱ���������Σ�������null�����Թ�����ϣ����ظ��ڵ�Ĺ���
		if (**str == '#') 
		{
			(*str)++;
			return NULL;
		}
		// ��Ϊ���������ַ�����ʾ��һ���ַ���ʾһλ���Ƚ���ת��
		int num = 0;
		while (**str != ',' && **str != '\0')
		{
			num = num * 10 + ((**str) - '0');
			(*str)++;
		}
		TreeNode* root = new TreeNode(num);
		if (**str == '\0') 
		{
			return root;
		}
		else 
		{
			(*str)++;
		}
		root->left = DeserializeCore(str);
		root->right = DeserializeCore(str);
		return root;
	}
};

//�˴�û�й���������������г���
void main()
{

	//std::vector<int> array1 = { 1,2,4,7,3,5,6,8 };
	//std::vector<int> array2 = { 4,7,2,1,5,3,8,6 };
	TreeNode*   pRoot1 = NULL;

	Solution* s = new Solution;
	char* ret;
	try
	{

		ret = s->Serialize(pRoot1);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << " " << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete s;
	system("pause");
	return;
}
