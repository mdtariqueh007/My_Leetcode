class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();


        for(int i = 0;i<k-1;i++){
            colors.push_back(colors[i]);
        }

        int cnt = 1;
        int res = 0;

        for(int i = 1;i<colors.size();i++){
            if(colors[i]!=colors[i-1]){
                cnt++;
            }
            else{
                cnt = 1;
            }

            if(cnt>=k){
                res++;
            }
        }

        return res;
    }
};