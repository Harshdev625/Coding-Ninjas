#include <iostream>
#include <vector>
using namespace std;
#include "Max_Priority_Queue.h"
int main(){
    PriorityQueue q;
    q.insert(1);
    q.insert(2);
    q.insert(33);
    q.insert(444);
    q.insert(1111);
    q.insert(66666);
    q.insert(555555);
    cout<<q.getSize()<<endl;
    cout<<q.getMax()<<endl;
    while(!q.isEmpty()){
        cout<<q.removeMax()<<" ";
    }
    cout<<endl;
}