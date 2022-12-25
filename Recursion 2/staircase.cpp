#include <iostream>
using namespace std;
int staircase(int n)
{
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return staircase(n-3)+staircase(n-2)+staircase(n-1);
}
int main()
{
    int n, output;
    cin >> n;
    output = staircase(n);
    cout << output << endl;
}
