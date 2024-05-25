class Node{
    public:
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;

        for(char c : word){
            if(!node->containsKey(c)){
                node->put(c,new Node());
            }

            node = node->get(c);
        }

        node->setEnd();
    }

    bool checkAllPrefix(string word){
        Node* node = root;

        for(char c : word){
            if(!node->containsKey(c)){
                return false;
            }
            else{
                node = node->get(c);
                if(!node->isEnd()){
                    return false;
                }
            }
        }

        return true;
    }
};

class Solution {
    private:
    Trie* tr = new Trie();
public:
    string longestWord(vector<string>& words) {
        for(string s : words){
            tr->insert(s);
        }

        string longest = "";

        for(string s : words){
            if(tr->checkAllPrefix(s)){
                if(s.length()>longest.length() || (s.length()==longest.length() && s<longest)){
                    longest = s;
                }
            }
        }

        return longest;
    }
};