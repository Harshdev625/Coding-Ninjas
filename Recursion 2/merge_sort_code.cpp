#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
  /*int j=0;
  int *a=new int[mid+1];
  for(int i=0;i<=mid;i++){
    a[i]=input[j];
    j++;
  }
  for(int i=0;i<=mid;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  int *b=new int[end-mid];
  for(int i=0;i<=end-mid-1;i++){
    b[i]=input[j];
    j++;
  }
  for(int i=0;i<=end-mid-1;i++){
    cout<<b[i]<<" ";
  }
  cout<<endl;
  int k=0,l=0,n=0;
  for(;l<=mid && n<=end-mid-1;){
    if(a[l]<=b[n]){
      input[k]=a[l];
      l++;
      k++;
    }
    else{
      input[k]=b[n];
      n++;
      k++;
    }
  }
  while(l<=mid){
    input[k]=a[l];
      l++;
      k++;
  }
  while(n<=end-mid-1){
    input[k]=b[n];
      n++;
      k++;
    }
  delete [] a;
  delete [] b;*/
  int *temp = new int[end - start + 1];
  int k = 0;
  int s1 = start, e1 = mid, s2 = mid + 1, e2 = end;
  while (s1 <= e1 && s2 <= e2)
  {
    if (arr[s1] < arr[s2])
    {
      temp[k++] = arr[s1++];
    }
    else
    {
      temp[k++] = arr[s2++];
    }
  }
  while (s1 <= e1)
  {
    temp[k++] = arr[s1++];
  }
  while (s2 <= e2)
  {
    temp[k++] = arr[s2++];
  }
  for (int i = 0; i < e2; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  int index = start;
  for (int i = 0; i < k; i++)
  {
    arr[index++] = temp[i];
  }
  delete[] temp;
}
void mergesort1(int input[], int start, int end)
{
  if (start >= end)
  {
    return;
  }
  if (start < end)
  {
    int mid = (start + end) / 2;
    mergesort1(input, start, mid);
    mergesort1(input, mid + 1, end);
    merge(input, start, mid, end);
  }
}
void mergeSort(int input[], int size)
{
  mergesort1(input, 0, size - 1);
}
int main()
{
  int length;
  cin >> length;
  int *input = new int[length];
  for (int i = 0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for (int i = 0; i < length; i++)
  {
    cout << input[i] << " ";
  }
}