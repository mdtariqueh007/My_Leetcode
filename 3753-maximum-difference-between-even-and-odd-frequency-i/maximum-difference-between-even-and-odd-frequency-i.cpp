class Solution {
public:
    int maxDifference(string s) {

        vector<int> count(26,0);

        for(char c: s){
            count[c-'a']++;
        }

        int maxOdd = 0;
        int minEven = 1e9;

        for(int i = 0;i<26;i++){
            if(count[i]==0) continue;
            
            if(count[i]&1){
                maxOdd = max(maxOdd, count[i]);
            }
            else{
                minEven = min(minEven, count[i]);
            }
        }

        return maxOdd - minEven;
        
    }
};