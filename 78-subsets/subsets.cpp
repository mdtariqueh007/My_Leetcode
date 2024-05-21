class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();
        int powSize = pow(2,n);
        vector<vector<int>> answer;
        for(int counter = 0;counter<powSize;counter++){
            vector<int> v;
            for(int  j = 0;j<n;j++){
                if((counter&(1<<j))!=0){
                    v.push_back(nums[j]);
                }
            }
            answer.push_back(v);
        }


        return answer;
        
    }
};