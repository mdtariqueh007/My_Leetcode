class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.size();


        int balance = 0;

        string ans = s;

        for(int i = 0;i<n;i++){
            if(s[i]=='('){
                balance++;
            }
            else if(s[i]==')'){
                balance--;
            }
            
            if(balance<0){
                ans[i] = '$';
                balance++;
            }

        }

        balance = 0;

        for(int i = ans.size()-1;i>=0;i--){
            if(ans[i]==')'){
                balance++;
            }
            else if(ans[i]=='('){
                balance--;
            }

            if(balance<0){
                ans[i] = '$';
                balance++;
            }
        }

        int i = 0;

        for(int j = 0;j<ans.size();j++){
            if(ans[j]!='$'){
                ans[i++] = ans[j];
            }
        }

        return ans.substr(0,i);



        
        
    }
};