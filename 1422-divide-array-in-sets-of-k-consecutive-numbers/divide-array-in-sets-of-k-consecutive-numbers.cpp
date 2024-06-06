class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        if(nums.size()%k!=0){
            return false;
        }
        multiset<int> mt;

        for(int i = 0;i<nums.size();i++){
            mt.insert(nums[i]);
        }

        while(!mt.empty()){
            auto it = mt.begin();

            int x = *it;

            mt.erase(mt.find(x));

            for(int i = 1;i<k;i++){
                auto it = mt.find(x+i);

                if(it==mt.end()){
                    return false;
                }
                mt.erase(it);
            }
        }

        return true;
    }
};