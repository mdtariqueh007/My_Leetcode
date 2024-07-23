class Solution {
    private:
    
    int solve(vector<int>& text1, vector<int>& text2){
        int n = text1.size(),m= text2.size();
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int ind1 = 1;ind1<=n;ind1++){
            for(int ind2 = 1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1]){
                    curr[ind2] = 1 + prev[ind2-1];
                }
                else{
                    curr[ind2] = max(prev[ind2],curr[ind2-1]);
                }
            }
            prev = curr;
        }
        return prev[m]; 
    }
    int solve2(vector<int>&arr){ //LIS

    if(arr.size()<=1){
        return arr.size();
    }

        int n = arr.size();

        vector<int> temp;

        temp.push_back(arr[0]);

        for(int i = 1;i<n;i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }

        return temp.size();

    }
public:
    int minOperations(vector<int>& target, vector<int>& arr) {

        int n = target.size();
        int m = arr.size();

        unordered_map<int,int> mp;

        for(int  i=  0;i<target.size();i++){
            mp[target[i]] = i;
        }

        vector<int> temp;

        for(int i = 0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()){
                temp.push_back(mp[arr[i]]);
            }    
        }
        // for(int x  :temp){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        return target.size() - solve2(temp);

        



        // return target.size() - solve(target,arr);
        
    }
};