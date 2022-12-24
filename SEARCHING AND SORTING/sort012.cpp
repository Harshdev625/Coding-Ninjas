#include <iostream>
#include <algorithm>
using namespace std;
/*void sort012(int *arr,int size){
    int i=0;
    int j=size-1;
    for(int k=0;k<size;k++){
        if(arr[k]==0){
            int t=arr[i];
            arr[i]=arr[k];
            arr[k]=t;
            i++;
        }
        else if(arr[k]==2){
            int t=arr[j];
            arr[j]=arr[k];
            arr[k]=t;
            j--;
        }
        else{
            continue;
        }
    }
}*/
void sort012(int *arr, int n)
{
    int z = 0, l = n - 1;
    for (int i = 0; i <= l;)
    {
        if (arr[i] == 0)
        {
            int temp = arr[z];
            arr[z] = arr[i];
            arr[i] = temp;
            z++;
            i++;
        }
        else if (arr[i] == 2)
        {
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
            l--;
        }

        else
        {
            i++;
        }
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
        int *arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        sort012(arr, size);

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        delete[] arr;
        cout << endl;
    }

    return 0;
}