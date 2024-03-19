class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int>freq(26,0);
        for(int i = 0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }

        sort(freq.rbegin(),freq.rend());

        int maxFreq = freq[0];

        int idleTime = (maxFreq-1)*n;

        for(int i = 1;i<26 && idleTime>0;i++){
            idleTime = idleTime - min(maxFreq-1,freq[i]);
        }
        idleTime = max(0,idleTime);

        return idleTime + tasks.size();
        
    }
};