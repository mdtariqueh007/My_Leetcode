class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {

        vector<vector<int>> excavated(n,vector<int>(n,0));

        for(auto it : dig){
            excavated[it[0]][it[1]] = 1;
        }

        int cnt = 0;

        for(auto it : artifacts){
            bool found = true;

            for(int i = it[0];i<=it[2];i++){
                for(int j = it[1];j<=it[3];j++){
                    if(excavated[i][j]==0){
                        found = false;
                        break;
                    }
                }
                if(!found){
                    break;
                }
            }

            if(found){
                cnt++;
            }
        }


        return cnt;
        
    }
};