class Solution {
public:
    int findTheLongestSubstring(string s) {

        int ans = 0;

        unordered_map<int,int> mp;

        int mask = 0;

        mp[mask] = -1;

        for(int i = 0;i<s.length();i++){
            char c = s[i];
            if(c=='a'){
                mask = (mask ^ (1<<0));
            }
            else if(c=='e'){
                mask = (mask ^ (1<<1));
            }
            else if(c=='i'){
                mask = (mask ^ (1<<2));
            }
            else if(c=='o'){
                mask = (mask ^ (1<<3));
            }
            else if(c=='u'){
                mask = (mask ^ (1<<4));
            }

            
            if(mp.find(mask)!=mp.end()){
                ans = max(ans, i - mp[mask]);
            }
            else{
                mp[mask] = i;
            }

        }

        return ans;
        
    }
};