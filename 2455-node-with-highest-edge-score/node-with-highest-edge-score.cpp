class Solution {
public:
    int edgeScore(vector<int>& edges) {

        int n = edges.size();

        vector<long long> score(n);


        for(int i = 0;i<n;i++){
            int u = i;
            int v = edges[i];

            score[v] += i;
        }

        long long maxScore = 0;
        int ind = -1;

        for(int i = 0;i<n;i++){
            if(score[i]>maxScore){
                maxScore = score[i];
                ind = i;
            }
        }

        return ind;
        
    }
};