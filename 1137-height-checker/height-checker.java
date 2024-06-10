class Solution {
    private void countingSort(int[] arr){
        Map<Integer, Integer> mp = new HashMap<>();

        int minVal = Arrays.stream(arr).min().getAsInt();
        int maxVal = Arrays.stream(arr).max().getAsInt();

        for(int val: arr){
            mp.put(val,mp.getOrDefault(val,0)+1);
        }

        int ind = 0;

        for(int val = minVal;val<=maxVal;val++){
            int cnt = mp.getOrDefault(val,0);

            while(cnt>0){
                arr[ind] = val;
                ind++;
                cnt--;
            }

            mp.put(val,0);
        }
    }
    public int heightChecker(int[] heights) {
        int[] temp = heights.clone();

        countingSort(temp);

        int res = 0;

        for(int i = 0;i<heights.length;i++){
            if(heights[i]!=temp[i]){
                res++;
            }
        }

        return res;
    }
}