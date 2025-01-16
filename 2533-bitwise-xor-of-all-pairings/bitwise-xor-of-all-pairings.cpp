class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        if(n%2==0 && m%2==0){
            return 0;
        }

        int xor1 = 0, xor2 = 0;

        if(n%2!=0){
            for(int x: nums2){
                xor1 ^= x;
            }
        }
        if(m%2!=0){
            for(int x: nums1){
                xor2 ^= x;
            }
        }
        
        return xor1^xor2;

    }
};