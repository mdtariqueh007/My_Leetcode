class Solution {
    private:
    bool isPrefixAndSuffix(string& str1, string& str2){
        int n = str1.size();
        int m = str2.size();

        if(n>m){
            return false;
        }

        string pre = str2.substr(0, n);
        string suff = str2.substr(m - n);

        return pre==str1 && suff==str1;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {

        int n = words.size();

        int ans = 0;

        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                string& str1 = words[i];
                string& str2 = words[j];

                if(isPrefixAndSuffix(str1, str2)){
                    ans++;
                }

            }
        }

        return ans;
        
    }
};