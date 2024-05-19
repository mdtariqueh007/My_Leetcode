class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();

        long long sum = 0;

        vector<long long> profit;

        for(long long num : nums){
            sum += num;

            profit.push_back((num^k) - num);
        }

        int end = profit.size();

        sort(profit.rbegin(),profit.rend());

        for(int i = 0;i<end-1;i = i + 2){
            
            
            long long gain = profit[i]+profit[i+1];
                
            

            if(gain>0){
                sum += gain;
            }
        }

        return sum;


    }
};