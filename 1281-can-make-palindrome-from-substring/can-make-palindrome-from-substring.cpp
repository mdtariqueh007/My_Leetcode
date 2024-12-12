class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        vector<vector<int>> prefix;

        vector<int> cnt(26,0);

        for(int i = 0;i<s.length();i++){
            cnt[s[i]-'a']++;
            prefix.push_back(cnt);
        }

        vector<bool> ans;

        for(auto q: queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];

            vector<int> diff;

            if(l==0){
                diff = prefix[r];
            }
            else{
                for(int i = 0;i<26;i++){
                    diff.push_back(prefix[r][i]-prefix[l-1][i]);
                }
            }

            int cntOdd = 0;

            for(int i = 0;i<26;i++){
                if(diff[i]&1){
                    cntOdd++;
                }
            }

            if(cntOdd/2<=k){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        

        return ans;
    }
};