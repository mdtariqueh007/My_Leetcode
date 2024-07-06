class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {

        int n = colors.size();

        int prev = colors[n - 1];
        int next = colors[1];
        int curr = colors[0];

        int i = 0;

        int cnt = 0;

        while(i<n){
            if(prev!=curr && curr!=next){
                cnt++;
            }

            prev = curr;
            curr = next;
            next = colors[(i+2)%n];
            i++;
        }

        return cnt;

        
        
    }
};