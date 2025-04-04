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
    int maxDepth = -1;
    vector<TreeNode*> deepestLeaves;
    void dfs(TreeNode* node, int depth){
        if(node==nullptr){
            return;
        }

        if(depth>maxDepth){
            maxDepth = depth;
            deepestLeaves = {node};
        }
        else if(depth==maxDepth){
            deepestLeaves.push_back(node);
        }

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
    TreeNode* lca(TreeNode* root, unordered_set<TreeNode*> nodeSet){
        if(root==nullptr || nodeSet.count(root)){
            return root;
        }

        TreeNode* left = lca(root->left, nodeSet);
        TreeNode* right = lca(root->right, nodeSet);

        if(left && right){
            return root;
        }
        
        return left?left:right;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        unordered_set<TreeNode*> nodeSet(deepestLeaves.begin(), deepestLeaves.end());
        return lca(root, nodeSet);
    }
};