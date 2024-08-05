class Solution {
    private:
    bool isPoss(string&s){
        bool flag = false;
        for(int i = 0;i<s.length()-1;i++){
            if(s[i]=='0' && s[i+1]=='1'){
                s[i] = '1';
                s[i+1] = '0';
                i++;
                flag = true;
            }
        }

        return flag;
    }
public:
    int secondsToRemoveOccurrences(string s) {

        int cnt = 0;

        while(isPoss(s)){
            cnt++;
        }

        return cnt;
    }
};