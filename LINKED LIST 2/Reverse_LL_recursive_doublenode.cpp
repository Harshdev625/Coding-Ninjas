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
class Pair{
    public:
    Node*head;
    Node*tail;
};
Pair reverse_ll(Node*head){
    if(head==nullptr || head->next==nullptr){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallans=reverse_ll(head->next);
    smallans.tail->next=head;
    head->next=nullptr;
    Pair ans;
    ans.head=smallans.head;
    ans.tail=head;
    //ans.head=head;
    return ans;
};
Node* reversellbetter(Node*head){
    return reverse_ll(head).head;
}
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
    Node*head2=reversellbetter(head);
    display(head2);
}