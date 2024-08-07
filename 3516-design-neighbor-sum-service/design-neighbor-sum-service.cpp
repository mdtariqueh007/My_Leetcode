class neighborSum {
    private:
    vector<vector<int>> mat;
    map<int,pair<int,int>> mp;
public:
    neighborSum(vector<vector<int>>& grid) {
        mat = grid;
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                mp[mat[i][j]] = {i,j};
            }
        }
    }
    
    int adjacentSum(int value) {

        int r = mp[value].first;
        int c = mp[value].second;

        int sum = 0;

        if(r-1>=0){
            sum += mat[r-1][c];
        }
        if(r+1<mat.size()){
            sum += mat[r+1][c];
        }
        if(c-1>=0){
            sum += mat[r][c-1];
        }
        if(c+1<mat[0].size()){
            sum += mat[r][c+1];
        }


        return sum;
        
    }
    
    int diagonalSum(int value) {

        int r = mp[value].first;
        int c = mp[value].second;

        int sum = 0;

        if(r-1>=0 && c-1>=0){
            sum += mat[r-1][c-1];
        }
        if(r+1<mat.size() && c+1<mat[0].size()){
            sum += mat[r+1][c+1];
        }
        if(r-1>=0 && c+1<mat[0].size()){
            sum += mat[r-1][c+1];
        }
        if(r+1<mat.size() && c-1>=0){
            sum += mat[r+1][c-1];
        }

        return sum;
        
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */