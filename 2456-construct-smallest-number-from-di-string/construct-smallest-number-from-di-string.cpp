class Solution {
    private:
    void solve(string&pattern, int ind, int currNum, string currString, string&ans, vector<bool>&used){
        if(ind==pattern.length()){
            ans = min(ans, currString);
            return;
        }

        if(pattern[ind]=='I'){
            for(int i = currNum+1;i<=9;i++){
                if(used[i]) continue;
                used[i] = true;
                solve(pattern, ind+1, i,currString+to_string(i),ans, used);
                used[i] = false;
            }
        }
        else{
            for(int i = currNum-1;i>=1;i--){
                if(used[i]) continue;
                used[i] = true;
                solve(pattern, ind+1, i,currString+to_string(i),ans, used);
                used[i] = false;
            }
        }







    }
public:
    string smallestNumber(string pattern) {

        string ans = "99999999999999";

        vector<bool> used(10, false);

        string temp = "";

        for(int i = 1;i<=9;i++){
            used[i] = true;
            
            solve(pattern,0,i,temp + to_string(i),ans,used);
            used[i] = false;
        }

        return ans;
        
    }
};