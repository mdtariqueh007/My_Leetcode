class Solution {
    private:
    bool solve(vector<int>&seq, vector<bool>& used, int n, int ind){
        if(ind==seq.size()){
            return true;
        }

        if(seq[ind]!=0){
            return solve(seq, used, n, ind+1);
        }

        for(int num = n;num>0;num--){
            if(used[num]){
                continue;
            }

            if(num==1){
                seq[ind] = 1;
                used[1] = true;
                if(solve(seq, used, n, ind+1)){
                    return true;
                }
                seq[ind] = 0;
                used[1] = false;
            }
            else if(ind+num<seq.size() && seq[ind+num]==0){
                seq[ind] = num;
                seq[ind+num] = num;
                used[num] = true;

                if(solve(seq, used, n, ind+1)){
                    return true;
                }

                seq[ind] = 0;
                seq[ind+num] = 0;
                used[num] = false;
            }
        }

        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {

        vector<int> seq(2 * n - 1, 0);
        vector<bool> used(n+1, false);

        solve(seq, used, n, 0);

        return seq;
        
    }
};