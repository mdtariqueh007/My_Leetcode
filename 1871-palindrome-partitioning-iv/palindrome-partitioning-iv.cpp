class Solution {
    private:
    bool isPalindrome(int i,int j,string&s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    bool solve(int ind,string &s,int partitions){
        if(ind>=s.length()){
            return partitions==0;
        }

        if(partitions==0){
            return isPalindrome(ind,s.size()-1,s);
        }

        bool flag = false;


        for(int i = ind;i<s.size()-1;i++){
            if(isPalindrome(ind,i,s)){
                flag = flag || solve(i+1,s,partitions-1); 
            }
        }

        return flag;


    }
public:
    bool checkPartitioning(string s) {
        return solve(0,s,2);
    }
};