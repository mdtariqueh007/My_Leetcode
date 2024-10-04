class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        sort(skill.begin(),skill.end());

        int val = skill[0] + skill.back();

        long long ans = skill[0]*skill.back();

        int i = 1;
        int j = skill.size() - 2;

        while(i<j){
            if(skill[i]+skill[j]!=val){
                return -1;
            }
            
            ans += (skill[i]*skill[j]);
            i++;
            j--;
        }

        return ans;
        
    }
};