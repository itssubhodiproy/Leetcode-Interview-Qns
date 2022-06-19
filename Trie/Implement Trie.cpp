struct Node{
    Node* links[26];
    bool end=false;
    //check if it contains key
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    //Add a new reference Trie node
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    //to pointing to next reference
    Node* next(char ch){
        return links[ch-'a'];
    }
    //set that it is End of the word
    void setEnd(){
        end=true;
    }
    //return whether we finish or not
    bool endStatus(){
        return end;
    }
};

class Trie {
private: 
    Node* root;
public:
    Trie() {
        root=new Node();
    }
void insert(string word) {
        Node* node=root;
        for(auto it: word){
            if(!node->containsKey(it))
                node->put(it,new Node());
            node=node->next(it);
        }
        node->setEnd();
    }
bool search(string word) {
        Node* node=root;
        for(auto it: word){
            if(!node->containsKey(it))
                return false;
            node=node->next(it);
        }
        return node->endStatus();
    }
bool startsWith(string prefix) {
        Node* node=root;
        for(auto it: prefix){
            if(!node->containsKey(it))
                return false;
            node=node->next(it);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
