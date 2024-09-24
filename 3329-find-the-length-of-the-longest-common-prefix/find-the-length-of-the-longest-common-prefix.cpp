class Node{
    public:
    Node* child[10];
    Node(){
        for(int i = 0;i<10;i++){
            child[i] = NULL;
        }
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;

        string s = to_string(num);

        for(char c : s){
            int dig = c - '0';

            if(!node->child[dig]){
                node->child[dig] = new Node(); 
            }

            node = node->child[dig];
        }
    }

    int findLongestPrefix(int num){
        Node* node = root;
        string s = to_string(num);

        int cnt = 0;

        for(char c : s){
            int dig = c - '0';

            if(node->child[dig]){
                cnt++;

                node = node->child[dig];
            }
            else{
                break;
            }
        }

        return cnt;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;

        for(int num : arr1){
            t.insert(num);
        }

        int ans = 0;

        for(int num: arr2){
            int len = t.findLongestPrefix(num);

            ans = max(ans,len);
        }

        return ans;
    }
};