class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = blocks.size();

        int cntWhite = 0;

        int ans = 0;

        for(int i = 0;i<k;i++){
            if(blocks[i]=='W'){
                cntWhite++;
            }
        }

        ans = cntWhite;

        for(int i = k;i<n;i++){
            if(blocks[i]=='W' && blocks[i-k]=='W') continue;
            if(blocks[i]=='W' && blocks[i-k]=='B') cntWhite++;
            else if(blocks[i]=='B' && blocks[i-k]=='W') cntWhite--;

            ans = min(ans,cntWhite);

        }

        return ans;


        
    }
};