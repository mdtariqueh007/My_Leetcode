class Solution {
    private:
    bool check(string a,string b){
        vector<bool> cnt(26,false);

        for(int i = 0;i<a.size();i++){
            cnt[a[i]-'a'] = true;
        }
        for(int i = 0;i<b.size();i++){
            cnt[b[i]-'a'] = false;
        }

        for(int i = 0;i<26;i++){
            if(cnt[i]==true){
                return false;
            }
        }

        return true;
    }
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        int cnt = 0;

        for(string s : words){
            if(check(s,allowed)){
                cnt++;
            }
        }

        return cnt;
        
    }
};