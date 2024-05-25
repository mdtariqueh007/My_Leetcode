class Node{
    public:
    Node* links[26];
    bool flag = false;
    int diff = 0;

    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    void put(char c, Node* node){
        links[c-'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }

    void incr(){
        diff++;
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

        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word){
        Node* node = root;

        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }

            node = node->get(word[i]);
        }

        return node->isEnd();
    }
};



class MagicDictionary {
    private:
    Trie* tr;
public:
    MagicDictionary() {
        tr = new Trie(); 
    }
    
    void buildDict(vector<string> dictionary) {
        for(string s : dictionary){
            tr->insert(s);
        }
    }
    
    bool search(string searchWord) {

        for(int i = 0;i<searchWord.size();i++){
            for(int j = 0;j<26;j++){
                char c = j + 'a';

                if(c==searchWord[i]){
                    continue;
                }
                char temp = searchWord[i];
                searchWord[i] = c;

                if(tr->search(searchWord)){
                    return true;
                }

                searchWord[i] = temp;
            }
        }

        return false;
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */