#include <iostream>
#include <vector>

using namespace std;
#include "PriorityQueue.h"
int main(){
    PriorityQueue q;
    q.insert(77);
    q.insert(33);
    q.insert(22);
    q.insert(1);
    q.insert(4);
    q.insert(5);
    cout<<q.getSize()<<endl;
    cout<<q.getMin()<<endl;
    while(!q.isEmpty()){
        cout<<q.removeMin()<<" ";
    }
    cout<<endl;
}