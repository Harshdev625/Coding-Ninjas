#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class Stack
{
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = nullptr;
        size = 0;
    }
    void push(T element)
    {
        Node<T> *newnode = new Node(element);
        newnode->next = head;
        head = newnode;
        size++;
    }
    T pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        Node<T> *newnode = head;
        T value = head->data;
        head = head->next;
        delete newnode;
        size--;
        return value;
    }
    T top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return head->data;
    }
    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }
    int getsize()
    {
        return size;
    }
};
int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.top() << " " << s.pop() << " " << s.getsize() << " " << s.isEmpty();
}