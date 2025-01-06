class Solution {
public:
    vector<int> minOperations(string boxes) {


        int n = boxes.size();

        vector<int> answer(n,0);

        int ballsInLeft = 0, movesToLeft = 0;
        int ballsInRight = 0, movesToRight = 0;

       

        for(int i = 0;i<n;i++){
            answer[i] += movesToLeft;

            ballsInLeft += boxes[i] - '0';
            movesToLeft += ballsInLeft;

            int j = n - i - 1;

            answer[j] += movesToRight;

            ballsInRight += boxes[j] - '0';
            movesToRight += ballsInRight;
        }

        return answer;
        
    }
};