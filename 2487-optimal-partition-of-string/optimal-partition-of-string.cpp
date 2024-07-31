class Solution {
public:
    int partitionString(string s) {


        int ans = 0;
        int n = s.length();

        int flag = 0;

        for(int i = 0;i<n;i++){
            int val = s[i] - 'a';
            if((flag&(1<<val))){
                flag = 0;
                ans++;
            }

            flag = flag | (1<<val);
        }

        return ans+1;


    }
};