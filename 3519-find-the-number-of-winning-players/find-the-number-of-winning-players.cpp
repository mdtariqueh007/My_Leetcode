class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {

        map<int,map<int,int>> mp;

        for(auto it : pick){
            int x = it[0];
            int y = it[1];

            mp[x][y]++;
        }

        int cnt = 0;

        for(auto it : mp){
            bool flag = false;
            for(auto p : it.second){
                if(p.second>it.first){
                    flag = true;
                }
            }

            if(flag){
                cnt++;
            }
        }

        return cnt;
        
    }
};