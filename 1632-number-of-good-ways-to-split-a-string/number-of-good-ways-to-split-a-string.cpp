class Solution {
public:
    int numSplits(string s) {
        int n = s.length();

        vector<int> prefix(n,0);
        vector<int> suffix(n,0);

        vector<bool> vis(26,false);

        for(int i = 0;i<n;i++){
            if(vis[s[i]-'a']==false){
                prefix[i] = (i==0)?0:prefix[i-1] + 1;
                vis[s[i]-'a'] = true;
            }
            else{
                prefix[i] = prefix[i-1];
            }
        }

        for(int i = 0;i<26;i++){
            vis[i] = false;
        }

        for(int i = n-1;i>=0;i--){
            if(vis[s[i]-'a']==false){
                suffix[i] = (i==n-1)?0:suffix[i+1]+1;
                vis[s[i]-'a'] = true;
            }else{
                suffix[i] = suffix[i+1];
            }
        }

        // for(int i : prefix){
        //     cout<<i<<" ";
        // }

        // cout<<"\n";

        // for(int i : suffix){
        //     cout<<i<<" ";
        // }

        // cout<<"\n";

        int ans = 0;

        for(int i = 0;i<n-1;i++){
            if(prefix[i]==suffix[i+1]){
                ans++;
            }
        }

        return ans;

        
    }
};