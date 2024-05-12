class Solution {
    private:
    bool check(int x,int y,vector<vector<char>>&grid){
        int cnt1 = 0,cnt2 = 0;
        for(int i = x;i<x+2;i++){
            for(int j=y;j<y+2;j++){
                if(grid[i][j]=='B'){
                    cnt1++;
                }else{
                    cnt2++;
                }
            }
        }

        if(cnt1<=1 || cnt2<=1){
            return true;
        }

        return false;
    }
public:
    bool canMakeSquare(vector<vector<char>>& grid) {

        for(int i = 0;i<2;i++){
            for(int j = 0;j<2;j++){
                if(check(i,j,grid)){
                    return true;
                }
            }
        }

        return false;
        
    }
};