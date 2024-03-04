class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(),tokens.end());

        int score = 0;

        int n = tokens.size();

        int j = n-1;
        int i = 0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                power -= tokens[i];
                i++;
            }else if(score>=1){
                if(i==j) break;
                score--;
                power += tokens[j];
                j--;
            }else{
                break;
            }
        }

        return score;
        
    }
};