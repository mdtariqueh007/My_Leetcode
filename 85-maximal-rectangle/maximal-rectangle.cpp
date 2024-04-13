class Solution {
    private:
    int largestArea(vector<int>&histo){
        stack<int> st;
        int n = histo.size();
        int maxArea = 0;
        for(int i = 0;i<=n;i++){
            while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
                int height = histo[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i-st.top()-1;
                maxArea = max(maxArea,height*width);
            }
            st.push(i);
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