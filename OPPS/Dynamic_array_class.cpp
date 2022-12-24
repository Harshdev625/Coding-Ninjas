#include <iostream>
using namespace std;
class dynamicarray
{
    int *data;
    int nextindex;
    int capacity;

public:
    dynamicarray()
    {
        data = new int[5];
        nextindex = 0;
        capacity = 5;
    }
    void add(int element)
    {
        if (nextindex == capacity)
        {
            int *newdata = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            capacity *= 2;
        }
        data[nextindex] = element;
        nextindex++;
    }
    int get(int i) const
    {
        if (i < nextindex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }
    void add(int i, int element)
    {
        if (i < nextindex)
        {
            data[i] = element;
        }
        else if (i == nextindex)
        {
            add(element);
        }
        else
        {
            return;
        }
    }
    void display() const
    {
        for (int i = 0; i < nextindex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void operator=(dynamicarray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextindex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextindex = d.nextindex;
        this->capacity = d.capacity;
    }
    dynamicarray(dynamicarray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextindex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextindex = d.nextindex;
        this->capacity = d.capacity;
    }
};
int main()
{
    dynamicarray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.display();
    dynamicarray d3;
    d3 = d1;
    dynamicarray d2(d1);
    d1.add(0, 100);
    d1.display();
    d2.display();
    d3.display();
}