class Solution {
    private:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int solve(string&s,int k){
        unordered_map<int,int> mp;

        int n = s.length();

        int i = 0;
        int j = 0;

        int res = 0;

        while(j<n){
            if(!isVowel(s[j])){
             i = j + 1;
             mp.clear();
             
            }
            else{
                mp[s[j]]++;
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }

                res += (j - i + 1);
            }

            j++;
           
        }

        return res;
    }
public:
    int countVowelSubstrings(string word) {
        return solve(word,5) - solve(word,4);
    }
};