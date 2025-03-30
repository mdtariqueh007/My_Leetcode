class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<pair<int,int>> pos(26, {-1, -1});

        for(int i = 0;i<s.size();i++){
            if(pos[s[i]-'a'].first==-1){
                pos[s[i]-'a'].first = i;
            }
            pos[s[i]-'a'].second = i;
        }


        int prevLast = 0;
        int curr = 0;

        vector<int> ans;

        for(int i = 0;i<s.size();i++){
            if(i>prevLast){
                ans.push_back(curr);
                curr = 1;
            }
            else{
                curr++;
            }

            prevLast = max(prevLast, pos[s[i]-'a'].second);
        }

        ans.push_back(curr);

        return ans;
        
    }
};