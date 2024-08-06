class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {

        int n = tiles.size();

        sort(tiles.begin(),tiles.end());

        vector<int> prefix(n);

        prefix[0] = tiles[0][1] - tiles[0][0] + 1;

        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + tiles[i][1] - tiles[i][0] + 1;
        }

        int ans = 0;

        for(int i = 0;i<n;i++){
            int leftEnd = tiles[i][0];
            int rightEnd = tiles[i][0] + carpetLen - 1;

            int low = i;
            int high = n - 1;

            int left = i;
            int right = i - 1;

            while(low<=high){
                int mid = low + (high - low)/2;

                if(tiles[mid][1]<=rightEnd){
                    right = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }

            int temp = 0;

            if(right!=i-1){
                temp += prefix[right];
                if(left>0){
                    temp -= prefix[left - 1];
                }
            }

            if(right+1<n){
                temp += max(0,rightEnd - tiles[right+1][0] + 1);
            }

            ans = max(ans,temp);
        }

        return ans;

    }
};