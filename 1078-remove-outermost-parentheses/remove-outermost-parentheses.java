class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder sb = new StringBuilder();

        int cnt = 0;

        for(int i = 0;i<s.length();i++){
            if(s.charAt(i)=='(' && cnt==0){
                cnt++;
            }
            else if(s.charAt(i)=='(' && cnt>0){
                sb.append(s.charAt(i));
                cnt++;
            }
            else if(s.charAt(i)==')' && cnt==1){
                cnt--;
            }
            else if(s.charAt(i)==')' && cnt>1){
                sb.append(s.charAt(i));
                cnt--;
            }
        }

        return sb.toString();

    }
}