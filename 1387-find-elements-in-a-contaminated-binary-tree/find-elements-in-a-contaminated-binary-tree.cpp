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
    TreeNode* rootHead;
    void dfs(TreeNode* node, int currVal){
        if(node==nullptr){
            return;
        }

        if(node->val!=currVal){
            node->val = currVal;
        }
        dfs(node->left, 2 * currVal + 1);
        dfs(node->right, 2 * currVal + 2);
    }
    bool dfs2(TreeNode* node,int target){
        if(node==nullptr){
            return false;
        }

        if(node->val==target){
            return true;
        }

        return dfs2(node->left, target) || dfs2(node->right, target);
    }
public:
    FindElements(TreeNode* root) {

        rootHead = root;

        dfs(root, 0);


        
    }
    
    bool find(int target) {

        return dfs2(rootHead, target);

        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */