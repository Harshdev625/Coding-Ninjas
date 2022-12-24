#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double geometricSum(int k)
{
    if (k == 0)
    {
        return 1;
    }
    double ans = geometricSum(k - 1);
    if (k > 0)
    {
        return ans + 1 / pow(2, k);
    }
    return 1 + ans;
}
int main()
{
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;
}
