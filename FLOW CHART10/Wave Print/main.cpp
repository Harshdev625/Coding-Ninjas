#include <iostream>

using namespace std;

void waveprint(int a[][100],int r,int c){
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
   int a[100][100];
   int r;
   int c;
   cin>>r>>c;
   for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>a[i][j];
    }
   }
   waveprint(a,r,c);
}
