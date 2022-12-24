#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
Node *takeinput()
{
    int data;
    cin >> data;
    Node *mainhead = nullptr;
    Node *head = nullptr;
    Node *tail = nullptr;
    while (data != -1)
    {
        Node *newdata = new Node(data);
        if (head == nullptr)
        {
            mainhead = newdata;
            head = newdata;
            tail = newdata;
        }
        else
        {
            tail->next = newdata;
            newdata->prev = tail;
            tail = tail->next;
        }
        cin >> data;
    }
    // cout<<mainhead->data<<" "<<mainhead->next<<endl;
    return mainhead;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " " << temp->prev << " " << temp << " " << temp->next << endl;
        temp = temp->next;
    }
}
int main()
{
    Node *head = takeinput();
    display(head);
}