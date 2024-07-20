class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26,0);

        for(char c : tasks){
            freq[c - 'A']++;
        }

        sort(freq.begin(),freq.end());

        int maxFreq = freq[25];

        int spaces = maxFreq - 1;

        int idleSlots = n * spaces;

        for(int i = 24;i>=0;i--){
            idleSlots = idleSlots - min(freq[i],spaces);
        }

        if(idleSlots>0){
            return tasks.size() + idleSlots;
        }
        else{
            return tasks.size();
        }
        
    }
};