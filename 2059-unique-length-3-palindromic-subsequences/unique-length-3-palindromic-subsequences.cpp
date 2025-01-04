class Solution {

public:
    int countPalindromicSubsequence(string s) {

        int n = s.length();
        
        vector<pair<int,int>> occ(26,{-1,-1});

        for(int i = 0;i<n;i++){
            if(occ[s[i]-'a'].first==-1){
                occ[s[i]-'a'].first = i;
            }
            else{
                occ[s[i]-'a'].second = i;
            }
        }

        // vector<int> pre(n,0);

        // pre[0] = 1;

        // unordered_set<char> st;

        // st.insert(s[0]);
        // for(int i = 1;i<n;i++){
        //     if(st.find(s[i])!=st.end()){
        //         pre[i] = pre[i-1];
        //     }
        //     else{
        //         pre[i] =pre[i-1] + 1;
        //         st.insert(s[i]);
        //     }
        // }

        // for(int it : pre){
        //     cout<<it<<" ";
        // }

        // cout<<"\n";

       

        int res = 0;

        vector<int> visited(26,0);

        for(int i = 0;i<n;i++){
            if(occ[s[i]-'a'].second!=-1 && !visited[s[i]-'a']){
                int firstOcc = occ[s[i]-'a'].first;
                int lastOcc = occ[s[i]-'a'].second;

                // int countDistinct = 0;
                // if(firstOcc==0){
                //     countDistinct = pre[lastOcc];
                // }
                // else{
                //     countDistinct = pre[lastOcc] - pre[firstOcc-1];
                // }


                // res += countDistinct;

                visited[s[i]-'a'] = 1;

                unordered_set<char> dis;

                for(int ind = firstOcc+1;ind<=lastOcc-1;ind++){
                    dis.insert(s[ind]);
                }

                res += dis.size();
                 
            }
           
        }

         
        return res;



        
    }
};