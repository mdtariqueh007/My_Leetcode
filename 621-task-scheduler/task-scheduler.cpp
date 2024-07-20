class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(char c : tasks){
            freq[c-'A']++;
        }

        int time = 0;

        priority_queue<int> pq;

        for(int i = 0;i<26;i++){
            if(freq[i]>0)
                pq.push(freq[i]);
        }

        while(!pq.empty()){
            vector<int> temp;

            for(int i = 0;i<n+1;i++){
                if(!pq.empty()){
                    int cnt = pq.top();
                    pq.pop();
                    cnt--;
                    
                    temp.push_back(cnt);
                    
                }
            }

            for(int x : temp){
                if(x>0)
                pq.push(x);
            }

            if(pq.empty()){
                time += temp.size();
            }
            else{
                time += (n + 1);
            }
        }

        return time;
    }
};