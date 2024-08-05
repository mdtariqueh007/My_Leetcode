class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {

        vector<int> temp;

        int n = s.length();

        for(int i = 0;i<n;i++){
            if(s[i]=='|'){
                temp.push_back(i);
            }
        }

       

       

        vector<int> ans;

        for(auto it : queries){
            int start = it[0];
            int end = it[1];

            int startInd = lower_bound(temp.begin(),temp.end(),start) - temp.begin();
            int endInd = upper_bound(temp.begin(),temp.end(),end) - temp.begin();
            endInd--;

            if(endInd<=startInd){
                ans.push_back(0);
            }
            else{
                int numberOfCandles = temp[endInd] - temp[startInd] - (endInd - startInd);

                ans.push_back(numberOfCandles);
            }
        }

        return ans;
        
    }
};