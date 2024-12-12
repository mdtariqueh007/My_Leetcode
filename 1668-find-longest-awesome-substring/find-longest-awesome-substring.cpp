class Solution {
public:
    int longestAwesome(string s) {

        unordered_map<int,int> mp;

        mp[0] = -1;

        int ans = 0;
        int mask = 0;

        for(int i = 0;i<s.length();i++){
            int digit = s[i] - '0';

            mask = mask^(1<<digit);

            if(mp.find(mask)==mp.end()){
                mp[mask] = i;
            }
            else{
                ans = max(ans, i - mp[mask]);
            }

            if(mask==0 || (mask&(mask-1))==0){
                ans = max(ans, i + 1);
            }

            for(int pos = 0;pos<10;pos++){
                int newMask = mask^(1<<pos);

                if(mp.find(newMask)!=mp.end()){
                    ans = max(ans, i - mp[newMask]);
                }
            }
        }

        return ans;

        
    }
};