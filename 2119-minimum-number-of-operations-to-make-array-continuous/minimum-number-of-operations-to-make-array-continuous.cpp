class Solution {
public:
    int minOperations(vector<int>& nums) {
        

        int n = nums.size();

        set<int> st(nums.begin(),nums.end());

        vector<int> temp;

        for(int it : st){
            temp.push_back(it);
        }

        int j = 0;

        int ans = 1e9;

        for(int i = 0;i<temp.size();i++){
            while(j<temp.size() && temp[j]<temp[i]+n){
                j++;
            }

            int inRange = j - i;
            int outRange = n - inRange;

            ans = min(ans,outRange);
        }

        return ans;


    }
};