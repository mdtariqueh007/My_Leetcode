/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void dfs(TreeNode* root,string s,vector<string>&st){
        if(root==NULL){
            // reverse(s.begin(),s.end());
            // st.push_back(s);
            return;
        }

        

        s += (char)(root->val + 'a');
        if(root->left==NULL && root->right==NULL){
            string t = s;
            reverse(t.begin(),t.end());
            st.push_back(t);
            return;
        }
        dfs(root->left,s,st);
        dfs(root->right,s,st);
    }
public:
    string smallestFromLeaf(TreeNode* root) {

        vector<string> temp;

        dfs(root,"",temp);

        sort(temp.begin(),temp.end());

        return temp[0];
        
    }
};