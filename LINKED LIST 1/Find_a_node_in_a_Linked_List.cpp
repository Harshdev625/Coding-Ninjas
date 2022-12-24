#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
Node* takeinput(){
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node*newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
int findNode(Node*head,int val){
    Node*temp=head;
    int count=0;
    if(temp==NULL){
        return -1;
    }
    while(temp->data!=val && temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    if(temp->data==val && temp->next!=NULL){
        return count; 
    }
    else if(temp->next==NULL && temp->data==val){
        return count;
    }
    else{
        return -1;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Node*head=takeinput();
        int val;
        cin>>val;
        cout<<findNode(head, val)<<endl;
    }
}