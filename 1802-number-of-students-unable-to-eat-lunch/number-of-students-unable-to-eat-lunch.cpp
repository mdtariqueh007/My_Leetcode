class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
            vector<int> count(2,0);

            for(int i = 0;i<students.size();i++){
                count[students[i]]++;
            }

            int remaining  = sandwiches.size();
            for(int sandwich : sandwiches){
                if(count[sandwich]==0){
                    break;
                }

                if(remaining-- ==0){
                    break;
                }
                count[sandwich]--;
            }

            return remaining;


    }
};