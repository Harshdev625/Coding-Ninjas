#include <iostream>
using namespace std;
int allIndexes(int input[], int size, int x, int output[])
{
    if (size == 0)
    {
        return 0;
    }
    int ans = allIndexes(input + 1, size - 1, x, output);
    for (int i = 0; i < ans; i++)
    {
        output[i]++;
    }
    if (input[0] == x)
    {
        for (int j = ans; j > 0; j--)
        {
            output[j] = output[j - 1];
        }
        output[0] = 0;
        return ans + 1;
    }
    return ans;
}
int allIndexes2(int input[], int size, int x, int output[])
{
    if (size == 0)
    {
        return 0;
    }
    int ans = allIndexes2(input, size - 1, x, output);
    if (input[size - 1] == x)
    {
        output[ans] = size - 1;
        return ans + 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;

    delete[] output;
}