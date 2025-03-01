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
    #define ll long long
    ll fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    n--;
    int base[2][2] = {{1, 1}, {1, 0}};
    ll ans[2][2] = {{1, 0}, {0, 1}};
    while (n)
    {
        if (n & 1)
        {
            ll temp[2][2];
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    temp[i][j] = 0;
                    for (int k = 0; k < 2; k++)
                    {
                        temp[i][j] += ans[i][k] * base[k][j];
                    }
                }
            }

            ans[0][0] = temp[0][0];
            ans[0][1] = temp[0][1];
            ans[1][0] = temp[1][0];
            ans[1][1] = temp[1][1];

            n = n - 1;
        }
        else
        {
            ll temp[2][2];
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    temp[i][j] = 0;
                    for (int k = 0; k < 2; k++)
                    {
                        temp[i][j] += base[i][k] * base[k][j];
                    }
                }
            }

            base[0][0] = temp[0][0];
            base[0][1] = temp[0][1];
            base[1][0] = temp[1][0];
            base[1][1] = temp[1][1];

            n = n / 2;
        }
    }

    return ans[0][0];
}
public:
    int climbStairs(int n) {
        // memset(memo, -1 , sizeof(memo));
        return fibo(n+1);
    }
};