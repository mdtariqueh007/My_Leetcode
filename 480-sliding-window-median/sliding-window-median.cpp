class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        multiset<int> low, high;

        int sz1 = k/2;
        int sz2 = k - sz1;

        vector<double> ans;

        double median;

        for(int i = 0;i<n;i++){
            int val = nums[i];

            if(low.empty() || val<=*low.rbegin()){
                low.insert(val);
            }
            else{
                high.insert(val);
            }

            if(i>=k){

                int toRemove = nums[i-k];

                if(low.count(toRemove)){
                    low.erase(low.find(toRemove));
                }
                else{
                    high.erase(high.find(toRemove));
                }
            }

             while(low.size()>sz1){
                int x = *low.rbegin();
                low.erase(prev(low.end()));
                high.insert(x);
            }

            while(high.size()>sz2){
                int x = *high.begin();
                high.erase(high.begin());
                low.insert(x);
            }

            if(i>=k-1){
            
                if(k&1){
                    median = *high.begin();
                }
                else{
                    median = (*high.begin()*1.0 + *low.rbegin()*1.0)*1.0/2.0;
                }

                ans.push_back(median);

            }

        }

        return ans;
        
    }
};