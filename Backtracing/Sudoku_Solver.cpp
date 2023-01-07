#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
bool isvalid(int a[][9], int i, int j, int val)
{
    for (int l = 0; l < 9; l++)
    {
        if (a[i][l] == val)
        {
            return false;
        }
    }
    for (int l = 0; l < 9; l++)
    {
        if (a[l][j] == val)
        {
            return false;
        }
    }
    i = i - (i % 3);
    j = j - (j % 3);
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (a[row + i][col + j] == val)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudokusolver(int a[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isvalid(a, i, j, val))
                    {
                        // cout<<val <<endl;
                        a[i][j] = val;
                        if (sudokusolver(a) == true)
                        {
                            return true;
                        }
                        else
                        {
                            a[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    // your code goes here
    int a[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
        }
    }
    sudokusolver(a) ? cout << "true" : cout << "false";
    return 0;
}
