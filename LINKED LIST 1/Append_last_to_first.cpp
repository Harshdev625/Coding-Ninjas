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
        this->next = NULL;
    }
};
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
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
Node *appendLastNToFirst(Node *head, int n)
{
    if (head == NULL)
    {
        return head;
    }
    if (n == 0)
    {
        return head;
    }
    Node *temp1 = head;
    int c = 0;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
        c++;
    }
    Node *temp = head;
    Node *newhead = head;
    Node *tail = head;
    Node *newtail = head;
    int count = 0;
    while (count != c - n)
    {
        temp = temp->next;
        if (count == c - n - 1)
        {
            newtail = temp;
        }
        count++;
    }
    newhead = temp->next;
    Node *a = newhead;
    while (a->next != NULL)
    {
        a = a->next;
    }
    a->next = tail;
    newtail->next = NULL;
    return newhead;
}
void print(Node *head)
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
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int n;
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}