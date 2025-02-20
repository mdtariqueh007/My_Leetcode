class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> present(nums.begin(),nums.end());
        int n = nums[0].length();

        for(int num = 0;num<(1<<n);num++){
            string temp = "";
            for(int i = n-1;i>=0;i--){
                int k = num>>i;
                if(k&1){
                    temp += "1";
                }
                else{
                    temp += "0";
                }
            }

            if(present.find(temp)==present.end()){
                return temp;
            }
        }

        return "";


    }
};