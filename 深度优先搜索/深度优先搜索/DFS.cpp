#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Graph {
private:
	int n;  //!< ��������
	vector<int> *edges;  //!< �ڽӱ�
	bool* visited; //ָ��һ����¼���ʹ��̵�bool����

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

	//�����ڽӱ�
	void insert(int x, int y) {
		edges[x].push_back(y);
		edges[y].push_back(x);
	}


	//������������㷨
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
	cout << "�����������������ֱ��ʾͼ�ж������ͱ�����" << endl;
	cin >> n >> m;
	Graph g(n);
	cout << "������x��y����" << m << "�У���ʾ�Ӷ���x��y�������" << endl;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		g.insert(x, y);
	}
	cout << "������һ����������ʾ���������" << endl;
	cin >> k;
	g.dfs(k);
	return 0;
}