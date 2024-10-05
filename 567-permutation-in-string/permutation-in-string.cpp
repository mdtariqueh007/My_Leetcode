class Solution {
public:

    bool areSame(int arr1[],int arr2[],int n ){
        for(int i = 0;i<n;i++){
            if(arr1[i]!=arr2[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        if(s1.length()>s2.length()) return false;

        int CT[26]={0},CP[26]={0};

        for(int i = 0;i<s1.length();i++){
            CT[s2[i]-'a']++;
            CP[s1[i]-'a']++;
        }
        for(int i = s1.length();i<s2.length();i++){
            if(areSame(CT,CP,26))
                return true;
            CT[s2[i]-'a']++;
            CT[s2[i-s1.length()]-'a']--;
        }
        if(areSame(CT,CP,26)) return true;

        return false;
        
    }
};