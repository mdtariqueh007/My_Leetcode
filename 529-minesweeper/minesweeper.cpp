class Solution {
public:
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    int countMines(vector<vector<char>>&board,int x,int y){
        int c = 0;

        for(int i = 0;i<8;i++){
            int nx = x + dx[i];
            int nc = y + dy[i];
            
            if(nx<0 || nc<0 || nx>=board.size() || nc>= board[0].size() || board[nx][nc]!='M'){
                continue;
            }
            c++;
        }

        return c;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];

        if(board[x][y]!='E' && board[x][y]!='M'){
                return board;
        }

        if(board[x][y]=='M'){
                board[x][y] = 'X';

                return board;
        }

        int mines = countMines(board,x,y);
        if(mines!=0){
                board[x][y] = char(mines + '0');
                return board;
        }

        board[x][y] = 'B';

        queue<pair<int,int>> q;
        q.push({x,y});

        int n = board.size();
        int m = board[0].size();

     

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0;i<8;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow<0 || ncol<0 || nrow>=n || ncol>=m || board[nrow][ncol]!='E'){
                    continue;
                }

                mines = countMines(board,nrow,ncol);

                if(mines!=0){
                    board[nrow][ncol] = char(mines + '0');
                    continue;
                }

                board[nrow][ncol] = 'B';
                q.push({nrow,ncol});
            }


        }   

        return board;
       

    }
};