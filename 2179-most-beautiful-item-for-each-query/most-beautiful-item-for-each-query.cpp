class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        sort(items.begin(), items.end());

        int n = items.size();

        int maxBeauty = items[0][1];
        for(int i = 1;i<n;i++){
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        vector<int> ans;

        for(int q: queries){
            int maxBeauty = 0;
            
            int low = 0, high = n - 1;

            while(low<=high){

                int mid = low + (high - low)/2;

                if(items[mid][0]>q){
                    high = mid - 1;
                }
                else{
                    maxBeauty = max(maxBeauty, items[mid][1]);
                    low = mid + 1;
                }

            }

            ans.push_back(maxBeauty);
        }

        return ans;
        
    }
};