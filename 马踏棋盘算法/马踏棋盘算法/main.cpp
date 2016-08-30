#include <iostream>
#include <time.h>
using namespace std;
#define X 5
#define Y 5

int chess[X][Y];


//�ж��¸��ڵ�λ���Ƿ����
int nextxy(int* x, int* y, int count)
{
	switch (count)
	{
	case 0:
		if (*x + 2 < X - 1 && *y - 1 >= 0 && chess[*x + 2][*y - 1] == 0)
		{
			*x += 2;
			*y -= 1;
			return 1;
		}
		break;

	case 1:
		if (*x + 2 <= X - 1 && *y + 1 <= Y - 1 && chess[*x + 2][*y + 1] == 0)
		{
			*y += 2;
			*x += 1;
			return 1;
		}
		break;

	case 2:
		if (*y + 1 <= Y - 1 && *x + 2 <= X - 1 && chess[*x + 2][*y + 1] == 0)
		{
			*y += 1;
			*x += 2;
			return 1;
		}
		break;
	case 3:
		if (*y - 1 >= 0 && *x + 2 <= X - 1 && chess[*x + 2][*y - 1] == 0)
		{
			*y -= 1;
			*x += 2;
			return 1;
		}
		break;
	case 4:
		if (*y - 2 >= 0 && *x + 1 <= X - 1 && chess[*x + 1][*y - 2] == 0)
		{
			*y -= 2;
			*x += 1;
			return 1;
		}
		break;
	case 5:
		if (*y - 2 >= 0 && *x - 1 >= 0 && chess[*x - 1][*y - 2] == 0)
		{
			*y -= 2;
			*x -= 1;
			return 1;
		}
		break;
	case 6:
		if (*y - 1 >= 0 && *x - 2 >= 0 && chess[*x - 2][*y - 1] == 0)
		{
			*y -= 1;
			*x -= 2;
			return 1;
		}
		break;
	case 7:
		if (*y + 1 <= Y - 1 && *x - 2 >= 0 && chess[*x - 2][*y + 1] == 0)
		{
			*y += 1;
			*x -= 2;
			return 1;
		}
		break;

	default:
		break;
	}
	return 0;
}

void print()
{
	int i, j;
	for (int i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			cout << chess[i][j] << " ";
				
		}
		cout << endl;
	}
}
	//������ȱ������̡�x,yΪλ�����꣬tag�Ǳ�Ǳ�����ÿ��һ��tag+1
	int  traverse(int x, int y, int tag)
	{
		int x1 = x, y1 = y, flag = 0, count = 0;
		chess[x][y] = tag;
		if (X*Y == tag)
		{
			//��ӡ����
			return 1;
		}

		flag = nextxy(&x1, &y1, count);

		while (flag == 0 && count <= 7)
		{
				count++;
				flag = nextxy(&x1, &y1, count);
		}
		
		while (flag)
		{
			if (traverse(x1, y1, tag + 1)) // ���ȫ��������ϣ��򷵻ء�
			{
				return 1;
			}

			///û���ҵ���һ�����ý�㣬����� 
			x1 = x;
			y1 = y;
			count++;

			flag = nextxy(&x1, &y1, count);
			while (0 == flag && count <= 7)
			{
				count++;
				flag = nextxy(&x1, &y1, count);
			}

		}
		
		

		if(0==flag)
		{
			chess[x][y] = 0;

		}
		return 0;
		
	}



int main()
{
	int i, j;
	clock_t start, finish;
	start = clock();
	for (int i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			chess[i][j] = 0;

		}
	}

	chess[2][0] = 1;
	int result = traverse(2, 0, 2);
	finish = clock();

	if (result == 1)
	{
		print();
		cout << "���μ����ʱ" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	}

	else
	{
		cout << "����ʧ��" << endl;
	}

	
	

	return 0;
}