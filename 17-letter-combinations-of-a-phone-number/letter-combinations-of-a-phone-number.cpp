class Solution {
    void f(int ind,string&digits,string&res,vector<string>&ans,vector<string>&mapping){
        if(ind==digits.size()){
            ans.push_back(res);
            return;
        }

        int index = digits[ind] - '0';
        string val = mapping[index];
        for(int j = 0;j<val.size();j++){
            res.push_back(val[j]);
            f(ind+1,digits,res,ans,mapping);
            res.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        string res = "";
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        f(0,digits,res,ans,mapping);

        return ans;

        
    }
};