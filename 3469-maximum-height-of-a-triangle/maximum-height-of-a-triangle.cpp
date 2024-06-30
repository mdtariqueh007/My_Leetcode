class Solution {
    private:
    int solve(int a,int b){
        int cnt = 0;
        int curr = a;
        int req = 1;
        while(curr>=req){
            cnt++;
            if(curr==a){
                a = a - req;
                curr = b;
            }
            else{
                b = b - req;
                curr = a;
            }

            req++;
        }

        return cnt;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red,blue),solve(blue,red));
    }
};