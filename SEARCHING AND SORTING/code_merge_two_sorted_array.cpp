#include <iostream>
using namespace std;
void merge(int *a, int n, int *b, int m, int *ans)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            ans[k] = a[i];
            i++;
            k++;
        }
        else
        {
            ans[k] = b[j];
            j++;
            k++;
        }
    }
    while (j <= m - 1)
    {
        ans[k] = b[j];
        j++;
        k++;
    }
    while (i <= n - 1)
    {
        ans[k] = a[i];
        i++;
        k++;
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    int *b = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int *ans = new int[m + n];
    merge(a, n, b, m, ans);
    for (int i = 0; i < n + m; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    delete[] a;
    delete[] b;
    delete[] ans;
}