class Solution {
    private:
    bool isPoss(vector<int>&buses,vector<int>&passengers,int capacity,int mid){
        int b = buses.size();
        int p = passengers.size();

        int j = 0;

        for(int i = 0;i<b;i++){
            int curr = 0;
            while(j<p && passengers[j]<mid && passengers[j]<=buses[i] && curr<capacity){
                j++;
                curr++;
            }

            if(curr==capacity){
                continue;
            }

            if(mid<=buses[i]){
                return true;
            }
        }

        return false;
    }
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int b = buses.size();
        int p = passengers.size();

        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());

        int ans = 0;

        int low = 1;
        int high = 1e9+1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isPoss(buses,passengers,capacity,mid)){
                ans = mid; 
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        unordered_set<int> st(passengers.begin(),passengers.end());

        cout<<ans<<"\n";

        while(st.find(ans)!=st.end()){
            ans--;
        }

        return ans;

    }
};