#include <iostream>
#include <climits>
using namespace std;
class Stackusingarray
{
    int *data;
    int nextindex;
    int capacity;

public:
    Stackusingarray()
    {
        int size;
        cin >> size;
        data = new int[size];
        nextindex = 0;
        capacity = size;
    }
    int size()
    {
        return nextindex;
    }
    bool isEmpty()
    {
        if (nextindex == 0)
        {
            return true;
        }
        return false;
    }
    void push(int element)
    {
        if (nextindex == capacity)
        {
            int *newarray = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newarray[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newarray;
        }
        data[nextindex] = element;
        nextindex++;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextindex--;
        return data[nextindex];
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextindex - 1];
    }
};
int main()
{
    Stackusingarray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
}