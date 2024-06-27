class Solution {
public:
    double minimumAverage(vector<int>& nums) {

        // multiset<int> mt;

        // for(int x : nums){
        //     mt.insert(x);
        // }

        sort(nums.begin(),nums.end());

        // vector<double> averages;

        double ans = 1e9;

        for(int i = 0;i<nums.size()/2;i++){
            int mini = nums[i];
            int maxi = nums[nums.size()- i - 1];

            ans= min(ans,((mini*1.0  + maxi * 1.0)/2.0));
            
        }

        // sort(averages.begin(),averages.end());

        return ans;
        
        
    }
};