class BIT{
    private:
    vector<int> bit;
    int n;
    public:
    BIT(int n){
        this->n = n;
        bit.resize(n+1,0);
    }
    void update(int ind, int val){
        ind++;

        while(ind<=n){
            bit[ind] += val;
            ind += (ind & -ind);
        }
    }

    int query(int ind){
        ind++;

        int sum = 0;

        while(ind> 0){
            sum += bit[ind];
            ind -= (ind & -ind);
        }

        return sum;
    }
};

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        BIT bit(n);

        for(auto it: shifts){
            int left = it[0];
            int right = it[1];
            int dir = it[2];

            if(dir==1){
                bit.update(left, 1);
                bit.update(right + 1, - 1);
            }
            else{
                bit.update(left, -1);
                bit.update(right+1, 1);
            }
        }

        for(int i = 0;i<n;i++){
            int increment = (s[i] - 'a' + bit.query(i))%26;

            increment = (increment + 26)%26;

            s[i] = 'a' + increment;
        }

        return s;
    }
};