class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int maxi = -1;

        int chunks = 0;

        int n = arr.size();

        for(int i = 0;i<n;i++){
            maxi = max(maxi, arr[i]);

            if(maxi==i){
                chunks++;
            }
        }


        return chunks;
        
    }
};