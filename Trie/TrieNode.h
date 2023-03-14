class TrieNode{
    public:
    char data;
    TrieNode**children;
    bool isterminal;
    TrieNode(char data){
        this->data=data;
        isterminal=false;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};