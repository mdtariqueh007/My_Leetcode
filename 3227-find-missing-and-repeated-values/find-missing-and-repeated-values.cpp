class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        long long n = grid.size();

        long long sum = 0, squareSum = 0;
        long long val = n * n;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                sum += grid[i][j] * 1LL;
                squareSum += (grid[i][j] * grid[i][j] * 1LL);
            }
        }

        long long totalSum = (val * (val + 1))/2;
        long long totalSquareSum = (val * (val + 1) *(2 * val + 1))/6;

        long long sumDiff = sum - totalSum; // x - y
        long long squareSumDiff = squareSum - totalSquareSum; // x2 - y2

        int repeatVal = (squareSumDiff/sumDiff + sumDiff)/2;
        int missingVal = repeatVal - sumDiff;

        return {repeatVal, missingVal};


        
    }
};