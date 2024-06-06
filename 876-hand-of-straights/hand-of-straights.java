class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {

        int n = hand.length;

        if(n%(groupSize)!=0){
            return false;
        }

        Map<Integer, Integer> mp = new TreeMap<>();

        for(int card :hand){
            mp.put(card,mp.getOrDefault(card,0)+1);
        }

        for(int card : mp.keySet()){
            int cnt = mp.get(card);
            if(cnt>0){
                for(int i = 0;i<groupSize;i++){
                    if(mp.getOrDefault(card+i,0)<cnt){
                        return false;
                    }

                    mp.put(card+i,mp.get(card+i) - cnt);
                }
            }
        }

        return true;


        
    }
}