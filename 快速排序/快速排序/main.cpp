#include <iostream>
using namespace std;

void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) //从右向左找第一个小于X的数
			{
				j--;
			}
			if (i < j)
			{
				s[i++] = s[j];
			}
			while (i < j && s[i] < x) //从左向右找第一个大于等于X的数
			{
				i++;
			}
			if (i < j)
			{
				s[j--] = s[i];
			}
		}

		s[i] = x;

		quick_sort(s, l, i - 1);
		quick_sort(s, i + 1, r);
	}

}

int main()
{
	int s[10] = { 48,6,57,88,60,42,83,73,89,85 };
	int l = 0, r = 9;
	quick_sort(s, l, r);
	cout << "快速排序的结果是：" << endl;
	for (int i = 0; i <10; i++)
	{
		cout << s[i]<<" ";
	}

	return 0;
}