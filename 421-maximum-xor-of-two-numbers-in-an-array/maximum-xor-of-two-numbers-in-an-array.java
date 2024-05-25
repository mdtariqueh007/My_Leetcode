class Node{
    Node[] links;

    Node(){
        links = new Node[2];
    }

    boolean containsKey(int bit){
        return links[bit]!=null;
    }

    Node get(int bit){
        return links[bit];
    }

    void put(int bit, Node node){
        links[bit] = node;
    }
}

class Trie{
    private Node root;

    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node node = root;

        for(int i = 31;i>=0;i--){
            int bit = (num&(1<<i))!=0?1:0;

            if(!node.containsKey(bit)){
                node.put(bit, new Node());
            }

            node = node.get(bit);
        }
    }

    int getMax(int num){
        Node node = root;

        int maxNum = 0;

        for(int i = 31;i>=0;i--){
            int bit = (num&(1<<i))!=0?1:0;

            if(!node.containsKey(1-bit)){
                node = node.get(bit);
            }else{
                maxNum = maxNum|(1<<i);

                node = node.get(1-bit);
            }
        }

        return maxNum;
    }
}

class Solution {
    public int findMaximumXOR(int[] nums) {

        Trie t = new Trie();

        for(int it : nums){
            t.insert(it);
        }

        int ans = 0;

        for(int i = 0;i<nums.length;i++){
            int res = t.getMax(nums[i]);

            ans = Math.max(ans,res);
        }

        return ans;
        
    }
}