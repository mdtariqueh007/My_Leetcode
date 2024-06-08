class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {

        int n = skills.size();


        if(k>=n){
            int ind = max_element(skills.begin(),skills.end()) - skills.begin();

            return ind;
        }

        deque<int> dq;

        for(int i = 0;i<n;i++){
            dq.push_back(i);
        }

        int winner = dq.front();

        dq.pop_front();

        int consWins = 0;

        while(consWins<k){
            int challenger = dq.front();
            dq.pop_front();

            if(skills[winner]>skills[challenger]){
                consWins++;
                dq.push_back(challenger);

            }else{
                dq.push_back(winner);
                winner = challenger;
                consWins = 1;
            }
        }

        return winner;

        
        
    }
};