class Solution {
public:
    int nthUglyNumber(int n) {

        if(n==1){
            return 1;
        }

        int cnt = 0;
        
        set<long long> st;

        long long curr = 1;

        st.insert(curr);

        while(cnt<n){
            curr = *st.begin();
            st.erase(st.begin());

            st.insert(curr*2);
            st.insert(curr*3);
            st.insert(curr*5);

            cnt++;
        }

        return curr;


        
    }
};