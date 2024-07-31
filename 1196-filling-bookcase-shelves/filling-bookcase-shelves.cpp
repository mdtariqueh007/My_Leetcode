class Solution {
    private:
    int width;
    int dp[1001][1001];
    int solve(int ind,vector<vector<int>>&books,int remainingWidth,int maxHeight){
        if(ind>=books.size()){
            return maxHeight;
        }

        if(dp[ind][remainingWidth]!=-1){
            return dp[ind][remainingWidth];
        }

        int bookHeight = books[ind][1];
        int bookWidth = books[ind][0];

        int keep = 1e9, skip = 1e9;

        if(remainingWidth>=bookWidth){
            keep = solve(ind + 1,books,remainingWidth - bookWidth, max(maxHeight,bookHeight));
        }

        skip = maxHeight + solve(ind+1, books,width - bookWidth, bookHeight);

        return dp[ind][remainingWidth] = min(keep,skip);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        width = shelfWidth;

        memset(dp,-1,sizeof(dp));

        return solve(0,books,width,0);
    }
};