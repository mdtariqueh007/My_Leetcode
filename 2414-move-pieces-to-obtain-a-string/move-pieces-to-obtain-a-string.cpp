class Solution {
public:
    bool canChange(string start, string target) {

        queue<pair<char, int>> startQ, targetQ;

        for(int i = 0;i<start.size();i++){
            if(start[i]!='_'){
                startQ.push({start[i], i});
            }

            if(target[i]!='_'){
                targetQ.push({target[i], i});
            }
        }

        if(startQ.size()!=targetQ.size()){
            return false;
        }

        while(!startQ.empty()){
            auto [sChar, sInd] = startQ.front();
            startQ.pop();
            auto [tChar, tInd] = targetQ.front();
            targetQ.pop();

            if(sChar!=tChar || (sChar=='L' && sInd<tInd) || (sChar=='R' && sInd>tInd)){
                return false;
            }
        }

        return true;
        
    }
};