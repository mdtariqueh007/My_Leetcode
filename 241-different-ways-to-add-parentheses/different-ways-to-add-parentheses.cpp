class Solution {
    private:
    
    vector<int> solve(string& expression, vector<vector<vector<int>>>&dp, int start, int end){

        if(!dp[start][end].empty()){
            return dp[start][end];
        }

        vector<int> res;

        if(start==end){
            res.push_back(expression[start] - '0');
            return res;
        }

        if(end-start==1 && isdigit(expression[start])){
            int tens = expression[start] - '0';
            int ones = expression[end] - '0';

            res.push_back(tens*10 + ones);
            return res;
        }

        for(int i = start;i<=end;i++){
            char curr = expression[i];

            if(isdigit(curr)){
                continue;
            }

            vector<int> leftRes = solve(expression, dp, start, i - 1);
            vector<int> rightRes = solve(expression, dp, i+1, end);

            for(int lVal: leftRes){
                for(int rVal: rightRes){
                    int ans = 0;

                    if(curr=='+'){
                        ans = lVal + rVal;
                    }
                    else if(curr=='-'){
                        ans = lVal - rVal;
                    }
                    else if(curr=='*'){
                        ans = lVal * rVal;
                    }

                    res.push_back(ans);
                }
            }
        }

        return dp[start][end] = res;
    }
public:
    vector<int> diffWaysToCompute(string expression) {

        int n = expression.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

        return solve(expression, dp, 0, expression.size() - 1);

        
        
    }
};