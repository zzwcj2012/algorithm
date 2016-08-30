#include <iostream>
#include <cstring>
using namespace std;

class Graph {
private:
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

int main() {
	int n, m, x, y;
	cout << "请输入两个数n和m，分别表示图中顶点数量和 有向边数量" << endl;
	cin >> n >> m;
	Graph g(n);
	cout << "请输入" << m << "行，每行输入两个数x和y" << endl;
	for (int i = 0; i < m; ++i) {
			cin >> x >> y;
		g.insert(x, y);
	}
	g.output();
	return 0;
}
