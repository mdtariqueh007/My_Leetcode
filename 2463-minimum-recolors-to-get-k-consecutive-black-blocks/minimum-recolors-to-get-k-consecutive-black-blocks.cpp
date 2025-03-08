class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int cntWhite = 0;

        for(int i = 0;i<k;i++){
            cntWhite += blocks[i]=='W';
        }

        int ans = cntWhite;

        for(int i = k;i<blocks.size();i++){
            int newBlock = blocks[i];
            int oldBlock = blocks[i-k];

            if(oldBlock=='W'){
                cntWhite--;
            }

            if(newBlock=='W'){
                cntWhite++;
            }

            ans = min(ans, cntWhite);
        }

        return ans;
        
    }
};