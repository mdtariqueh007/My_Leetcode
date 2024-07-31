class Solution {
public:
    int partitionString(string s) {

        int n = s.length();

        vector<int> lastPos(26,-1);

        int ans = 0;

        int last = -1;

        for(int i = 0;i<n;i++){
            if(lastPos[s[i]-'a']>=last){
                ans++;
                last = i;
            }

            lastPos[s[i]-'a'] = i;
        }

        return ans;
        
    }
};