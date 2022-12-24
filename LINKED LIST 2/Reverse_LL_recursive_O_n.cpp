#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=nullptr;
    }
};
Node*reverse_ll(Node*head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node *smallans=reverse_ll(head->next);
    Node*tail=head->next;
    tail->next=head;
    head->next=nullptr;
    return smallans;
};
Node *takeinput(){
    int data;
    cin>>data;
    Node *head=nullptr;
    Node *tail=nullptr;
    while(data!=-1){
        Node *newnode =new Node(data);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;

    }
    return head;
}

void display(Node*head){
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node*head=takeinput();
    //display(head);
    Node*head2=reverse_ll(head);
    display(head2);
}