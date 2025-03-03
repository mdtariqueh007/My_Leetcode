class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> ans, equal, greater;

        for(int x: nums){
            if(x<pivot){
                ans.push_back(x);
            }
            else if(x==pivot){
                equal.push_back(x);
            }
            else{
                greater.push_back(x);
            }
        }

        ans.insert(ans.end(), equal.begin(), equal.end());
        ans.insert(ans.end(), greater.begin(), greater.end());

        return ans;
        
    }
};