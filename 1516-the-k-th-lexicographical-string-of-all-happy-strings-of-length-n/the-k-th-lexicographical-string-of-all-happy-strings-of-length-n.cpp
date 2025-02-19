class Solution {
    private:
    void solve(string curr, char prev, int n, vector<string>&happyStrings){
        if(curr.length()==n){
            happyStrings.push_back(curr);
            return;
        }

        if(prev=='a'){
            solve(curr+"b", 'b', n, happyStrings);
            solve(curr+"c", 'c', n, happyStrings);
        }
        else if(prev=='b'){
            solve(curr+"a", 'a', n, happyStrings);
            solve(curr+"c", 'c', n, happyStrings);
        }
        else{
            solve(curr+"a", 'a', n, happyStrings);
            solve(curr+"b", 'b', n, happyStrings);
        }
    }
public:
    string getHappyString(int n, int k) {

        vector<string> happyStrings;

        solve("a", 'a', n, happyStrings);
        solve("b", 'b', n, happyStrings);
        solve("c", 'c', n, happyStrings);

        if(k>happyStrings.size()){
            return "";
        }

        sort(happyStrings.begin(), happyStrings.end());

        

        return happyStrings[k-1];


        
    }
};