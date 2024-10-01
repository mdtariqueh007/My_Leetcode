class Solution {
    private:
    bool isValid(string&s ,int k){
        int cntCons = 0;
        vector<bool> vowels(5,false);
        for(int i = 0;i<s.size();i++){
            if(s[i]=='a'){
                vowels[0] = true;
            }
            else if(s[i]=='e'){
                vowels[1] = true;
            }
            else if(s[i]=='i'){
                vowels[2] = true;
            }
            else if(s[i]=='o'){
                vowels[3] = true;
            }
            else if(s[i]=='u'){
                vowels[4] = true;
            }
            else{
                cntCons++;
            }

        }

        bool flag = (cntCons==k);

        for(int i = 0;i<5;i++){
            if(vowels[i]==false){
                flag = false;
            }
        }

        return flag;
    }
public:
    int countOfSubstrings(string word, int k) {

        int cnt = 0;

        int n = word.size();

        for(int i = 0;i<n;i++){
            string s = "";

            for(int j = i;j<n;j++){
                s += word[j];

                if(isValid(s,k)){
                    cnt++;
                }
            }
        }

        return cnt;
        
    }
};