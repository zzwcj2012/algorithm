#include <iostream>
using namespace std;

void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) //���������ҵ�һ��С��X����
			{
				j--;
			}
			if (i < j)
			{
				s[i++] = s[j];
			}
			while (i < j && s[i] < x) //���������ҵ�һ�����ڵ���X����
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
	cout << "��������Ľ���ǣ�" << endl;
	for (int i = 0; i <10; i++)
	{
		cout << s[i]<<" ";
	}

	return 0;
}