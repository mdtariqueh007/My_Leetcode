class Solution {
    private:
    int largestArea(vector<int>&histo){
        int n = histo.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0;i<n;i++){
            while(!st.empty() && histo[st.top()]>=histo[i]){
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();

                int area = histo[ele]* (nse - pse - 1);

                maxArea = max(maxArea,area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int ele = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty()?-1:st.top();

            int area = histo[ele]* (nse - pse - 1);

            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> height(m,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                    height[j] = 0;
                }
            }

            maxArea = max(maxArea,largestArea(height));

        }
        return maxArea;
    }
};