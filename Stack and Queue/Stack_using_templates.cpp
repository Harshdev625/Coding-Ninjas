#include <iostream>
using namespace std;
template <typename A>
class Stackusingarray
{
    A *data;
    int nextindex;
    int capacity;

public:
    Stackusingarray()
    {
        int size;
        cin >> size;
        data = new A[size];
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
    void push(A element)
    {
        if (nextindex == capacity)
        {
            A *newarray = new A[2 * capacity];
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
    A pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        nextindex--;
        return data[nextindex];
    }
    A top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextindex - 1];
    }
};
int main()
{
    Stackusingarray<char> s;
    s.push(101);
    s.push(104);
    s.push(103);
    s.push(104);
    s.push(105);
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
}