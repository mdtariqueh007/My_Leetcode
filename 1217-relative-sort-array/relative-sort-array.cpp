class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxi = *max_element(arr1.begin(),arr1.end());
        vector<int> count(maxi+1);

        for(int x : arr1){
            count[x]++;
        }

        vector<int> res;

        for(int x : arr2){
            while(count[x]>0){
                res.push_back(x);
                count[x]--;
            }
        }

        for(int i = 0;i<=maxi;i++){
            while(count[i]>0){
                res.push_back(i);
                count[i]--;
            }
        }

        return res;
    }
};