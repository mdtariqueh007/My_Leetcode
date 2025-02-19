class Solution {
    private:
    void solve(string curr, char prev, int n, vector<string>&happyStrings){
        if(curr.length()==n){
            happyStrings.push_back(curr);
            return;
        }

        for(char c = 'a';c<='c';c++){
            if(c==prev){
                continue;
            }

            solve(curr+c,c,n, happyStrings);
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
        
        return happyStrings[k-1];


        
    }
};