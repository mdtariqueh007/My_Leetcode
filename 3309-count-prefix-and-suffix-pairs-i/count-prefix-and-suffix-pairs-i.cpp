class Node {
public:
    Node* links[26] = {};
    int cnt = 0; // Count of words ending at this node

    bool contains(char c) {
        return links[c - 'a'] != NULL;
    }

    Node* get(char c) {
        return links[c - 'a'];
    }

    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }

    void incrementCount() {
        cnt++;
    }

    int getCount() {
        return cnt;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    // void insertChar(char c, Node*& node) {
    //     if (!node->contains(c)) {
    //         node->put(c, new Node());
    //     }
    //     node = node->get(c);
    //     node->incrementCount();
    // }

    // int countWords(char c, Node* node) {
    //     if (!node || !node->contains(c)) {
    //         return 0;
    //     }
    //     return node->get(c)->getCount();
    // }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        Trie prefixTrie, suffixTrie;

        for (string& s : words) {
            int n = s.length();
            Node* prefixNode = prefixTrie.root;
            Node* suffixNode = suffixTrie.root;

            string s1 = "", s2 = "";


            // Traverse through the word
            for (int i = 0; i < n; i++) {
                char pre = s[i];          // Character for prefix trie
                char suff = s[n - i - 1]; // Character for suffix trie (reversed)

                // Count matching words in both tries
                int cnt1 = 0, cnt2 = 0;
                // cnt1 += prefixTrie.countWords(pre, prefixNode);
                // cnt2 += suffixTrie.countWords(suff, suffixNode);

                // ans = min(cnt1, cnt2);
                // // Insert the character into both tries
                // prefixTrie.insertChar(pre, prefixNode);
                // suffixTrie.insertChar(suff, suffixNode);

                // if(prefixNode==NULL || !prefixNode->contains(pre)){
                //     break;
                // }
                // if(suffixNode==NULL || !suffixNode->contains(suff)){
                //     break;
                // }

                
                if(!prefixNode->contains(pre)){
                    prefixNode->put(pre, new Node());
                }
                if(!suffixNode->contains(suff)){
                    suffixNode->put(suff, new Node());
                }

                s1 = s1 + pre;
                s2 = suff + s2;

                prefixNode = prefixNode->get(pre);
                suffixNode = suffixNode->get(suff);

                if(prefixNode->getCount()>0 && suffixNode->getCount()>0){
                    if(s1==s2){
                        // cout<<s1<<"_______"<<s<<"\n";
                        ans += min(prefixNode->getCount(), suffixNode->getCount());
                    }
                }

                
               

                if(i==n-1){
                    prefixNode->incrementCount();
                    suffixNode->incrementCount();
                }

                

            }
        }

        return ans;
    }
};
