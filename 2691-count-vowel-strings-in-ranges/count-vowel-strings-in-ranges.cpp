class Solution {
    private:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    bool isValid(string& s){
        int n = s.length();

        return (isVowel(s[0]) && isVowel(s[n-1]));
        
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();

        vector<int> prefix(n,0);

        prefix[0] = isValid(words[0]);

        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + (isValid(words[i]));
        }

        vector<int> ans;

        for(auto q: queries){
            int l = q[0];
            int r = q[1];

            if(l==0){
                ans.push_back(prefix[r]);
            }
            else{
                ans.push_back(prefix[r] - prefix[l-1]);
            }
        }

        return ans;

    }
};