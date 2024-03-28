class Solution {
    private:
    void dfs(int i,int j,vector<vector<int>>&land,int& maxX,int& maxY,int& minX,int& minY){
        maxX = max(maxX,i);
        minX = min(minX,i);
        maxY = max(maxY,j);
        minY = min(minY,j);
        land[i][j] = -1;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        for(int k = 0;k<4;k++){
            int nr = i + dx[k];
            int nc = j + dy[k];

            if(nr<0 || nc<0 || nr>=land.size() || nc>=land[0].size() || land[nr][nc]!=1){
                continue;
            }

            dfs(nr,nc,land,maxX,maxY,minX,minY);
        }

    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> ans;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(land[i][j]==1){
                    int maxX = i,maxY = j;
                    int minX = i,minY = j;

                    dfs(i,j,land,maxX,maxY,minX,minY);

                    ans.push_back({minX,minY,maxX,maxY});

                }
            }
        }

        return ans;
    }
};