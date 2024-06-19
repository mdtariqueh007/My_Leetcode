class Solution {
    private:
    bool isPossible(vector<int>&ranks,int cars,long long mins){
        long long car = 0;

        for(int i = 0;i<ranks.size();i++){
            long long canRepair = sqrt(mins/(ranks[i]));
            car += canRepair;
        }

        return car>=cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long cnt = 0;

        int maxi = *max_element(ranks.begin(),ranks.end());

        long long low = 1;
        long long high = (long long)maxi*cars*cars;

        // for(long long i = low;i<=high;i++){
        //     if(isPossible(ranks,cars,i)){
        //         return i;
        //         break;
        //     }
        // }

        long long ans = -1;

        while(low<=high){
            long long mid = low + (high - low)/2;

            if(isPossible(ranks,cars,mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;


    }
};