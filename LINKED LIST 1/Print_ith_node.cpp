#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
Node *takeinput(){
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
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
void printIthNode(Node *head,int a){
    Node*temp=head;
    for(int i=0;i!=a && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp!=NULL)
    cout<<(temp->data)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Node*head=takeinput();
        int pos;
        cin>>pos;
        printIthNode(head,pos);
        cout<<endl;
    }
}