class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {

        string start = event1[0];
        string end = event1[1];
        string s = event2[0];
        string e = event2[1];

        

        if((s<start && e<start) || (s>end && e>end)){
            return false;
        }

        return true;
    }
};