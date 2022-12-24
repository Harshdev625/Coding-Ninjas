#include <iostream>
using namespace std;

void rotate(int *input, int d, int size)
{
    if (size == 0)
    {
        return;
    }
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    int a = d % size;
    for (int i = size - a, j = size - 1; j > i; i++, j--)
    {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    for (int i = 0, j = size - a - 1; j > i; i++, j--)
    {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
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

        int d;
        cin >> d;

        rotate(input, d, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }

    return 0;
}