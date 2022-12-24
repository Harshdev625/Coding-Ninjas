#include <iostream>

using namespace std;

void print2darray(int a[][100],int row,int col){
    int j=1;
    for(int i=1;i<=row;i++){
        j=j*i;
    }
    cout<<j;

    int b[j][col];
    for(int i=0;i<row;i++){

    }

}

int main()
{
    int row;
    int col;
    cin>>row>>col;
    int a[100][100];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[row][col];
        }
    }
    print2darray(a,row,col);
}
