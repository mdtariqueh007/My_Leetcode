class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int n = s.length;
        int m = g.length;

        int i = 0, j = 0;

        while(i<n && j<m){
            if(s[i]>=g[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return j;
    }
}