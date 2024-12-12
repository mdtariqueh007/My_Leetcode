class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        vector<int> prefix;

        prefix.push_back(0);

        

        for(int i = 0;i<s.length();i++){
            int ind = s[i] - 'a';

            prefix.push_back(prefix.back() ^ (1<<ind));
        }

        vector<bool> ans;

        for(auto q: queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];

            

            int num = prefix[r+1]^prefix[l];

            int cntOdd = 0;

            for(int i = 0;i<32;i++){
                if(num & (1<<i)){
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