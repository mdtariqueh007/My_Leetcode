class Solution {
    private:
    void solve(int row, vector<string>&board, vector<vector<string>>&ans, vector<bool>&col, vector<bool>&diag1, vector<bool>&diag2, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int c = 0;c<n;c++){
            if(col[c] || diag1[row+c] || diag2[row-c+n-1]){
                continue;
            }

            board[row][c] = 'Q';

            col[c] = true;
            diag1[row+c] = true;
            diag2[row-c+n-1] = true;

            solve(row+1, board, ans, col, diag1, diag2, n);

            board[row][c] = '.';

            col[c] = false;
            diag1[row+c] = false;
            diag2[row-c+n-1] = false;


        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n);
        string s(n, '.');

        for(int i = 0;i<n;i++){
            board[i] = s;
        }

        vector<vector<string>> ans;

        vector<bool> col(n, false), diag1(2*n-1, false), diag2(2*n-1, false);

        solve(0, board, ans, col, diag1, diag2, n);

        return ans;
        
    }
};