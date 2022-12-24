#include <iostream>
#include <climits>

using namespace std;

void largestrowcolumn(int a[][100], int row,int column){
    if(row==0&&column==0){
        cout<<"row"<<" "<<row<<" "<<INT_MIN;
    }
    else{
    int rowmax=0;
    int columnmax=0;
    int rowindex =0;
    int columnindex=0;
    for(int i=0;i<row;i++){
        int sumr1=0;
        for(int j=0;j<column;j++){
            sumr1=sumr1+a[i][j];

            if(sumr1>rowmax){
                rowmax=sumr1;
               rowindex=i;
            }
        }
    }
        for(int i=0;i<column;i++){
        int sumc1=0;
        for(int j=0;j<row;j++){
            sumc1=sumc1+a[j][i];

            if(sumc1>columnmax){
                columnmax=sumc1;
                columnindex=i;
            }
        }
    }
    if (rowmax>columnmax){
        cout<<"row"<<" "<<rowindex<<" "<<rowmax;
    }
    else if(rowmax==columnmax){
        if(rowindex<columnindex){
            cout<<"row"<<" "<<rowindex<<" "<<rowmax;
        }
        else if(rowindex==columnindex){
            cout<<"row"<<" "<<rowindex<<" "<<rowmax;
        }
        else{
            cout<<"column"<<columnindex<<" "<<columnmax;
        }
    }
    else{
         cout<<"column"<<" "<<columnindex<<" "<<columnmax;
    }
     //cout<<rowindex<<" "<<rowmax<<" "<<columnindex<<" "<<columnmax;
}
}
int main()
{
   int a[100][100];
   int row;
   int column;
   cin>>row>>column;

   for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
        cin>>a[i][j];
    }
   }
   largestrowcolumn(a,row,column);
}
