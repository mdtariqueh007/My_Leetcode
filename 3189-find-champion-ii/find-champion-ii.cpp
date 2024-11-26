class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n,0);
        
        for(auto it : edges){
            indegree[it[1]]++;
        }
        
        int cnt = 0;
        int ans = -1;
        
        for(int i = 0;i<n;i++){
            if(indegree[i]==0){
                cnt++;
                if(cnt==1){
                    ans = i;
                }
                else if(cnt>1){
                    return -1;
                }
            }
        }
        
        return ans;
        
    }
};