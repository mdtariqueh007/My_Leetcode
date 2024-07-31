class Solution {
    private:
    bool isSpecial(string&s,int i, int j){
        while(i<j){
            if(s[i]!=s[i+1]){
                return false;
            }
            i++;
        }

        return true;
    }
public:
    int maximumLength(string s) {
        
       unordered_map<string,int> mp;
       int n = s.length();

       for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if(isSpecial(s,i,j)){
                mp[s.substr(i,j-i+1)]++;
            }
        }
       }

       int ans = 0;

       for(auto it : mp){
        if(it.second>=3 && it.first.length()>ans){
            ans = it.first.length();
        }
       }

       return ans==0?-1:ans;

        
    }
};