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
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
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
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *node1 = head1;
    Node *node2 = head2;
    Node *tail = head1;
    Node *tail2 = head2;
    Node *mainhead = NULL;
    if (node1 == NULL && node2 == NULL)
    {
        return head;
    }
    if (node1 != NULL && node2 == NULL)
    {
        return head1;
    }
    if (node1 == NULL && node2 != NULL)
    {
        return head2;
    }
    if (node1->data <= node2->data)
    {
        head = node1;
        node1 = node1->next;
        mainhead = head;
    }
    else
    {
        head = node2;
        node2 = node2->next;
        mainhead = head;
    }
    while (node1 != NULL && node2 != NULL)
    {
        if (node1->data <= node2->data)
        {
            head->next = node1;
            head = node1;
            node1 = node1->next;
        }
        else
        {
            head->next = node2;
            head = node2;
            node2 = node2->next;
        }
    }
    if (node1 == NULL && node2 != NULL)
    {
        head->next = node2;
        head = node2;
    }
    if (node2 == NULL && node1 != NULL)
    {
        head->next = node1;
        head = node1;
    }
    return mainhead;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head1 = takeinput();
        Node *head2 = takeinput();
        Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
        print(head3);
    }
    return 0;
}