class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.rbegin(),enemyEnergies.rend());

        int n = enemyEnergies.size();

        int i = 0, j = n - 1;

        long long p = 0, e = currentEnergy;

        if(e<enemyEnergies[j]){
            return 0;
        }

        while(i<=j){
            if(enemyEnergies[j]<=e){
                p += e/enemyEnergies[j];
                e = e%enemyEnergies[j];
                // j--;
            }
            else{
                e += enemyEnergies[i];
                i++;
            }
        }

        return p;
    }
};