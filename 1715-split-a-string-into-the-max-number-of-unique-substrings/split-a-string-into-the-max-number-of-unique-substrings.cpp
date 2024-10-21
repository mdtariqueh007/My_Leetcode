class Solution {
    private:
    int solve(int ind,string&s,unordered_set<string>&seen){
        if(ind==s.size()){
            return 0;
        }

        int maxSplits = 0;

        for(int end = ind;end<s.size();end++){
            string subString = s.substr(ind,end-ind+1);

            if(seen.find(subString)==seen.end()){
                seen.insert(subString);

                maxSplits = max(maxSplits, 1 + solve(end+1,s,seen));

                seen.erase(subString);
            }
        }

        return maxSplits;
    }
public:
    int maxUniqueSplit(string s) {

        unordered_set<string> seen;

        return solve(0,s,seen);
        
    }
};