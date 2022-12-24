#include <iostream>
#include <cstring>
#include<string.h>
using namespace std;

void trimSpaces(char a[]) {
     char x = a[strlen(a)-1];
    int j = 0;
    for(int i=0;i<strlen(a);i++)
    {
         if(a[i]!=' ')
        {
            a[j] = a[i];
            j++;
        }
    }
    a[j] = '\0';
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}

