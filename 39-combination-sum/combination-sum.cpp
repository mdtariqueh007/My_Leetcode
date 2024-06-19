class Solution {
    private:
    void solve(int ind,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&temp,int target){
        if(target<0){
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(ind>=candidates.size()){
            return;
        }

        for(int i = ind;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            solve(i,candidates,ans,temp,target-candidates[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        solve(0,candidates,ans,temp,target);

        return ans;
    }
};