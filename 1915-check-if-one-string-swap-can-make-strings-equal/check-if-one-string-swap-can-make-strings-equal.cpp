class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int firstInd = 0, secondInd = 0;

        int diff = 0;

        for(int i = 0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                diff++;
            

            if(diff>2){
                
                return false;
            }
            else if(diff==1){
                firstInd = i;
            }
            else{
                secondInd = i;
            }
            }
        }

        return (s1[firstInd]==s2[secondInd] && s1[secondInd]==s2[firstInd]);

    }
};