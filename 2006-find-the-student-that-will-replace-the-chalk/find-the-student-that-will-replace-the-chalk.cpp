class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {

        int n = chalk.size();

        vector<long long> prefix(n,0);

        prefix[0] = chalk[0];

        for(int i = 1;i<chalk.size();i++){
            prefix[i] = prefix[i-1] + chalk[i];
        }

        k = k%prefix.back();

        int low = 0;
        int high = n - 1;

        int ans = n;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(prefix[mid]<=k){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
        
    }
};