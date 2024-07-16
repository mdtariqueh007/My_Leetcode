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
    TreeNode* lowestCommonAncestor(TreeNode* root, int p , int q) {

        if(root==NULL || root->val==p || root->val==q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left==NULL) return right;
        
        if(right==NULL) return left;

        return root;
        
    }
    bool findPath(TreeNode* node, int target, string&path){
        if(node==NULL){
            return false;
        }

        if(node->val==target){
            return true;
        }

        path.push_back('L');
        if(findPath(node->left,target,path)==true){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(node->right,target,path)==true){
            return true;
        }
        path.pop_back();

        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root,startValue,destValue);

        string LCAtoStart = "";
        string LCAtoEnd = "";

        findPath(LCA,startValue,LCAtoStart);
        findPath(LCA,destValue,LCAtoEnd);

        for(int i = 0;i<LCAtoStart.size();i++){
            LCAtoStart[i] = 'U';
        }

        return LCAtoStart + LCAtoEnd;
    }
};