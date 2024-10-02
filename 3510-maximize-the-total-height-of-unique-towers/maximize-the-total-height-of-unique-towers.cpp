class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {

        long long sum = 0;

        int n = maximumHeight.size();

        sort(maximumHeight.rbegin(),maximumHeight.rend());

        int last = 1e9+1;

        for(int i = 0;i<n;i++)
        {
            if(maximumHeight[i]<last){
                sum += maximumHeight[i];
                last = maximumHeight[i];
            }
            else{
                if(last-1==0){
                    return -1;
                }
                sum += last - 1;
                last = last - 1;
            }
        }

        return sum;
        
    }
};