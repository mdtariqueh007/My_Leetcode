class Solution {
public:
    int minOperations(vector<string>& logs) {

        int cnt = 0;

        for(string s : logs){
            string t = s;
            reverse(t.begin(),t.end());

            t = t.substr(1);

            cout<<t<<"\n";

            if(t==".."){
                if(cnt>0){
                    cnt--;  
                }
            }
            else if(t=="."){
                cnt = cnt;
            }
            else{
                cnt++;
            }
        }

        return cnt;
        
    }
};