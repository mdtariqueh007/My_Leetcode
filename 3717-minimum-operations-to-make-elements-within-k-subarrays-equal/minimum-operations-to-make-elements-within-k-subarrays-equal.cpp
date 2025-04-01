class Solution {
    private:
    long long dp[100001][16];
    vector<long long> calculateOpToMedians(vector<int>&nums, int k){
        int n = nums.size();

        multiset<int> low, high;

        int sz1 = k/2;
        int sz2 = k - sz1;

        vector<long long> ans;

        int median;

        long long leftSum = 0, rightSum = 0;

        for(int i = 0;i<n;i++){
            int val = nums[i];

            if(low.empty() || val<=*low.rbegin()){
                low.insert(val);
                leftSum += val;
            }
            else{
                high.insert(val);
                rightSum += val;
            }

            if(i>=k){

                int toRemove = nums[i-k];

                if(low.count(toRemove)){
                    low.erase(low.find(toRemove));
                    leftSum -= toRemove;
                }
                else{
                    high.erase(high.find(toRemove));
                    rightSum -= toRemove;
                }
            }

            if(low.size()>sz1){
                int x = *low.rbegin();
                low.erase(prev(low.end()));
                leftSum -= x;
                high.insert(x);
                rightSum += x;
            }

            if(high.size()>sz2){
                int x = *high.begin();
                high.erase(high.begin());
                rightSum -= x;
                low.insert(x);
                leftSum += x;
            }

            if(i>=k-1){
            
                median = *high.begin();
                long long op = ((low.size() * median) - leftSum) + (rightSum - (high.size() * median));
                ans.push_back(op);
            }
        }

        return ans;    
    }
    long long solve(int ind, int cnt, int x, int k, vector<int>&nums,vector<long long>&mediansOp){
        if(cnt==k){
            return 0;
        }
        if(ind>nums.size()-x){
            if(cnt<k){
                return 1e12;
            }
            else{
                return 0;
            }
        }

        if(dp[ind][cnt]!=-1){
            return dp[ind][cnt];
        }

        long long skip = solve(ind + 1, cnt, x, k, nums, mediansOp);

        long long take = mediansOp[ind] + solve(ind + x, cnt + 1, x, k, nums, mediansOp);

        return dp[ind][cnt] = min(skip, take);
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        memset(dp, -1, sizeof(dp));

        vector<long long> mediansOp = calculateOpToMedians(nums, x);

        return solve(0, 0, x, k, nums, mediansOp);
        
    }
};