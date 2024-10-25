struct Node{
    Node* links[27];
    bool isLeaf = false;

    bool containsKey(int ch){
        return links[ch]!=NULL;
    }
    Node* get(int ch){
        return links[ch];
    }
    void put(int ch,Node* node){
        links[ch] = node;
    }
    void setEnd(){
        isLeaf = true;
    }
    bool isEnd(){
        return isLeaf;
    }
};

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    bool insert(string word){
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            int ind;
            if(word[i]=='/'){
                ind = 26;
            }
            else{
                ind = word[i] - 'a';
            }

            if(!node->containsKey(ind)){
                node->put(ind,new Node());
            }

            node = node->get(ind);

            if(word[i+1]=='/' && node->isEnd()){
                return false;
            }
        }

        node->setEnd();

        return true;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        vector<string> ans;

        Trie* tr = new Trie();

        for(string f : folder){
            if(tr->insert(f)){
                ans.push_back(f);
            }
        }

        return ans;
    }
};