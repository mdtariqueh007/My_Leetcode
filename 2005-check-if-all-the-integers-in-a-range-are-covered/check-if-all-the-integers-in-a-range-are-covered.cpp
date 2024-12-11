class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {

        vector<int> line(52,0);

        for(auto r: ranges){
            line[r[0]]++;
            line[r[1]+1]--;
        }

        int cnt = 0;

        for(int i = 1;i<=50;i++){
            cnt += line[i];

            if(cnt<=0 && i>=left && i<=right){
                return false;
            }
        }

        return true;
        
    }
};