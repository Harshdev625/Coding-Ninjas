#include <iostream>
using namespace std;
void wavePrint(int **a,int r,int c){
    for(int i=0;i<c;i++){
        if(i%2==0){
        for(int j=0;j<r;j++){
            cout<<a[j][i]<<" ";
        }
        }
        else{
        for(int j=r-1;j>=0;j--){
            cout<<a[j][i]<<" ";
        }
        }
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
		wavePrint(input, row, col);
		cout << endl;
	}
}