class Solution {
public:
    int maxOperations(string s) {

        vector<int> temp;

        s += "1";

        int cons1 = 0;

        for(char c : s){
            if(c=='1'){
                cons1++;
            }
            else{
                if(cons1>0)
                temp.push_back(cons1);
                cons1 = 0;
            }
        }

        if(cons1>0){
            temp.push_back(cons1);
        }

        for(int x : temp){
            cout<<x<<" ";
        }

        cout<<"\n";

        int sum = 0;
        int pre = 0;

        for(int i = 0;i<temp.size() - 1;i++){
            pre = pre + temp[i];

            sum = sum + pre;
        }

        return sum;

        return -1;
        
    }
};