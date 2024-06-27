class Solution {
public:
    double minimumAverage(vector<int>& nums) {

        multiset<int> mt;

        for(int x : nums){
            mt.insert(x);
        }

        vector<double> averages;

        for(int i = 0;i<nums.size()/2;i++){
            int mini = *mt.begin();
            int maxi = *(--mt.end());

            mt.erase(mt.begin());
            mt.erase(--mt.end());

            averages.push_back((mini*1.0  + maxi * 1.0)/2.0);
            
        }

        sort(averages.begin(),averages.end());

        return averages[0];
        
        
    }
};