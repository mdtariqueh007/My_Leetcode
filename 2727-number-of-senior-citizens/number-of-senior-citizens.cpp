class Solution {
public:
    int countSeniors(vector<string>& details) {

        int cnt = 0;

        for(string s  : details){
            string Age = s.substr(11,2);
            if(Age>"60"){
                cnt++;
            }
        }

        return cnt;
        
    }
};