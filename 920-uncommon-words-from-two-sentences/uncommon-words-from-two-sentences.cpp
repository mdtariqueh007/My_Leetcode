class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string,int> mp;

        stringstream str(s1);

        string temp;

        while(str>>temp){
            mp[temp]++;
        }

        stringstream str1(s2);

        while(str1>>temp){
            mp[temp]++;
        }

        vector<string> ans;

        for(auto it : mp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }

        return ans;

    }
};