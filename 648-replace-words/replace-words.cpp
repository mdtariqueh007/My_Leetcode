class Node{
    public:
    Node* links[26];
    bool flag = false;
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
            if(!node->links[c-'a']){
                node->links[c-'a'] = new Node();
            }

            node = node->links[c-'a'];
        }

        node->flag = true;
    }

    string check(string word){
        Node* node = root;

        string s = "";

        for(char c : word){
            if(!node->links[c-'a']){
                break;
            }

            s += c;
            node = node->links[c-'a'];
            if(node->flag){
                return s;
            }
        }

        return word;
    }
};

class Solution {
    private:
    Trie* tr = new Trie();
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string s : dictionary){
            tr->insert(s);
        }

        istringstream ss(sentence);

        string word = "";
        string ans = "";

        while(ss>>word){
            ans += tr->check(word);
            ans += ' ';
        }

        ans.pop_back();

        return ans;
    }
};