class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(players.rbegin(),players.rend());
        sort(trainers.rbegin(),trainers.rend());

        int i = 0;
        int j = 0;

        int cnt = 0;

        while(i<players.size() && j<trainers.size()){
            if(players[i]<=trainers[j]){
                cnt++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return cnt;
    }
};