class Solution {
    private:
    vector<int> helper(string&expression){
        // if(ind>=expression.size()){
        //     return {};
        // }
        if(expression.empty()){
            return {};
        }

        

        vector<int> result;

        bool isNumber = true;

        for(int i = 0;i<=expression.size();i++){
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
                isNumber = false;
                string s1 = expression.substr(0,i);
                string s2 = expression.substr(i+1);
                vector<int> left = helper(s1);
                vector<int> right = helper(s2);

                for(int x:  left){
                    for(int y: right){
                        if(expression[i]=='+'){
                            result.push_back(x+y);
                        }
                        else if(expression[i]=='-'){
                            result.push_back(x-y);
                        }
                        else{
                            result.push_back(x*y);
                        }
                    }
                }
            }
        }

        if(isNumber){
            result.push_back(stoi(expression));
        }

        return result;
    }
public:
    vector<int> diffWaysToCompute(string expression) {

        return helper(expression);
        
    }
};