class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        vector<int> temp = arr;

        unordered_map<int,int> mp1, mp2;

        int chunks = 0;

        sort(temp.begin(), temp.end());

        for(int i = 0;i<arr.size();i++){
            mp1[arr[i]]++;
            mp2[temp[i]]++;

            if(mp1==mp2){
                chunks++;
                mp1.clear();
                mp2.clear();
            }
        }

        return chunks;
        
    }
};