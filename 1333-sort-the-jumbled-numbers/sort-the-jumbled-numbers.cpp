class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        sort(nums.begin(),nums.end(),[&](int a,int b){
            string s1 = to_string(a);
            string s2 = to_string(b);

            for(int i = 0;i<s1.size();i++){
                s1[i] = mapping[s1[i]-'0'] + '0';
            }
            for(int i = 0;i<s2.size();i++){
                s2[i] = mapping[s2[i]-'0'] + '0';
            }

            int num1 = stoi(s1);
            int num2 = stoi(s2);

            return num1<num2;
            
        });

        return nums;
        
    }
};