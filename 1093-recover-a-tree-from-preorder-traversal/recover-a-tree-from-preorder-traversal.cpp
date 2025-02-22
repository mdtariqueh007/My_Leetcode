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
    TreeNode* helper(int depth, string& traversal, int &ind){
        if(ind>=traversal.length()){
            return nullptr;
        }

        int dashCount = 0;

        while(ind+dashCount<traversal.length() && traversal[ind+dashCount]=='-'){
            dashCount++;
        }

        if(depth!=dashCount){
            return nullptr;
        }

        ind += dashCount;

        int val = 0;

        while(ind<traversal.length() && isdigit(traversal[ind])){
            val = val * 10 + (traversal[ind] - '0');
            ind++;
        }

        TreeNode* node = new TreeNode(val);

        node->left = helper(depth+1, traversal, ind);
        node->right = helper(depth+1, traversal, ind);

        return node;

        
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        return helper(0, traversal,index);
    }
};