#include<bits/stdc++.h>
#include "Trie.h"
using namespace std;
int main(){
    Trie t;
    t.insertword("and");
    t.insertword("are");
    t.insertword("dot");
    cout<<t.search("and")<<endl;
    t.removeword("and");
    cout<<t.search("and")<<endl;
}