/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node{
    public:
    Node *links[26];
    bool flag = false;

    Node(){

    }

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put (char ch , Node *n){
        links[ch-'a']=n;
    }

    Node *get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};


class Trie {

public:

    /** Initialize your data structure here. */
    Node* root;
    Trie() {
      root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* n = root;
        for(int i=0;i<word.size();i++){
            if(n->containsKey(word[i])==false){
                Node *tmp = new Node();
                n->put(word[i], tmp);
            }
            n = n->get(word[i]);
        }
        n->setEnd();

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* n = root;
        for(auto i:word){
            if(n->containsKey(i)==false) return false;
            n = n->get(i);
        }
        return n->isEnd();

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* n = root;
        for(auto i:prefix){
            if(n->containsKey(i)==false) return false;
            n = n->get(i);
        }
        return true;
    }
};