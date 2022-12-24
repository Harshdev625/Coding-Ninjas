#include <iostream>
#include <algorithm>
using namespace std;

/*int tripletSum(int *arr, int n, int num){
    sort(arr,arr+n);
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            int sum=arr[i]+arr[j];
            for(int k=i+1;k<=j-1;k++){
                if(arr[k]==num-sum){
                    count++;
                }
            }
        }
    }
    return count;
}*/
int tripletSum(int *arr, int n, int num)
{
    int count=0;
	sort(arr, arr+n);  
    for(int i=0; i<n-1; i++){
        int start = i+1, end = n-1;
        while(start<end){
            if(arr[start]+arr[end] == num-arr[i]){
               int index = end;
                while(arr[index] == arr[end] && index > start){
                    count ++;
                    index--;
                }
                start++;
            } else if(arr[start]+arr[end] > num-arr[i]){
            	end--;
            } else {
                start++;
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}