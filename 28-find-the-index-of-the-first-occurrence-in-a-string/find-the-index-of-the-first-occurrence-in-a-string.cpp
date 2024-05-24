class Solution {
    private:
    vector<int> ZFunc(string&s){
        int n = s.length();

        vector<int> Z(n,0);

        int l = 0, r = 0;

        for(int i = 1;i<n;i++){
            if(i<=r){
                Z[i] = min(Z[i-l],r-i+1); 
            }
            while(i+Z[i]<n && (s[Z[i]]==s[i+Z[i]])){
                Z[i]++;
            }

            if((i+Z[i]-1)>r){
                l = i;
                r = i + Z[i] - 1;
            }
        }

        return Z;
    }
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();

        string str = needle + "#" + haystack;

        vector<int> Z = ZFunc(str);

        for(int i = 0;i<Z.size();i++){
            if(Z[i]==m){
                return (i - m - 1);
            }
        }

        return -1;
    }
};