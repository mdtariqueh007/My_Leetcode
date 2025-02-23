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
    TreeNode* helper(int preStart, int preEnd,int postStart, vector<int>& preorder, vector<int>&postorder){
        if(preStart>preEnd){
            return nullptr;
        }

        if(preStart==preEnd){
            return new TreeNode(preorder[preStart]);
        }

        TreeNode* node = new TreeNode(preorder[preStart]);

        int leftRootVal = preorder[preStart+1];

        int numOfNodesInLeft = 1;

        while(postorder[postStart+numOfNodesInLeft - 1]!=leftRootVal){
            numOfNodesInLeft++;
        }

        node->left = helper(preStart+1, preStart+numOfNodesInLeft,postStart,preorder, postorder);
        node->right = helper(preStart+numOfNodesInLeft+1, preEnd, postStart+numOfNodesInLeft, preorder, postorder);

        return node;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return helper(0,preorder.size()-1,0, preorder, postorder);
    }
};