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
class FindElements {
    private:
    unordered_set<int> st;
    
    void dfs(TreeNode* node, int currVal){
        if(node==nullptr){
            return;
        }

        st.insert(currVal);
        dfs(node->left, 2 * currVal + 1);
        dfs(node->right, 2 * currVal + 2);
    }
public:
    FindElements(TreeNode* root) {

        dfs(root,0);
        
    }
    
    bool find(int target) {

        return st.find(target)!=st.end();
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */