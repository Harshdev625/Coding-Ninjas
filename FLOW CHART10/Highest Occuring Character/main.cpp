#include <iostream>
#include <cstring>
using namespace std;

char highestOccurringChar(char a[]){
     int freq[26] = { 0 };

    int m = -1;
    char result;
    int len = strlen(a);
    for (int i = 0; i < len; i++)
        freq[a[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        if (m< freq[i]) {
            m = freq[i];
            result = (char)(i + 'a');
        }
    return result;
}


int main()
{
    int n= 1e6;
    char a[n];
    cin >> a;
    cout << highestOccurringChar(a);
}

