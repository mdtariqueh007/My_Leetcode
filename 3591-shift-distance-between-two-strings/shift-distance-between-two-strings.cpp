class Solution {
    
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;

        int n = s.length();

        vector<vector<long long>> mat(26, vector<long long>(26, 1e18));

        for(int i = 0;i<26;i++){
            mat[i][i] = 0;
        }

        for(int i = 0;i<26;i++){
            int u = i;
            int v = (i+1)%26;

            mat[u][v] = nextCost[u];
            mat[v][u] = previousCost[v];
        }

        for(int k = 0;k<26;k++){
            for(int i = 0;i<26;i++){
                for(int j = 0;j<26;j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        
        for(int i = 0;i<n;i++){
            int src = s[i] - 'a';
            int tar = t[i] - 'a';

            ans += mat[src][tar];
        }

        return ans;



    }
};