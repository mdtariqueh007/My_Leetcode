class Node{
    public:
    Node* child[26];
    int cnt;
    Node(){
        for(int i = 0;i<26;i++){
            child[i] = NULL;
        }

        cnt = 0;
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
            if(!node->child[c-'a']){
                node->child[c-'a'] = new Node();
            }

           

            node = node->child[c-'a'];
            node->cnt++;
        }
    }

    int count(string s){
        Node* node = root;

        int ans = 0;

        for(char c : s){
            ans += node->child[c-'a']->cnt;
            node = node->child[c-'a'];
        }

        return ans;
    }

};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {

        Trie t;

        for(string s : words){
            t.insert(s);
        }

        vector<int> ans;

        for(string s: words){
            ans.push_back(t.count(s));
        }

        return ans;
        
    }
};