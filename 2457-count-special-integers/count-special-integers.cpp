class Solution {
    private:
    int solve(int ind,int tight,int mask,string &num){
        if(ind==num.size()){
            return 1;
        }

        int ans = 0;

        int ub = tight ? num[ind] - '0':9;

        for(int dig = 0;dig<=ub;dig++){
            if(mask==0 && dig==0){
                ans += solve(ind+1,(tight && dig==ub),0,num);
            }
            else{
                if((mask & 1<<dig)==0){
                    ans += solve(ind+1,(tight && dig==ub), mask|(1<<dig),num);
                }
            }
            
        }

        return ans;
    }
public:
    int countSpecialNumbers(int n) {
       string num = to_string(n);

       return solve(0,1,0,num) - 1; 
    }
};