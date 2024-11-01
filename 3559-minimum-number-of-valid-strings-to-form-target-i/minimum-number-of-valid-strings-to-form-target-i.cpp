class Node{
    public:
    Node* links[26];

    Node(){
        for(int i = 0;i<26;i++){
            links[i] = NULL;
        }
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

        for(char c : word){
            if(node->links[c-'a']==NULL){
                node->links[c - 'a'] = new Node();
            }

            node = node->links[c - 'a'];
        }

        
    }
    int solve(int ind, string& target,vector<int>&dp){
        if(ind==target.size()){
            return 0;
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }

        int ans = 1e6;

        Node* node = root;

        int i = ind;

        while(i<target.size()){
            char ch = target[i];
            if(node->links[ch-'a']==NULL){
                break;
            }

            ans = min(ans, 1 + solve(i+1,target,dp));

            node = node->links[ch-'a'];
            i++;
        }

        return dp[ind] = ans;

            

            
    }
};

class Solution {
    private:
    
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie* tr = new Trie();

        for(string s : words){
            tr->insert(s);
        }

       int n = target.size();

       vector<int> dp(n+1,-1);

       

        int ans = tr->solve(0,target,dp);

        if(ans>=1e6){
            return -1;
        }

        return ans;

       


        



    }
};