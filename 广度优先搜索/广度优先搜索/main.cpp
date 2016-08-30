#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Graph {
private:
	int n;
	bool *visited;
	vector<int> *edges;

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

	void insert(int x, int y) {
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	void bfs(int start_vertex) {
		queue<int> bfs_queue;
		bfs_queue.push(start_vertex);
		visited[start_vertex] = true;
		while (!bfs_queue.empty())
		{
			int vertex = bfs_queue.front();
			cout << vertex << endl;
			bfs_queue.pop();
			for (int adj_vertex : edges[vertex])
			{
				if (!visited[adj_vertex])
				{
					visited[adj_vertex] = true;
					bfs_queue.push(adj_vertex);
				}
			}
		}
	}
};

int main() {
	int n, m, k;
	cout << "请输入两个整数，分别表示图中的顶点数和边的数量" << endl;
	cin >> n >> m;
	Graph g(n);
	cout << "请输入" << m << "行的x和y值，表示从x到y的无向边" << endl;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		g.insert(x, y);
	}
	cout << "请输入开始遍历结点编号" << endl;
	cin >> k;
	cout << "图的广度优先搜索结果是：" << endl;
	g.bfs(k);
	return 0;
}