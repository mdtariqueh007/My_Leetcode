class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> pos(26, -1);

        for(int i = 0;i<s.size();i++){
            pos[s[i]-'a'] = i;
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

            prevLast = max(prevLast, pos[s[i]-'a']);
        }

        ans.push_back(curr);

        return ans;
        
    }
};