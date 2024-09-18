class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto lambda = [&](int a,int b){
            return (to_string(a)+to_string(b))>(to_string(b)+to_string(a));
        };

        sort(nums.begin(),nums.end(),lambda);

        string ans = "";

        for(int it : nums){
            ans += to_string(it);
        }

        return ans[0]=='0'?"0":ans;
        
    }
};