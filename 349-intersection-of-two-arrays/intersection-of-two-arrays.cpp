class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size(),n = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i = 0,j = 0;
        unordered_set<int> intersection;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums2[j]<nums1[i]){
                j++;
            }
            else{
    
                intersection.insert(nums1[i]);
                i++;
                j++;
            }
        }

        vector<int> ans(intersection.begin(),intersection.end());

        return ans;
        
    }
};