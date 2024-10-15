class TopxFrequentSum{
    private:
    unordered_map<int,int> mp;
    set<pair<int,int>> topx, rest;
    long long sum = 0;
    int x;
    public:
    TopxFrequentSum(int limit){
        x = limit;
    }
    void removePrevOcc(int num){
        if(topx.empty() && rest.empty()){
            return;
        }

        if(mp.find(num)==mp.end()){
            return;
        }

        pair<int,int> p = {mp[num],num};
        if(topx.find(p)!=topx.end()){
            sum -= (num * 1LL * mp[num] * 1LL);
            topx.erase(p);
        }
        else if(rest.find(p)!=rest.end()){
            rest.erase(p);
        }
    }

    void add(int num){
        removePrevOcc(num);
        mp[num]++;
        topx.insert({mp[num],num});
        sum += (num* 1LL * mp[num] *1LL);

        if(topx.size()>x){
            auto it = topx.begin();
            rest.insert(*it);
            sum -= (it->first *1LL * it->second * 1LL);
            topx.erase(it);
        }
    }

    void remove(int num){
        removePrevOcc(num);
        mp[num]--;

        if(mp[num]==0){
            mp.erase(num);
        }
        else{
            rest.insert({mp[num],num});
        }

        while(topx.size()<x && !rest.empty()){
            auto it = prev(rest.end());

            sum += (it->first * 1LL  * it->second * 1LL);

            topx.insert(*it);
            rest.erase(it);
        }
    }

    long long getSum(){
        return sum;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        TopxFrequentSum ds = TopxFrequentSum(x);

        vector<long long> ans;

        for(int i = 0;i<n;i++){
            ds.add(nums[i]);

            if(i>=k){
                ds.remove(nums[i-k]);
            }
            if(i>=k-1){
                ans.push_back(ds.getSum());
            }
        }

        return ans;
    }
};