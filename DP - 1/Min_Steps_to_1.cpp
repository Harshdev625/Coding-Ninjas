#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
// recursive apporach to find out Minimum steps to convert a number to 1. 
int countMinStepsToOne(int n){
    if(n==1){
        return 0;
    }
    int min1=0,min2=INT_MAX,min3=INT_MAX;
    min1=countMinStepsToOne(n-1);
    if(n%2==0){
        min2+countMinStepsToOne(n/2);
    }
    if(n%3==0){
        min3=countMinStepsToOne(n/3);
    }
    return 1 + min(min1,(min(min2,min3)));
}
int main() {
    // your code goes here
    int n;
	cin >> n;
	cout << countMinStepsToOne(n);
    return 0;
}
