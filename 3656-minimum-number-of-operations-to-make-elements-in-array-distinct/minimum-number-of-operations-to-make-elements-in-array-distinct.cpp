class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int cnt = 0;

        while(st.size()!=nums.size()){
            if(nums.size()<=3){
                nums.clear();
            }
            else{
                nums.erase(nums.begin(), nums.begin() + 3);
            }
            st.clear();
            for(auto it: nums){
                st.insert(it);
            }
            cnt++;
        }

        return cnt;


        
    }
};