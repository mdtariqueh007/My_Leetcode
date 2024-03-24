class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(),deadends.end());

        if(dead.find("0000")!=dead.end()){
            return -1;
        }

        if(target=="0000"){
            return 0;
        }

        unordered_set<string> seen;

        queue<string> q;

        q.push("0000");

        seen.insert("0000");

        int minTurns = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string str = q.front();
                q.pop();
                for(int i = 0;i<4;i++){
                    vector<string> s(2,str);
                    s[0][i] = (s[0][i] - '0' + 1)%10 + '0';
                    s[1][i] = (s[1][i] -'0' -1 +10)%10 + '0';

                    for(int j = 0;j<2;j++){
                        if(seen.find(s[j])==seen.end() && dead.find(s[j])==dead.end()){
                            if(target==s[j]){
                                return minTurns+1;
                            }
                            q.push(s[j]);
                            seen.insert(s[j]);
                        }
                    }
                }
            }
            minTurns++;
        }

        return -1;


        
    }
};