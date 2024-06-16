class Node{
    public:
    Node* child[26];
    bool isEnd = false;;
    int linkCount = 0;

   void put(char ch, Node* node){
    if(child[ch-'a']==NULL){
        child[ch-'a'] = node;
        linkCount++;
    }
   }

   bool contains(char ch){
    return child[ch-'a']!=NULL;
   }

   int getLinks(){
    return linkCount;
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
            if(node->contains(c)==false){
                node->put(c,new Node());
            }

            node = node->child[c-'a'];
        }

        node->isEnd = true;
    }

    string searchLongestPrefix(string word){
        Node* node = root;
        string prefix = "";
        for(char c: word){
            if(node->contains(c) && node->getLinks()==1 && node->isEnd==false){
                prefix += c;
                node = node->child[c-'a'];
            }
            else{
                break;
            }
        }

        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }

        Trie tr;

        for(int  i= 1;i<strs.size();i++){
            tr.insert(strs[i]);
        }

        return tr.searchLongestPrefix(strs[0]);
    }
};