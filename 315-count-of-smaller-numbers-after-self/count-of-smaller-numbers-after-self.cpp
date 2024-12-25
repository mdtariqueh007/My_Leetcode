#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans(n,0);

        oset<pair<int,int>> st;

        for(int i = n - 1;i>=0;i--){
            ans[i] = st.order_of_key({nums[i],i});
            st.insert({nums[i],i});
        }

        return ans;

    }
};