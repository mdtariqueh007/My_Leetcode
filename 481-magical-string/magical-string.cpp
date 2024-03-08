class Solution {
public:
    int magicalString(int n) {
        
        if(n<=3){
            return 1;
        }

        string s = "122";

        int cntOnes = 1;

        int i = 2;

        while(s.size()<n){
            if(s[i]=='1'){
                if(s.back()=='1'){
                    s += "2";
                }else{
                    s += "1";
                    cntOnes++;
                }
            }else{
                if(s.back()=='1'){
                    s += "22";
                }else{
                    s += "11";
                    cntOnes += 2;
                }
            }
            i++;
        }

        if(s.size()==n){
            return cntOnes;
        }else{
            if(s.back()=='1'){
                return cntOnes - 1;
            }else{
                return cntOnes;
            }
        }



    }
};