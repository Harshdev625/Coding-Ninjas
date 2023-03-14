#include "TrieNode.h"
#include <string>
using namespace std;
class Trie{
    TrieNode*root;
    public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insertword(TrieNode*root,string word){
        if(word.size()==0){
            root->isterminal=true;
            return;
        }
        TrieNode*child;
        int index=word[0]-'a';
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertword(child,word.substr(1));
    }
    void insertword(string word){
        insertword(root,word);
    }
    bool search(TrieNode*root,string word){
        if(word.size()==0){
            return root->isterminal;
        }
        int index=word[0]-'a';
        if(root->children[index]){
            return search(root->children[index],word.substr(1));
        }
        return false;
    }
    bool search(string word){
        return search(root,word);
    }
    void removeword(TrieNode*root,string word){
        if(word.size()==0){
            root->isterminal=false;
            return;
        }

        int index=word[0]-'a';
        if(!root->children[index])return;
        removeword(root->children[index],word.substr(1));
        if(!root->children[index]->isterminal){
            for(int i=0;i<26;i++){
                if(root->children[index]->children[i])return;
            }
            root->children[index]=nullptr;
        }
    }
    void removeword(string word){
        removeword(root,word);
    }
};