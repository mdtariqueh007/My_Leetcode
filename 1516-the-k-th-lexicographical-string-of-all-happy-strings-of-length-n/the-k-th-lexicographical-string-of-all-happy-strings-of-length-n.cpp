class Solution {
    private:
    bool isHappy(string&s){
        int n = s.length();

        if(n==1){
            return true;
        }

        for(int i = 0;i<n-1;i++){
            if(s[i]==s[i+1]){
                return false;
            }
        }

        return true;
    }
    void solve(string curr, int n, vector<string>& happyStrings){
        if(curr.length()==n){
            if(isHappy(curr)){
                happyStrings.push_back(curr);
            }
            return;
        }

        solve(curr+"a", n, happyStrings);
        solve(curr+"b", n, happyStrings);
        solve(curr+"c", n, happyStrings);
    }
public:
    string getHappyString(int n, int k) {

        vector<string> happyStrings;

        solve("", n, happyStrings);

        sort(happyStrings.begin(), happyStrings.end());

        if(k>happyStrings.size()){
            return "";
        }

        return happyStrings[k-1];
        
    }
};