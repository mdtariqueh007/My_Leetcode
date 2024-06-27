class Solution {
public:
    double minimumAverage(vector<int>& nums) {

        // multiset<int> mt;

        // for(int x : nums){
        //     mt.insert(x);
        // }

        sort(nums.begin(),nums.end());

        vector<double> averages;

        for(int i = 0;i<nums.size()/2;i++){
            int mini = nums[i];
            int maxi = nums[nums.size()- i - 1];

            averages.push_back((mini*1.0  + maxi * 1.0)/2.0);
            
        }

        sort(averages.begin(),averages.end());

        return averages[0];
        
        
    }
};