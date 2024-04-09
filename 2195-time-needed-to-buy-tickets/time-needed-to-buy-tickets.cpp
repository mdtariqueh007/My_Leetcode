class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int time = tickets[k];

        for(int i = 0;i<tickets.size();i++){
            if(i==k) continue;
            if(i<k)
                time += min(tickets[i],tickets[k]);
            else
                time += min(tickets[i],tickets[k]-1);
        }

        return time;
        
    }
};