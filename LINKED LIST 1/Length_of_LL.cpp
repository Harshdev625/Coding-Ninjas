#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int a){
        data=a;
        next=NULL;
    }
};
Node *takeinput(){
    int data ;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node*newdata=new Node(data);
        if(head==NULL){
            head=newdata;
            tail=newdata;
        }
        else{
            tail->next=newdata;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
int length(Node* head){
    int count=0;
    Node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Node*head=takeinput();
        cout<<length(head)<<endl;
    }
}