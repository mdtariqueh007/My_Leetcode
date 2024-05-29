class Solution {
public:
    bool isNumber(string s) {

        int state = 0;

        int n = s.length();

        // if(s=="."){
        //     return false;
        // }


        for(int i = 0;i<n;i++){
            if(s[i]=='+' || s[i]=='-'){
                if(state==0 || state==3){
                    state++;
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='.'){
                if(state==0 || state==1){
                    state = 6;
                }else if(state==2){
                    state = 8;
                }
                else{
                    return false;
                }
            }
            else if(s[i]>='0' && s[i]<='9'){
                if(state==1 || state==4 || state==6){
                    state++;
                }
                else if(state==3 || state==0){
                    state += 2;
                }
            }
            else if(s[i]=='e' || s[i]=='E'){
                if(state==2  || state==7 || state==8){
                    state = 3;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

        if(state==2 || state==5 || state==7 || state==8){
            return true;
        }

        return false;
        
    }
};