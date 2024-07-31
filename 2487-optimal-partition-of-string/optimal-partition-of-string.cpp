class Solution {
public:
    int partitionString(string s) {
        
        set<char> st;

        int n = s.size();

        int cnt = 0;

        for(int i = 0;i<n;i++){
            if(st.find(s[i])!=st.end()){
                cnt++;
                st.clear();
            }

            st.insert(s[i]);
        }

        return cnt+1;


    }
};