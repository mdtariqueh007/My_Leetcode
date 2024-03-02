class Solution {
    private:
    int f(vector<int>&nums,long long target){
        int n = nums.size();

        unordered_map<int,int> mp;
       
        int cnt = 0;

        for(int i = 0;i<n;i++){
            if(target%nums[i]==0){
                int remain = target/nums[i];

                cnt += mp[remain];
            }

            mp[nums[i]]++;
        }

        return cnt;
    }
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {

       auto lambda1 = [&](int s,long long n){
           return s + f(nums2,n*n);
       };

       auto lambda2 = [&](int s,long long n){
           return s + f(nums1,n*n);
       };

       return accumulate(nums1.begin(),nums1.end(),0,lambda1) +
                accumulate(nums2.begin(),nums2.end(),0,lambda2);

        
    }
};