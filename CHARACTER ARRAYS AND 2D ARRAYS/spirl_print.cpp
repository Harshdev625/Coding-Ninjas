#include <iostream>
using namespace std;
void spiralPrint(int **a,int r,int c){
    int sr=0;
    int er=r-1;
    int sc=0;
    int ec=c-1;
    int total=r*c;
    int k=0;
    while(total){
        if(k%4==0){
        int i;
        for( i=sc;i<=ec;i++){
            cout<<a[sr][i]<<" ";
            total--;
        }
        k++;
        sr=sr+1;
        }
        else if(k%4==1){
        int i;
        for( i=sr;i<=er;i++){
            cout<<a[i][ec]<<" ";
            total--;
        }
        ec=ec-1;
        k++;  
        }
        else if(k%4==2){
        int i;
        for( i=ec;i>=sc;i--){
            cout<<a[er][i]<<" ";
            total--;
        }
        k++;
        er=er-1;
        }
        else{
        int i;
        for( i=er;i>=sr;i--){
            cout<<a[i][sc]<<" ";
            total--;
        }
        sc=sc+1;
        k++;      
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
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}