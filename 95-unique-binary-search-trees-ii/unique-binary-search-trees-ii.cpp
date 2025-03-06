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
    map<pair<int,int>, vector<TreeNode*>> dp;
    vector<TreeNode*> solve(int start, int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(nullptr);
            return ans;
        }

        if(dp.find({start, end})!=dp.end()){
            dp[{start, end}];
        }

        for(int i = start;i<=end;i++){
            vector<TreeNode*> leftSubTrees = solve(start, i - 1);
            vector<TreeNode*> rightSubTrees = solve(i+1, end);

            for(auto l: leftSubTrees){
                for(auto r: rightSubTrees){
                    TreeNode* root = new TreeNode(i, l, r);
                    ans.push_back(root);
                }
            }
        }

        return dp[{start,end}] = ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {

        return solve(1, n);
        
    }
};