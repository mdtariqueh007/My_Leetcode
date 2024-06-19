class Solution {
    private boolean isPossible(int[] bloomDay,int m,int k,int mid){
        int boq=0;
        int cnt = 0;

        for(int i = 0;i<bloomDay.length;i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                boq += cnt/k;
                cnt = 0;
            }
        }

        boq += cnt/k;

        return boq>=m;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;

        int maxi = bloomDay[0];
        int mini = bloomDay[0];

        for(int i = 1;i<n;i++){
            maxi = Math.max(bloomDay[i],maxi);
            mini = Math.min(bloomDay[i],mini);
        }

        int low = mini, high = maxi, ans = -1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isPossible(bloomDay,m,k,mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
}