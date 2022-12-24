#include <iostream>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
	int num = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (input[i] > input[i + 1])
		{
			num = i + 1;
			break;
		}
	}
	return num;
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}

	return 0;
}