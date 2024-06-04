class Solution {
    public int longestPalindrome(String s) {
        int[] cnt = new int[256];

        int odd = 0;

        for(int i = 0;i<s.length();i++){
            cnt[s.charAt(i)]++;
        }

        for(int i = 'A';i<='Z';i++){
            if((cnt[i]&1)!=0){
                odd++;
            }
        }
        for(int i = 'a';i<='z';i++){
            if((cnt[i]&1)!=0){
                odd++;
            }
        }

        if(odd==0){
            return s.length();
        }
        else{
            return s.length()-odd + 1;
        }
    }

}