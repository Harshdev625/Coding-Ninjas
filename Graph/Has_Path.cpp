#include <bits/stdc++.h>
using namespace std;
bool haspath(int **arr, bool *visit, int start, int end, int v)
{
    for(int i=0;i<v;i++){
        cout<<visit[i]<<" ";
    }
    cout<<endl;
    if (start == end)
    {
        return true;
    }
    visit[start] = true;
    for (int i = 0; i < v; i++)
    {
        if (arr[start][i] == 1 && !visit[i])
        {
            if (haspath(arr, visit, i, end, v))
                return true;
        }
    }
    return false;
}
int main()
{
    int v, e;
    cin >> v >> e;
    int **arr = new int *[v];
    for (int i = 0; i < v; i++)
    {
        arr[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            arr[i][j] = 0;
        }
    }
    int f, s;
    for (int i = 0; i < e; i++)
    {
        cin >> f >> s;
        arr[f][s] = 1;
        arr[s][f] = 1;
    }
    int start, end;
    cin >> start >> end;
    bool *visit = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visit[i] = false;
    }
    if (haspath(arr, visit, start, end, v))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
