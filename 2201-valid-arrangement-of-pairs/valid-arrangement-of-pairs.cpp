class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        unordered_map<int, vector<int>> adj;

        unordered_map<int, int> degree;

        for(auto p: pairs){
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);

            degree[u]++;
            degree[v]--;
        }

        int start = pairs[0][0];

        for(auto it: degree){
            int node = it.first;

            if(degree[node]==1){
                start = node;
                break;
            }
        }

        stack<int> st;

        st.push(start);

        vector<int> seq;

        while(!st.empty()){

            int node = st.top();

            while(!adj[node].empty()){

                int adjNode = adj[node].back();
                adj[node].pop_back();

                st.push(adjNode);

                node = adjNode;

            }

            int last = st.top();
            st.pop();
            seq.push_back(last);

        }

        reverse(seq.begin(), seq.end());

        int n = seq.size();

        vector<vector<int>> ans;

        for(int i = 0;i<n-1;i++){
            ans.push_back({seq[i],seq[i+1]});
        }

        return ans;

    }
};