#include <iostream>
using namespace std;
int findUnique(int *arr, int n)
{
    if (n == 1)
    {
        return *arr;
    }
    return arr[0] ^ findUnique(arr + 1, n - 1);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}