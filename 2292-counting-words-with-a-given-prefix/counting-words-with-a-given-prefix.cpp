class Node{
    public:
    Node* links[26] = {};
    int cnt = 0;

    bool contains(char c){
        return links[c-'a']!=NULL;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    void put(char c, Node* node){
        links[c-'a'] = node;
    }

    void incrementCnt(){
        cnt++;
    }

    int getCnt(){
        return cnt;
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string& word){
        Node* node = root;

        for(char c: word){
            if(!node->contains(c)){
                node->put(c, new Node());
            }

            node = node->get(c);
            node->incrementCnt();
        }
    }

    int countWordsWithPrefix(string& prefix){
        Node* node = root;

        for(char c: prefix){
            if(!node->contains(c)){
                return 0;
            }
            node = node->get(c);
        }

        return node->getCnt();
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        Trie tr;

        for(string& s: words){
            tr.insert(s);
        }

        int ans = tr.countWordsWithPrefix(pref);

        return ans;
        
    }
};