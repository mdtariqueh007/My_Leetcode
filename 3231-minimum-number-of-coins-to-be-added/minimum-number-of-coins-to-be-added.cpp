class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int i = 0;
        long long maxReach = 0;
        int cnt = 0;

        sort(coins.begin(),coins.end());

        while(maxReach<target){
            if(i<coins.size() && coins[i]<=maxReach+1){
                maxReach += coins[i];
                i++;
            }
            else{
                maxReach += (maxReach+1);
                cnt++;
            }
        }

        return cnt;
    }
};