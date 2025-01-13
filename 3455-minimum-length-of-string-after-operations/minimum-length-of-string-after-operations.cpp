class Solution {
public:
    int minimumLength(string s) {

        vector<int> freq(26,0);

        for(char c : s){
            freq[c-'a']++;
        }

        for(int i = 0;i<26;i++){
            if(freq[i]>=3){
                if(freq[i]%2==0){
                    freq[i] = 2;
                }
                else{
                    freq[i] = 1;
                }
            }
            
        }

        int ans = 0;

        for(int i = 0;i<26;i++){
            ans += freq[i];
        }

        return ans;
        
    }
};