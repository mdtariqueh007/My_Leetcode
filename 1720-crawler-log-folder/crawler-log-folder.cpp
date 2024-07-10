class Solution {
public:
    int minOperations(vector<string>& logs) {

        int cnt = 0;

        for(string s : logs){

            if(s=="../"){
                if(cnt>0){
                    cnt--;
                }
            }
            else if(s!="./"){
                cnt++;
            }
        }

        return cnt;
        
    }
};