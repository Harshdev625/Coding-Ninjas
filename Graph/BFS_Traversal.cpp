#include <bits/stdc++.h>
using namespace std;

void printBFS(int **edges, int s, int vertex, bool *visited)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		cout << front << " ";
		for (int i = 0; i < vertex; i++)
		{
			if (edges[front][i] == 1 && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	int n, vertex;
	cin >> n >> vertex;
	int **edges = new int *[n];
	for (int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}

	int s, e;
	for (int i = 0; i < vertex; i++)
	{
		cin >> s >> e;
		edges[s][e] = 1;
		edges[e][s] = 1;
	}

	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			printBFS(edges, i, n, visited);
		}
	}
	return 0;
}
