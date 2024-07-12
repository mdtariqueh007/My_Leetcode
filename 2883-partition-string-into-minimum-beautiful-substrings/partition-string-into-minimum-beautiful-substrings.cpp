class Solution {
    private:
    bool isValid(string&s,int i,int j){
        if(s[i]=='0'){
            return false;
        }

        int num = 0;

        for(int ind = i;ind<=j;ind++){
            if(s[ind]=='1'){
                num = num * 2 + 1;
            }
            else{
                num = num * 2;
            }
        }

        while(num>1){
            if(num%5==0){
                num = num/5;
            }
            else{
                return false;
            }
        }

        return true;
    }
    int solve(int ind,string&s){
        if(ind>=s.size()){
            return 0;
        }

        int mini = 1e9;

        for(int i = ind;i<s.size();i++){
            if(isValid(s,ind,i)){
                int curr = 1 + solve(i + 1,s);

                mini = min(mini,curr);
            }
        }

        return mini;
    }
public:
    int minimumBeautifulSubstrings(string s) {
        int ans = solve(0,s);

        if(ans==1e9){
            return -1;
        }

        return ans;
    }
};