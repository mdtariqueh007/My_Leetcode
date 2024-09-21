class Solution {
    private:
    void helper(int curr,int limit,vector<int>&ans){
        if(curr>limit){
            return;
        }

        ans.push_back(curr);

        for(int i = 0;i<=9;i++){
            int nextNum = curr*10 + i;

            helper(nextNum,limit,ans);
        }
    }
public:
    vector<int> lexicalOrder(int n) {

        vector<int> ans;

        for(int i = 1;i<=9;i++){
            helper(i,n,ans);
        }

        return ans;
        
    }
};