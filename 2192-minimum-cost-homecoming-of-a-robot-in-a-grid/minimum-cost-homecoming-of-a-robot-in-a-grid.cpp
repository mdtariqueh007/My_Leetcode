class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int rows = homePos[0] - startPos[0];
        int cols = homePos[1] - startPos[1];

        // int r = rowCosts.size();
        // int c = colCosts.size();

        // int rowToTraverse = (r - rows) + startPos[0];
        // int colToTraverse = (c - cols) + startPos[];

        int rowSign = rows>=0?1:-1;
        int colSign = cols>=0?1:-1;

        rows = abs(rows);
        cols = abs(cols);

        int cost = 0;

        int i = startPos[0] + rowSign;
        while(rows--){
            cost += rowCosts[i];
            i = i + rowSign;
        }

        i = startPos[1] + colSign;
        while(cols--){
            cost += colCosts[i];
            i = i + colSign;
        }

        return cost;
    }
};