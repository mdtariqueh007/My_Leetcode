class Solution {
    private:
    int countDistinctPrimes(int n){
        set<int> primeFactors;

        while(n%2==0){
            primeFactors.insert(2);
            n /= 2;
        }

        for(int i = 3;i*i<=n;i+=2){
            while(n%i==0){
                primeFactors.insert(i);
                n /= i;
            }
        }

        if(n>1){
            primeFactors.insert(n);
        }

        return primeFactors.size();
    }
    vector<int> nextGreaterElement(vector<int>&nums){
        int n = nums.size();
        vector<int> nge(n, n);
        stack<int> st;

        for(int i = n - 1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }

            if(!st.empty()){
                nge[i] = st.top();
            }


            st.push(i);
        }

        return nge;
    }
    vector<int> previousGreaterOrEqual(vector<int>&nums){
        int n = nums.size();
        vector<int> pse(n ,- 1);
        stack<int> st;

        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }

            if(!st.empty()){
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }
    long long powerMod(long long base, long long exp, int mod){
        long long res = 1;

        base = base%mod;

        while(exp>0){
            if(exp&1){
                res = (res * base)%mod;
            }
            base = (base * base)%mod;
            exp /= 2;
        }

        return res;
    }
public:
    int maximumScore(vector<int>& nums, int k) {

        int n = nums.size();
        const int mod = 1e9 + 7;

        vector<int> primeScore(n, 0);

        for(int i = 0;i<n;i++){
            primeScore[i] = countDistinctPrimes(nums[i]);
        }

        vector<int> nge = nextGreaterElement(primeScore);
        vector<int> pse = previousGreaterOrEqual(primeScore);

        priority_queue<pair<int,int>> pq;

        for(int i = 0;i<n;i++){
            pq.push({nums[i], i});
        }

        long long score = 1;

        while(k>0 && !pq.empty()){
            int num = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            long long right = nge[ind] - ind;
            long long left = ind - pse[ind];

            long long total = left * right;

            if(k<=total){
                score = (score * powerMod(num, k, mod))%mod;
                k = 0;
            }
            else{
                score = (score * powerMod(num, total, mod))%mod;
                k -= total;
            }

            
        }

        return score;
    }
};