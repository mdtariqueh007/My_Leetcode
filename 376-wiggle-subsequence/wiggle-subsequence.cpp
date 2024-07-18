class Solution {
    private:
    
    map<string,int> mp;
    int solve(int ind,int prev,int curr,vector<int>&arr){ //curr==0 '>' else '<''
        if(ind>=arr.size()){
            return 0;
        }
        
        string temp = to_string(ind) + "#" + to_string(prev) + "#" + to_string(curr);
        
        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        
        int take = 0, notTake = 0;
        
        notTake = solve(ind+1,prev,curr,arr);
        
        if(curr==0){
            if(arr[ind]>prev){
                take = 1 + solve(ind+1,arr[ind],1,arr);
            }
            // else{
            //     take = solve(ind+1,prev,curr,arr);
            // }
        }
        else{
            if(arr[ind]<prev){
                take = 1 + solve(ind+1,arr[ind],0,arr);
            }
            // else{
            //     take = solve(ind+1,prev,curr,arr);
            // }
        }
        
        return mp[temp] = max(take,notTake);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        mp.clear();
        
        
        return max(solve(0,-1,0,nums),solve(0,1e9,1,nums));
    }
};