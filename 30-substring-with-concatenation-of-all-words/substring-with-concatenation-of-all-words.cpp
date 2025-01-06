class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int n = s.length();

        vector<int> ans;

        int subStrSize = words[0].size() * words.size();

        unordered_map<string, int> dictionary;
        for(string s: words){
            dictionary[s]++;
        }

        for(int i = 0;i<=n-subStrSize;i++){
            string sub = s.substr(i, subStrSize);

            unordered_map<string,int> mp;

            int cnt = 0;
            
            for(int j = 0;j<sub.size();j+=words[0].size()){
                string subSub = sub.substr(j, words[0].size());

                mp[subSub]++;
            }

            if(mp==dictionary){
                ans.push_back(i);
            }
        }

        return ans;

        
        
    }
};