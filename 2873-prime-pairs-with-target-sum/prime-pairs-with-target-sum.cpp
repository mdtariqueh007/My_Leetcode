class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> prime(n+1,1);

        prime[0] = prime[1] = 0;

        for(int i = 2;i*i<=n;i++){
            if(prime[i]){
                for(int j = i*i;j<=n;j = j + i){
                    prime[j] = 0;
                }
            }
        }

        vector<vector<int>> ans;

        for(int i = 2;i<=n/2;i++){
            int j = n - i;

            if(prime[i] && prime[j]){
                ans.push_back({i,j});
            }
        }

        return ans;
    }
};