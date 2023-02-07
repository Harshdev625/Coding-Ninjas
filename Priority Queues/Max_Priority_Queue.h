#include <vector>
#include <climits>
class PriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childindex = pq.size() - 1;
        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (pq[childindex] > pq[parentindex])
            {
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentindex;
        }
    }
    int getMax()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }
        return pq[0];
    }
    int removeMax()
    {
        int n = getSize();
        if (n < 0)
        {
            return INT_MIN;
        }
        int elementtodelete = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentindex = 0;
        while (parentindex < n)
        {
            int leftchildindex = 2 * parentindex + 1;
            int rightchildindex = 2 * parentindex + 2;
            int maxindex = -1;
            if (leftchildindex < n && leftchildindex < n)
            {
                if (pq[leftchildindex] < pq[rightchildindex])
                {
                    maxindex = rightchildindex;
                }
                else
                {
                    maxindex = leftchildindex;
                }
            }
            else if (leftchildindex < n)
            {
                maxindex = leftchildindex;
            }
            else if (rightchildindex < n)
            {
                maxindex = rightchildindex;
            }
            if (maxindex != -1 && pq[maxindex] > pq[parentindex])
            {
                int temp = pq[maxindex];
                pq[maxindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                break;
            }
        }
        return elementtodelete;
    }
};