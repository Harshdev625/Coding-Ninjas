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
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node n1(100);
    Node *head = &n1;
    Node n2(200);
    n1.next = &n2;
    Node n3(300);
    n2.next = &n3;
    Node n4(400);
    n3.next = &n4;
    Node n5(500);
    n4.next = &n5;
    Node *n6 = new Node(600);
    n5.next = n6;
    Node *n7 = new Node(700);
    n6->next = n7;
    display(head);
    display(head);
}