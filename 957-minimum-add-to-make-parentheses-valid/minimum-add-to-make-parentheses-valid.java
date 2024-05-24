class Solution {
    public int minAddToMakeValid(String s) {
        Stack<Character> st = new Stack<Character>();
        
        int res = 0;

        for(int i = 0;i<s.length();i++){
            if(s.charAt(i)=='('){
                st.push('(');
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    res++;
                }
            }
        }

        if(!st.empty()){
            res += st.size();
        }

        return res;
    }
}