#include <iostream>
#include <climits>
using namespace std;
int arrayRotateCheck(int *input,int size){
    int min=INT_MAX;
    for(int i=0;i<size;i++){
        if(input[i]<min){
            min=input[i];
        }
    }
    int k=0;
    for(int i=0;i<size;i++){
        if(input[i]==min){
            k= i;
            break;
        }
    }
    return k;
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