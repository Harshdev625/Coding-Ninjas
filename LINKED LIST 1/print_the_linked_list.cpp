#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void print(Node *head)
{
    for (; head != NULL;)
    {
        cout << head->data << " " << head->next << endl;
        head = head->next;
    }
}
int main()
{
    Node n1(1);
    Node *head = &n1;
    Node n2(2);
    n1.next = &n2;
    Node n3(3);
    n2.next = &n3;
    Node n4(4);
    n3.next = &n4;
    Node n5(5);
    n4.next = &n5;
    Node *n6 = new Node(6);
    n5.next = &*n6;
    Node *n7 = new Node(7);
    n6->next = &*n7;
    print(head);
    /* n1.next=&n2;
     cout<<n1.data<<" "<<n2.data<<endl;
     cout<<n1.next<<" "<<n2.next<<endl;*/
}