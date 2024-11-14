class Solution {
    private:
    bool isPossToDistribute(int n, int x, vector<int>quantities){

        int j = 0;

        int remain = quantities[j];

        for(int i = 0;i<n;i++){
            if(remain<=x){
                j++;

                if(j==quantities.size()){
                    return true;
                }else{
                    remain = quantities[j];
                }
            }
            else{
                remain -= x;
            }

        }

        return false;

    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 0, high = *max_element(quantities.begin(), quantities.end());

        int ans = -1;

        while(low<=high){

            int mid = low + (high - low)/2;

            if(isPossToDistribute(n,mid,quantities)){
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