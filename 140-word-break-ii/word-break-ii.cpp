class Solution {
    private:
    void f(int ind,string&s,string sentence,unordered_map<string,int>&mp,vector<string>&ans){
        if(ind>=s.size()){
            // if(sentence.back()==' '){
                sentence.pop_back();
            // }

            ans.push_back(sentence);
            return;
        }

        string curr = "";

        for(int i = ind;i<s.size();i++){
            curr.push_back(s[i]);
            if(mp.find(curr)!=mp.end()){
                f(i+1,s,sentence+curr+' ',mp,ans);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto it : wordDict){
            mp[it]++;
        }

        vector<string> ans;
        f(0,s,"",mp,ans);

        return ans;
    }
};