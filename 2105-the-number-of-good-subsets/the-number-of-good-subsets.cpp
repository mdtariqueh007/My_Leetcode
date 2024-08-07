class Solution {
    private:
    const int mod = 1e9 + 7;
    long long powerMod(long long x, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n = n >> 1;
    }

    return res;
}
    void checkWeCanTake(int x,vector<int>&primes,map<int,int>&mp){
        bool flag = true;

        int num = 0;

        for(int i = 0;i<10;i++){
            int cnt = 0;

            while(x%primes[i]==0){
                x = x/primes[i];
                cnt++;

                if(cnt>1){
                    flag = false;
                    break;
                }
            }

            if(cnt==1){
                num = num | (1<<i);
            }
        }

        if(flag){
            mp[num]++;
        }
    }
    long long solve(int ind,vector<int>&temp,int mask,map<int,int>&mp){
        if(ind==temp.size()){
            return mask>0;
        }

        long long notTake = solve(ind+1,temp,mask,mp);
        long long take = 0;

        if((mask & temp[ind])==0){
            take = (mp[temp[ind]]%mod)*(solve(ind+1,temp,mask|temp[ind],mp)%mod) % mod;
        }

        return (notTake%mod + take%mod)%mod;
    }
public:
    int numberOfGoodSubsets(vector<int>& nums) {

        int n = nums.size();

        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

        map<int,int> mp;

        vector<int> temp;

        int cntOnes = 0;

        for(int x : nums){
            if(x==1){
                cntOnes++;
            }
            else{
                checkWeCanTake(x,primes,mp);
            }
        }

        for(auto &it : mp){
            temp.push_back(it.first);
        }


        long long ans = solve(0,temp,0,mp);

        ans = ((ans%mod) * powerMod(2,cntOnes,mod)%mod)%mod;

        return ans;




        
    }
};