class Solution {
    private:
    bool isPossible(string&s ,int mid, int numOps){
        int n = s.length();

        if(mid==1){

            //0101..

            int req1 = 0;

            for(int i = 0;i<n;i++){
                if(i&1 && s[i]=='0'){
                    req1++;
                }
                else if((i&1)==0 && s[i]=='1'){
                    req1++;
                }
            }

            //1010..

            int req2 = 0;

            for(int i = 0;i<n;i++){
                if(i&1 && s[i]=='1'){
                    req2++;
                }
                else if((i&1)==0 && s[i]=='0'){
                    req2++;
                }
            }

            return min(req1, req2)<=numOps;

        }

        int cnt = 1;
        int req = 0;

        for(int i = 1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{

                req += (cnt)/(mid+1);

                cnt = 1;

            }
        }

        req += (cnt)/(mid+1);

        return req<=numOps;
    }
public:
    int minLength(string s, int numOps) {

        int n = s.length();

        int low = 1, high = n;

        int ans = high;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isPossible(s, mid, numOps)){
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