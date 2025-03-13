class Solution {
    private:
    vector<int> sum;
    int ans;
    void solve(int ind, vector<int>& jobs, int k){
        if(ind==jobs.size()){


            int maxi = *max_element(sum.begin(), sum.end());
            ans = min(ans, maxi);

            return;

        }

        unordered_set<int> seen;

        for(int i = 0;i<k;i++){

            if(sum[i] + jobs[ind]>=ans){
                continue;
            }

            if(seen.find(sum[i])!=seen.end()){
                continue;
            }

            seen.insert(sum[i]);

            sum[i] += jobs[ind];
            solve(ind+1, jobs, k);
            sum[i] -= jobs[ind];
        }
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {

        sum.resize(k, 0);
        ans = 1e9;

        solve(0, jobs, k);

        return ans;


        
    }
};