class Solution {
    private:
    bool isValid(string s){
        int count = 0;

        for(char c: s){
            if(c=='('){
                count++;
            }
            else if(c==')'){
                if(count==0){
                    return false;
                }

                count--;
            }
        }

        return count==0;
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {

        unordered_set<string> visited;

        queue<string> q;

        q.push(s);

        vector<string> ans;

        bool found = false;

        while(!q.empty() && !found){
            int sz = q.size();
            while(sz--){

                string curr = q.front();
                q.pop();

                if(isValid(curr)){
                    ans.push_back(curr);
                    found = true;
                }

                for(int i = 0;i<curr.size();i++){
                    string newString = curr.substr(0,i) + curr.substr(i+1);

                    if(visited.find(newString)==visited.end()){
                        q.push(newString);
                        visited.insert(newString);
                    }
                }

            }
            
        }

        return ans;
        
    }
};