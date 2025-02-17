class Solution {
    private:
    void solve(vector<int>&cnt, string current, unordered_set<string>&sequences){
        
        sequences.insert(current);

        for(int i = 0;i<26;i++){
            if(cnt[i]>0){
                cnt[i]--;
                current.push_back(i+'A');
                solve(cnt,current,sequences);
                cnt[i]++;
                current.pop_back();
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {

        int n = tiles.length();

        unordered_set<string> sequences;
        vector<int> cnt(26,0);
        for(char c: tiles){
            cnt[c-'A']++;
        }
        
        solve(cnt, "", sequences);

        return sequences.size() - 1;
        
    }
};