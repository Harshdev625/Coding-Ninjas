#include <iostream>
using namespace std;
template <typename T>
class Queueusingarray{ 
    int firstindex;
    int nextindex;
    T*data;
    int size;
    int capacity;
     public:
    Queueusingarray(int s){
        firstindex=-1;
        nextindex=0;
        data=new T [s];
        size=0;
        capacity =s;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(int element){
        if(size == capacity){
            T *newarray = new T[2*capacity];
            int j=0;
            for(int i=firstindex;i<size;i++){
                newarray[j]=data[i];
                j++;
            }
            for(int i=nextindex;i<firstindex;i++){
                newarray[j]=data[i];
                j++;
            }
            delete [] data;
            data=newarray;
            firstindex=0;
            nextindex=j;
        }
        if(firstindex==-1){
            firstindex=0;
        }
        capacity=2*capacity;
        data[nextindex]=element;
        nextindex=(nextindex+1)%capacity;
        size++;
    }
    T front(){
        return data[firstindex];
    }
    T dequeue(){
        T ans;
        /*if(firstindex==nextindex){
            ans=0;
            firstindex=-1;
            nextindex=0;
            size=0;
            return ans;
        }*/
        if(firstindex==-1){
            return 0;
        }
        if(getSize()==1){
            ans=data[firstindex];
            firstindex=-1;
            nextindex=0;
            size--;
            return ans;
        }
        
        ans=data[firstindex];
        firstindex++;
        size--;
        return ans;
    }
};
int main(){
    Queueusingarray <int> q(2);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout << q.front()<<endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front()<<endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front()<<endl;
    cout << q.dequeue() << endl;
    cout << q.front()<<endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
}