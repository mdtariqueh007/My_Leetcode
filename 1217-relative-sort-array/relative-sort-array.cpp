class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int,int> mp;

        int rank = arr2.size();

        for(int x : arr2){
            mp[x] = rank--;
        }

        sort(arr1.begin(),arr1.end(),[&](int a,int b){
            if(mp[a]!=0 || mp[b]!=0){
                return mp[a]>mp[b];
            }
            else{
                return a<=b;
            }
        });

        return arr1;
        
    }
};