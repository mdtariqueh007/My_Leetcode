class Solution {
    private boolean check(int node,int col,int[][]graph,int[]color){
        color[node] = col;

        for(int it : graph[node]){
            if(color[it]==-1){
                if(check(it,1-col,graph,color)==false){
                    return false;
                }
            }
            else if(color[it]==col){
                return false;
            }
        }

        return true;
    }
    public boolean isBipartite(int[][] graph) {

        int n = graph.length;

        int[] color = new int[n];

        for(int i = 0;i<n;i++){
            color[i] = -1;
        }

        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                if(check(i,0,graph,color)==false){
                    return false;
                }
            }
        }

        return true;
        
    }
}