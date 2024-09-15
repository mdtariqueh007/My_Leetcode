class Solution {
public:
    int findTheLongestSubstring(string s) {

        int ans = 0;

        unordered_map<string,int> mp;

        string initialState = "00000";
        vector<int> state(5,0);

        mp[initialState] = -1;

        for(int i = 0;i<s.length();i++){
            char c = s[i];
            if(c=='a'){
                state[0] ^= 1;
            }
            else if(c=='e'){
                state[1] ^= 1;
            }
            else if(c=='i'){
                state[2] ^= 1;
            }
            else if(c=='o'){
                state[3] ^= 1;
            }
            else if(c=='u'){
                state[4] ^= 1;
            }

            string currState = "";

            for(int j = 0;j<5;j++){
                currState += to_string(state[j]);
            }

            if(mp.find(currState)!=mp.end()){
                ans = max(ans, i - mp[currState]);
            }
            else{
                mp[currState] = i;
            }

        }

        return ans;
        
    }
};