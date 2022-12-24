#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
node *takeinput()
{
    int data;
    cin >> data;
    node *head = nullptr;
    node *tail = nullptr;
    if (data == -1)
    {
        return head;
    }
    else
    {
        while (data != -1)
        {
            node *newdata = new node(data);
            if (head == nullptr)
            {
                head = newdata;
                tail = newdata;
            }
            else
            {
                tail->next = newdata;
                tail = tail->next;
            }
            cin >> data;
        }
    }
    tail->next = head;
    return head;
}
void display(node *head)
{
    
    node *temp = head;
    if(head==nullptr){
        return;
    }
    cout << head->data << " "<<head->next<<endl;
    temp = temp->next;
    while (temp != head)
    {
        cout << temp->data << " "<<temp->next<<endl;
        temp = temp->next;
    }
    cout << temp->data << " "<<temp->next<<endl;
    temp = temp->next;
    cout << temp->data << " "<<temp->next<<endl;
}
int main()
{
    node *head = takeinput();
    display(head);
}