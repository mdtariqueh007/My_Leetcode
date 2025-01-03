class Solution {
    private:
    int findMinMidEnd(vector<int>&prefix, int start, int end, int sum){
        int low = start;
        int high = end;

        int ans = high + 1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(prefix[mid]>=sum){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }

    int findMaxMidEnd(vector<int>& prefix, int start, int end, int sum){
        int low = start;
        int high = end;

        int ans = low - 1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(prefix[mid]<=sum){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
public:
    int waysToSplit(vector<int>& nums) {

        int n = nums.size();
        const int mod = 1e9 + 7;

        vector<int> prefix(n,0);

        prefix[0] = nums[0];

        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        long long ans = 0;

        for(int l = 0;l<n-2;l++){
            int leftSum = prefix[l];

            int remainingSum = prefix[n-1] - leftSum;

            int maxPossMidSum = remainingSum/2;

            int minMid = findMinMidEnd(prefix, l+1, n - 2, 2 * leftSum);
            int maxMid = findMaxMidEnd(prefix, l+1, n - 2, leftSum + maxPossMidSum);

            int possMidSub = max(maxMid - minMid + 1, 0);

            ans = (ans + possMidSub)%mod;
        }

        return ans;
        
    }
};