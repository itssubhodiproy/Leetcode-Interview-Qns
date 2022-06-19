class Node{
    Node* links[26];
    int NOP=0;
    int NOW=0;
    public:
    //check if it contains key
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    //Add a new reference Trie node
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    //to pointing to next reference
    Node *next(char ch){
        return links[ch-'a'];
    }
    //increment prefix count
    void incrementPrefix(){
        NOP++;
    }
    //increment word count
    void incrementWord(){
        NOW++;
    }
    //return No of Words
    int NoOfWords(){
        return NOW;
    }
    //return No of prefix
    int NoOfPrefix(){
        return NOP;
    }
    //reduce prefix count
    void decrementPrefix(){
        NOP--;
    }
    //reduce word count
    void decrementWord(){
        NOW--;
    }
};
class Trie{
        Node* root;
    public:
    Trie(){
        root= new Node();
    }
    void insert(string &word){
        Node* node= root;
        for(auto it: word){
            if(!node->containsKey(it))
                node->put(it,new Node());
            node=node->next(it);
            node->incrementPrefix();
        }
        node->incrementWord();
    }
    int countWordsEqualTo(string &word){
        Node* node=root;
        for(auto it: word){
            if(!node->containsKey(it))
                return 0;
            node=node->next(it);
        }
        node->NoOfWords();
    }
    int countWordsStartingWith(string &word){
        Node* node=root;
        for(auto it: word){
            if(!node->containsKey(it))
                return 0;
            node=node->next(it);
        }
        node->NoOfPrefix();
    }
    void erase(string &word){
        Node* node=root;
        for(auto it: word){
            if(!node->containsKey(it))
                return;
            node=node->next(it);
            node->decrementPrefix();
        }
        node->decrementWord();
    }
};
