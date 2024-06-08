class Solution {
public:
    string clearDigits(string s) {

        int n = s.length();

        vector<int> marked(n,0);

        for(int i = 0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                marked[i] = 1;
                for(int j = i-1;j>=0;j--){
                    if(s[j]>='a' && s[j]<='z' && !marked[j]){
                        marked[j] = 1;
                        break;
                    }
                }
            }
        }

        string ans = "";

        for(int i = 0;i<n;i++){
            if(!marked[i]){
                ans += s[i];
            }
        }


        return ans;
        
    }
};