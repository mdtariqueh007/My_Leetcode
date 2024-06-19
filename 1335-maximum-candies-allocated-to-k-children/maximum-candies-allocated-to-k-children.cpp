class Solution {
    private:
    bool isPossible(vector<int>&candies,long long k,int mid){
        long long cnt = 0;
        

        for(int i = 0;i<candies.size();i++){
            if(candies[i]>=mid){
                cnt += (candies[i])/mid;
                if(cnt>=k){
                    return true;
                }
            }
        }

       

        return cnt>=k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {

        int n = candies.size();

        int ans = 0;

        int low = 1;
        int high = *max_element(candies.begin(),candies.end());

        // for(int i = high;i>=low;i--){
        //     if(isPossible(candies,k,i)){
        //         return i;

        //     }
        // }/

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(candies,k,mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;

        
    }
};