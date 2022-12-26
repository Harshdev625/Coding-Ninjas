#include <iostream>
#include <cstring>
int getCodes(string input, string output[10000])
{
    if (input.length() == 0)
    {
        output[0] = "";
        return 1;
    }
    string out1[10000], out2[10000];
    int ans1 = getCodes(input.substr(1), out1);
    int j = 0;
    char ch1 = (input[0] - '0') + 'a' - 1;
    for (int i = 0; i < ans1; i++)
    {
        output[j++] = ch1 + out1[i];
    }
    if (input.length() >= 2)
    {
        int ans2 = getCodes(input.substr(2), out2);
        int num = (input[0] - '0') * 10 + (input[1] - '0');
        if (num >= 10 && num <= 26)
        {
            char ch2 = num + 'a' - 1;
            for (int i = 0; i < ans2; i++)
            {
                output[j++] = ch2 + out2[i];
            }
        }
    }
    return j;
}

using namespace std;

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
