#include <iostream>
#include <string>
using namespace std;
// Approach 1 
void printsubsequences(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }
    printsubsequences(input.substr(1), output);
    printsubsequences(input.substr(1), output + input[0]);
}
// Approach 2
void printsubsequences(string input, string output)
{
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }
    printsubsequences(input.substr(0,input.size()-1),output);
    printsubsequences(input.substr(0,input.size()-1),input.substr(input.size()-1)+output);
}
int main()
{
    string input;
    cin >> input;
    string output = "";
    printsubsequences(input, output);
}