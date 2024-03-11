class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<int,int> mp;

        int n = order.size();

        int rank = n;

        for(char c : order){
            mp[c] = rank;
            rank--;
        }

        sort(s.begin(),s.end(),[&](char a,char b){
            return mp[a]>mp[b];
        });

        return s;
    }
};