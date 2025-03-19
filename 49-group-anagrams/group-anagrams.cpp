class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;

        for(string &s: strs){
            vector<int> cnt(26, 0);

            for(char c: s){
                cnt[c - 'a']++;
            }

            string key = "";

            for(int i = 0;i<26;i++){
                key += "#";
                key += to_string(cnt[i]);
            }

            mp[key].push_back(s);
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;


        
    }
};