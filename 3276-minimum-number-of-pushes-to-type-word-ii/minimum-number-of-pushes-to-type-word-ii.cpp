class Solution {
public:
    int minimumPushes(string word) {

        vector<int> freq(26,0);

        for(char c: word){
            freq[c-'a']++;
        }

        sort(freq.rbegin(),freq.rend());

        int res = 0;
        int cnt = 0;

        int press = 1;

        for(int i = 0;i<26;i++){
            if(freq[i]!=0){
                cnt++;
                if(cnt>8){
                    cnt = 1;
                    press++;
                }

                res += (freq[i]*press);
            }
        }

        return res;
        
    }
};