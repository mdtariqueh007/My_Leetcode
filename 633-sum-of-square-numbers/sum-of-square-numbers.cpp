class Solution {
public:
    bool judgeSquareSum(int c) {

        unordered_map<long long,long long> mp;

        for(long long i = 0;i*i<=INT_MAX;i++){
            if((i*i + i*i)==c){
                return true;
            }
            if(mp.find(c-i*i)!=mp.end()){
                return true;
            }

            mp[i*i]++;
        }

        return false;
        
    }
};