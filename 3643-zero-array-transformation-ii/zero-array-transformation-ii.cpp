class Solution {
    private:
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {

        int n = nums.size();

        vector<int> line(n+1, 0);

        for(int i = 0;i<k;i++){

            auto q = queries[i];

            int l = q[0];
            int r = q[1];
            int val = q[2];

            line[l] += val;
            line[r+1] -= val;
            
        }

        for(int i = 1;i<=n;i++){
            line[i] += line[i-1];
        }

        for(int i = 0;i<n;i++){
            if(line[i]<nums[i]){
                return false;
            }
        }

        return true;
        
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int low = 0;
        int high = queries.size();

        int ans = -1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(canFormZeroArray(nums, queries, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
        
    }
};