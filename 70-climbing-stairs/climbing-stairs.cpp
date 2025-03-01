class Solution {
    private:
    int memo[46];
    int solve(int curr, int n){
        if(curr>n){
            return 0;
        }

        if(curr==n){
            return 1;
        }

        if(memo[curr]!=-1){
            return memo[curr];
        }

        int oneStep = solve(curr+1, n);
        int twoSteps = solve(curr+2, n);

        return memo[curr] = oneStep + twoSteps;
    }
public:
    int climbStairs(int n) {
        memset(memo, -1 , sizeof(memo));
        return solve(0, n);
    }
};