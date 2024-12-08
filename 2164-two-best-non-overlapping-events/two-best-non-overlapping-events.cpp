class Solution {
    private:
    int dp[100001][3];
    int binarySearch(int ind, int target, vector<vector<int>>&events){
        int low = ind + 1;
        int high = events.size() - 1;

        int ans = high + 1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(events[mid][0]>target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
    int solve(int ind, int cnt, vector<vector<int>>&events){
        if(cnt==2){
            return 0;
        }

        if(ind>=events.size()){
            return 0;
        }

        if(dp[ind][cnt]!=-1){
            return dp[ind][cnt];
        }

        int endTime = events[ind][1];

        int nextEventInd = binarySearch(ind,endTime, events);

        int take = events[ind][2] + solve(nextEventInd, cnt+1, events);

        int notTake = solve(ind+1, cnt, events);

        return dp[ind][cnt] = max(take, notTake);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        memset(dp, -1, sizeof(dp));

        sort(events.begin(),events.end());

        return solve(0,0,events);

    }
};