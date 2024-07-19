class Solution {
    private:
    bool f(int ind,vector<int>&arr,vector<int> &vis){
        if(ind>=arr.size() || ind<0) return false;
        vis[ind] = 1;
        if(arr[ind]==0) return true;
        bool left = false, right = false;
        if(ind+arr[ind]<arr.size() && !vis[ind+arr[ind]]) left = f(ind+arr[ind],arr,vis);
        if(ind-arr[ind]>=0 && !vis[ind-arr[ind]]) right = f(ind-arr[ind],arr,vis);

        return left || right;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        return f(start,arr,vis);
    }
};