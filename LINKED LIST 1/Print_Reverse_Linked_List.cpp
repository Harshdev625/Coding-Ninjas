#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
using namespace std;
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
void printReverse(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    if (temp->next == NULL)
    {
        cout << temp->data << " ";
        return;
    }
    else
        printReverse(temp->next);
    cout << temp->data << " ";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        printReverse(head);
        cout << endl;
    }
    return 0;
}