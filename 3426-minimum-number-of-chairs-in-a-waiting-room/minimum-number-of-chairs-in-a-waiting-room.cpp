class Solution {
public:
    int minimumChairs(string s) {
        int maxChair = 0;

        int chair = 0;

        for(char c : s){
            if(c=='E'){
                chair++;
            }
            else{
                chair--;
            }

            maxChair = max(maxChair,chair);
        }

        return maxChair;
    }
};