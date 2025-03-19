class Solution {
public:
    string reorganizeString(string s) {

        vector<int> freq(26, 0);

        for(char c: s){
            freq[c - 'a']++;
        }

        int maxi = 0;
        char mostFreqChar;

        for(int i = 0;i<26;i++){
            if(freq[i]>maxi){
                maxi = freq[i];
                mostFreqChar = i + 'a';
            }
        }

        int gaps = maxi - 1;

        int otherCharCnt = s.size() - maxi;

        if(otherCharCnt<gaps){
            return "";
        }

        int i = 0;

        while(freq[mostFreqChar - 'a']>0){
            s[i] = mostFreqChar;
            i += 2;
            freq[mostFreqChar - 'a']--;
        }

        

        for(int j = 0;j<26;j++){
            while(freq[j]>0){
                if(i>=s.size()){
                    i = 1;
                }
                s[i] = (j + 'a');
                i += 2;
                freq[j]--;
            }
        }

        return s;
        
    }
};