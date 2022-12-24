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
        next= NULL;
    }
};
template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return getSize() == 0;
    }
    T front()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
    T dequeue()
    {
        if (head == NULL)
        {
            return -1;
        }
        Node <T> *newnode = head;
        T ans = head->data;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        delete newnode;
        size--;
        return ans;
    }
    void enqueue(T element)
    {
        if (head == NULL)
        {
            Node<T> *newdata = new Node<T>(element);
            head = newdata;
            tail = newdata;
        }
        else
        {
            Node<T> *newdata = new Node<T>(element);
            tail->next = newdata;
            tail = newdata;
        }
        size++;
    }
};
int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
}