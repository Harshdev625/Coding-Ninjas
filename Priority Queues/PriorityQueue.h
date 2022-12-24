#include <vector>
class PriorityQueue{
    vector<int> pq;
    public:
    int getSize(){
        return pq.size();
    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int childindex=pq.size()-1;
        while(childindex>0){
            int parentindex=(childindex-1)/2;
            if(pq[childindex]<pq[parentindex]){
                int temp=pq[childindex];
                pq[childindex]=pq[parentindex];
                pq[parentindex]=temp;
            }
            else{
                break;
            }
            childindex=parentindex;
        }
    }
    int removeMin(){

        int n=getSize();
        if(n>0){
        int elementtodelete=pq[0];
        pq[0]=pq[n-1];
        pq.pop_back();
        int parentindex=0;
        while(parentindex<n){
        int leftchildindex=2*parentindex+1;
        int rightchildindex=2*parentindex+2;
        int minindex=-1;
        if(leftchildindex<n && rightchildindex<n){
            if(pq[leftchildindex]<pq[rightchildindex]){
                minindex=leftchildindex;
            }
            else{
                minindex=rightchildindex;
            }
        }
        else if(leftchildindex <n){
            minindex=leftchildindex;
        }
        else if(rightchildindex <n){
            minindex=rightchildindex;
        }
        if(minindex!=-1 && pq[parentindex]>pq[minindex]){
            int temp=pq[parentindex];
            pq[parentindex]=pq[minindex];
            pq[minindex]=temp;
            parentindex=minindex;
        }
        else{
            break;
        }
        }
        return elementtodelete;
        }
        return 0;
    }
};