class Solution {
    long long atMostK(string word, int k){
        int n = word.size();

        int left = 0;
        int cntCons = 0;

        long long cnt = 0;
        unordered_map<int,int> mp;
        unordered_set<char> st = {'a','e','i','o','u'};

        for(int right = 0;right<n;right++){
            if(st.find(word[right])!=st.end()){
                mp[word[right]]++;
            }
            else{
                cntCons++;
            }

            while(mp.size()==5 && cntCons>k){
                if(st.find(word[left])!=st.end()){
                    mp[word[left]]--;

                    if(mp[word[left]]==0){
                        mp.erase(word[left]);
                    }
                }
                else{
                    cntCons--;
                }

                left++;
            }

            cnt += (right - left + 1);
        }

        return cnt;

    }
public:
    long long countOfSubstrings(string word, int k) {

        return atMostK(word,k) - atMostK(word,k-1);
        
    }
};