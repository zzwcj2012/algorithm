#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Graph {
private:
	int n;  //!< 顶点数量
	vector<int> *edges;  //!< 邻接表
	bool* visited; //指向一个记录访问过程的bool数组

public:
	Graph(int input_n) {
		n = input_n;
		edges = new vector<int>[n];
		visited = new bool[n];
		memset(visited, 0, n);
	}

	~Graph() {
		delete[] edges;
		delete[] visited;
	}

	//插入邻接表
	void insert(int x, int y) {
		edges[x].push_back(y);
		edges[y].push_back(x);
	}


	//深度优先搜索算法
	void dfs(int vertex) {
		cout << vertex << endl;
		visited[vertex] = true;
		for (int adj_vertex : edges[vertex])
		{
			if (!visited[adj_vertex])
			{
				dfs(adj_vertex);
			}
		}
	}
};

int main() {
	int n, m, k;
	cout << "请输入两个整数，分别表示图中顶点数和边数量" << endl;
	cin >> n >> m;
	Graph g(n);
	cout << "请输入x和y，共" << m << "行，表示从顶点x到y的无向边" << endl;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		g.insert(x, y);
	}
	cout << "请输入一个整数，表示搜索的起点" << endl;
	cin >> k;
	g.dfs(k);
	return 0;
}