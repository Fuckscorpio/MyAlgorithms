#include <stack>
#include <exception>
#include <iostream>
#include <vector>
/*

https://cuijiahua.com/blog/2018/02/basis_66.html
���ݷ�


������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35,37����
��Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�

*/


class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		int count = 0;
		if (threshold < 1 || rows < 1 || cols < 1) {
			return count;
		}
		bool* visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);
		count = movingCountCore(threshold, rows, cols, 0, 0, visited);
		delete[] visited;
		return count;
	}
private:
	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited) {
		int count = 0;
		if (row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row*cols + col]) {
			visited[row*cols + col] = true;
			count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row - 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col + 1, visited)
				+ movingCountCore(threshold, rows, cols, row, col - 1, visited);
		}
		return count;
	}
	int getDigitSum(int num) {
		int sum = 0;
		while (num) {
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
};

void main()
{

	char array1[] = "abcesfcsadee";
	char array2[] = "bcced";

	Solution* s = new Solution;
	int ret;
	try
	{

		ret = s->movingCount(18, 50, 50);

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
