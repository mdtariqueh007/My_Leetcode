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
       string rootToStart = "";
       string rootToEnd = "";

       findPath(root,startValue,rootToStart);
       findPath(root,destValue,rootToEnd);

       int i = 0;
       int j = 0;
       while(rootToStart[i]==rootToEnd[j]){
        i++;
        j++;
       }

       int ind = i;

       while(ind<rootToStart.size()){
        rootToStart[ind] = 'U';
        ind++;
       }

       return rootToStart.substr(i) + rootToEnd.substr(j);
    }
};