class Solution {
    private:
    int getSumOfDig(int num){
        
        int ans = 0;

        while(num>0){

            ans += num%10;
            num /= 10;

        }

        return ans;
    }
public:
    int maximumSum(vector<int>& nums) {

        unordered_map<int,int> mp;

        int ans = -1;

        for(int x: nums){
            int sumOfDig = getSumOfDig(x);

            if(mp.find(sumOfDig)!=mp.end()){
                ans = max(ans, x + mp[sumOfDig]);
            }

            mp[sumOfDig] = max(mp[sumOfDig], x);
        }

        return ans;
        
    }
};