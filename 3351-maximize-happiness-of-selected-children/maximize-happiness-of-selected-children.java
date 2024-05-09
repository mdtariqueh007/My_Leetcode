class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a,b)->b-a);

        for(int i : happiness){
            pq.add(i);
        }

        int minus = 0;

        long sum = 0;

        while(k>0 && !pq.isEmpty()){
            int top = pq.peek();
            pq.poll();

            top = top - minus;

            if(top<=0){
                break;
            }

            sum += top;

            minus++;
            k--;
        }

        return sum;
    }
}