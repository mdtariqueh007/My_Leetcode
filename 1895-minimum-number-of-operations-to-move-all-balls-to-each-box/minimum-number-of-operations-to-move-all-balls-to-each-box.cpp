class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int> ans;
        
        vector<int> onesPos;

        for(int i = 0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                onesPos.push_back(i);
            }
        }

        for(int i = 0;i<boxes.size();i++){
            int cnt = 0;

            for(auto it: onesPos){
                cnt += abs(i - it);
            }

            ans.push_back(cnt);
        }

        return ans;


    }
};