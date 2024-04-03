class Solution {
public:


    bool findMatch(vector<vector<char>>&board,string word,int r,int c,int step){
        int rows = board.size();
        int cols = board[0].size();

        int l = word.length();

        if(step==l)
            return true;

        if(r<0 || c<0 || r>=rows || c>=cols)
            return false;
        if(board[r][c]==word[step]){
            char temp = board[r][c];
            board[r][c] = '$';
            int dx[4] = {-1,1,0,0};
            int dy[4] = {0,0,-1,1};
                bool res = false; ;
            for(int i = 0;i<4;i++){

                res = res || findMatch(board,word,r+dx[i],c+dy[i],step+1);
            }

            board[r][c] = temp;
            return res;
        }
        else{
            return false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {

        int l = word.length();
        int rows = board.size();
        int cols = board[0].size();

        if(l>(rows*cols))
            return false;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(board[i][j]==word[0])
                    if(findMatch(board,word,i,j,0))
                        return true;
            }
        }

        return false;
        
    }
};