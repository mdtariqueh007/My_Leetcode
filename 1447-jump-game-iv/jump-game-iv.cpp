class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        vector<bool> vis(n, false);

        queue<int> q;

        q.push(0);

        vis[0] = true;

        int steps = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0;i<sz;i++){
                int currInd = q.front();
                q.pop();

                if(currInd==n-1){
                    return steps;
                }

                if(currInd+1<n && !vis[currInd+1]){
                    vis[currInd+1] = true;
                    q.push(currInd+1);
                }
                if(currInd-1>=0 && !vis[currInd-1]){
                    vis[currInd-1] = true;
                    q.push(currInd-1);
                }

                for(int newInd: mp[arr[currInd]]){
                    if(!vis[newInd]){
                        vis[newInd] = true;
                        q.push(newInd);
                    }
                }

                mp[arr[currInd]].clear();

                
            }
            steps++;
        }

        return -1;


        
    }
};