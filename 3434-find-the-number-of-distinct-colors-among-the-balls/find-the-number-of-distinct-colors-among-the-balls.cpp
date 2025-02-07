class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        vector<int> ans;

//         vector<int> balls(limit+1,0);

//         unordered_map<int,int> mp;

//         for(auto q:  queries){
//             int x = q[0];
//             int y = q[1];

//             if(balls[x]==0){
//                 balls[x] = y;
//                 mp[y]++;
//             }else{
//                 mp[balls[x]]--;
//                 if(mp[balls[x]]==0){
//                     mp.erase(balls[x]);
//                 }
//                 balls[x] = y;
//                 mp[y]++;
//             }

//             ans.push_back(mp.size());

            
//         }

//         return ans;
        
       unordered_map<int,int> ball;
        unordered_map<int,int> col;
        
        int dis = 0;
        
        for(auto q : queries){
            int x = q[0];
            int y = q[1];
            
            if(ball[x]){
                int old = ball[x];
                if(old!=y){
                    col[old]--;
                    
                    if(col[old]==0){
                        dis--;
                    }
                    
                    col[y]++;
                    
                    if(col[y]==1){
                        dis++;
                    }
                    
                    ball[x] = y;
                }}else{
                    
                    
                    ball[x] = y;
                    
                    col[y]++;
                    
                    
                    if(col[y]==1){
                        dis++;
                    }
                    
                    
                    
                    
                    
                    
                    
                }
                
                ans.push_back(dis);
            }
        return ans;
        
    }
};