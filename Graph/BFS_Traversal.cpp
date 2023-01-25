#include <bits/stdc++.h>
using namespace std;

void printBFS(int **arr, int s, int edges, bool *visited)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		cout << front << " ";
		for (int i = 0; i < edges; i++)
		{
			if (arr[front][i] == 1 && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	int n, edges;
	cin >> n >> edges;
	int **arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}

	int s, e;
	for (int i = 0; i < edges; i++)
	{
		cin >> s >> e;
		arr[s][e] = 1;
		arr[e][s] = 1;
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
			printBFS(arr, i, n, visited);
		}
	}
	return 0;
}
