#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
Node *takeinput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newdata= new Node(data);
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
void print(Node *head){
    for(;head!=NULL;){
        cout<<head->data<<" "<<head->next<<endl;
        head=head->next;
    }
}
int main(){
    Node *a=takeinput();
    print(a);
}