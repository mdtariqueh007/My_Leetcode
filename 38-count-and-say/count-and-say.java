class Solution {
    private String helper(int n){
        if(n==1){
            return "1";
        }

        String s = helper(n-1);

        StringBuilder ans = new StringBuilder();

        int cnt = 1;

        for(int i = 0;i<s.length()-1;i++){
            if(s.charAt(i)==s.charAt(i+1)){
                cnt++;
            }else{
                ans.append(cnt);
                ans.append(s.charAt(i));
                cnt = 1;
            }
        }

        if(cnt>=1){
            ans.append(cnt);
            ans.append(s.charAt(s.length()-1));
            
        }

        return ans.toString();



    }
    public String countAndSay(int n) {
        return helper(n);
    }
}