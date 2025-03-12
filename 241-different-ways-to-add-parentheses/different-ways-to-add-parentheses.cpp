class Solution {
    private:
    vector<int> solve(string expression){
        vector<int> res;

        if(expression.size()==0){
            return res;
        }

        if(expression.size()==1){
            res.push_back(stoi(expression));
            return res;
        }

        if(expression.size()==2 && isdigit(expression[0])){
            res.push_back(stoi(expression));

            return res;
        }

        for(int i = 0;i<expression.size();i++){
            char curr = expression[i];

            if(isdigit(curr)){
                continue;
            }

            vector<int> leftRes = solve(expression.substr(0,i));
            vector<int> rightRes = solve(expression.substr(i+1));

            for(int lVal: leftRes){
                for(int rVal: rightRes){
                    int ans = 0;

                    if(curr=='+'){
                        ans = lVal + rVal;
                    }
                    else if(curr=='-'){
                        ans = lVal - rVal;
                    }
                    else if(curr=='*'){
                        ans = lVal * rVal;
                    }

                    res.push_back(ans);
                }
            }
        }

        return res;
    }
public:
    vector<int> diffWaysToCompute(string expression) {

        return solve(expression);

        
        
    }
};