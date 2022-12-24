#include <iostream>
#include <unordered_map>
using namespace std;
void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int,int> map2;
    for(int i=0;i<n;i++){
        map2[arr1[i]]++;
    }
    for(int i=0;i<m;i++){
        if(map2[arr2[i]]>0){
            cout<<arr2[i]<<endl;
            map2[arr2[i]]--;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    printIntersection( a,  b,  n, m);
}