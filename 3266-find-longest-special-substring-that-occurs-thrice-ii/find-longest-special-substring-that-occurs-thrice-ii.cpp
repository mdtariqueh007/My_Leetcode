class Solution {
    private:
    bool isPossible(map<char,vector<int>>&mp,int mid){
        for(auto it : mp){
            int cnt = 0;

            for(auto val : it.second){
                if(val>=mid){
                    cnt += (val - mid + 1);
                }
                if(cnt>=3){
                    return true;
                }
            }
        }

        return false;

    }
public:
    int maximumLength(string s) {
        
        map<char,vector<int>> mp;

        int lastChar = s[0];

        int cnt = 1;

        int n = s.length();

        for(int i = 1;i<n;i++){
            if(s[i]==lastChar){
                cnt++;
            }
            else{
                mp[lastChar].push_back(cnt);
                lastChar = s[i];
                cnt = 1;
            }
        }
        mp[lastChar].push_back(cnt);

        int ans = -1;

        int low = 1;
        int high = n - 2;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isPossible(mp,mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;


    }
};