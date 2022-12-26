#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
void subsetsOfArray(int input[], int n, int output[], int m)
{
  if (n == 0)
  {
    printArray(output, m);
    return;
  }
  subsetsOfArray(input + 1, n - 1, output, m);
  int i;
  int out[m + 1];
  for (i = 0; i < m; i++)
  {
    out[i] = output[i];
  }
  out[i] = input[0];
  subsetsOfArray(input + 1, n - 1, out, m + 1);
}
void printSubsetsOfArray(int input[], int size)
{
  int output[35000];
  subsetsOfArray(input, size, output, 0);
}
int main()
{
  int input[1000], length;
  cin >> length;
  for (int i = 0; i < length; i++)
    cin >> input[i];
  printSubsetsOfArray(input, length);
}
