class Solution {
    private:
    bool isPossible(vector<int>&position,int m,int mid){
        int cntBalls = 1;
        int last = position[0];

        for(int i = 1;i<position.size();i++){
            if(abs(position[i]-last)>=mid){
                cntBalls++;
                last = position[i];
            }
            if(cntBalls>=m){
                return true;
            }
        }

        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {

        int n = position.size();

        sort(position.begin(),position.end());

        int low = 1;
        int high = position[n-1] - position[0];

        int ans = 0;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isPossible(position,m,mid)){
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