#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> v;
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    v.push_back(400);
    v.push_back(500);
    cout<<v.size()<<endl;
    v.pop_back();
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<endl;
    }
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    cout<<v.at(3);
}