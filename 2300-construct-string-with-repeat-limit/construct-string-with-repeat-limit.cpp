class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        vector<int> cnt(26,0);

        for(char c: s){
            cnt[c-'a']++;
        }

        string ans;

        int currCharInd = 25;

        while(currCharInd>=0){
            if(cnt[currCharInd]==0){
                currCharInd--;
                continue;
            }

            int cntToUse = min(cnt[currCharInd], repeatLimit);

            ans.append(cntToUse, currCharInd + 'a');

            cnt[currCharInd] -= cntToUse;

            if(cnt[currCharInd]>0){
                int nextSmallerChar = currCharInd - 1;

                while(nextSmallerChar>=0 && cnt[nextSmallerChar]==0){
                    nextSmallerChar--;
                }

                if(nextSmallerChar<0){
                    break;
                }

                ans.push_back(nextSmallerChar + 'a');
                cnt[nextSmallerChar]--;
            }
        }

        return ans;

        

    }
};