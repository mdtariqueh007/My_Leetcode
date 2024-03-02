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

        int cnt = 0;

        for(int i = 0;i<nums1.size();i++){
            cnt += f(nums2,1LL*nums1[i]*nums1[i]);
        }

        for(int i = 0;i<nums2.size();i++){
            cnt += f(nums1,1LL*nums2[i]*nums2[i]);
        }

        return cnt;
        
    }
};