#include <iostream>
#include <climits>
using namespace std;
void findLargest(int **a, int r, int c)
{
    if (r == 0 && c == 0)
    {
        cout << "row " << 0 << " " << INT_MIN;
        return;
    }
    int k = 0;
    int sum = 0, presum = 0;
    for (int i = 0; i < r; i++)
    {
        int j;
        for (j = 0; j < c; j++)
        {
            sum = sum + a[i][j];
        }
        if (j == c)
        {
            if (sum > presum)
            {
                presum = sum;
                k = i;
            }
        }
        sum = 0;
    }
    int k1 = 0;
    int sum1 = 0, presum1 = 0;
    for (int i = 0; i < c; i++)
    {
        int j;
        for (j = 0; j < r; j++)
        {
            sum1 = sum1 + a[j][i];
        }
        if (j == r)
        {
            if (sum1 > presum1)
            {
                presum1 = sum1;
                k1 = i;
            }
        }
        sum1 = 0;
    }
    if (presum >= presum1)
    {
        cout << "row " << k << " " << presum;
    }
    else
    {
        cout << "column " << k1 << " " << presum1;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;

        int **input = new int *[row];
        for (int i = 0; i < row; i++)
        {
            input[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> input[i][j];
            }
        }

        findLargest(input, row, col);
        cout << endl;
    }
}