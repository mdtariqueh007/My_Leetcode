class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_set<int> s;
        for(int i = 0;i<banned.size();i++){
            s.insert(banned[i]);
        }
        
        long long sum = 0;
        int count = 0;
        for(int  i = 1;i<=n;i++){
            if(s.find(i)==s.end() && sum<=maxSum){
                sum+=i;
                count++;
            }
        }
        
        if(sum>maxSum){
            count = count-1;
        }
        
        return count;
        
    }
};