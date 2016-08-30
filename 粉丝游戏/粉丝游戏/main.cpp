#include <iostream>
#include <cstring>
using namespace std;

class Graph {
public:
	int **mat;
	int n;

public:
	Graph(int input_n) {
		n = input_n;
		mat = new int*[n];
		for (int i = 0; i < n; ++i) {
			mat[i] = new int[n];
			memset(mat[i], 0, sizeof(int) * n);
		}
	}

	~Graph() {
		for (int i = 0; i< n; ++i) {
			delete[] mat[i];
		}
		delete[] mat;
	}

	void insert(int x, int y) {
		mat[x][y] = 1;
	}
	//计算每个顶点出度与入度之差
	void degree()
	{
		int i, j, inD, outD;
		for (j = 0; j < n; j++) // 列  
		{
			inD = 0, outD = 0;
			for (i = 0; i < n; i++) // 行  
			{
				if (0 != mat[i][j])
				{
					inD++;
				}
				if (0 != mat[j][i])
				{
					outD++;
				}


			}
			cout << inD - outD << endl;
		}
	}

	void output() {
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main() 
{
	int n, m, x, y;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; ++i) 
	{
		cin >> x >> y;
		g.insert(x, y);
	}
	//g.output();
	g.degree();

	

	return 0;
}
