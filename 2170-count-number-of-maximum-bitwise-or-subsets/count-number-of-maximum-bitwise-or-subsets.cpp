class Solution {
    private:
    int solve(int ind,int currOr,vector<int>&nums,int maxOr){
        if(ind==nums.size()){
            if(currOr==maxOr){
                return 1;
            }
            else{
                return 0;
            }
        }

        int take = solve(ind+1, currOr|nums[ind],nums,maxOr);
        int notTake = solve(ind+1,currOr,nums,maxOr);

        return take + notTake;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {

        int maxOr = 0;

        int n = nums.size();

        for(int i = 0;i<n;i++){
            maxOr = maxOr|nums[i];
        }

        return solve(0,0,nums,maxOr);
        
    }
};