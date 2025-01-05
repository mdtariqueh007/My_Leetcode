class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.length();

        vector<int> line(n+1, 0);

        for(auto it: shifts){
            int start = it[0];
            int end = it[1];
            int dir = it[2];

            if(dir==1){
                line[start]++;
                line[end+1]--;
            }
            else{
                line[start]--;
                line[end+1]++;
            }

        }

        for(int i = 1;i<n;i++){
            line[i] += line[i-1];
        }

        for(int i = 0;i<n;i++){
            int increment = (s[i] - 'a' + line[i])%26;

            increment = (increment + 26)%26;

            s[i] = 'a' + increment;
        }

        return s;
        
    }
};