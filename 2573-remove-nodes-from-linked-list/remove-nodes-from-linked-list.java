/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNodes(ListNode head) {

        Stack<ListNode> st = new Stack<ListNode>();

        for(ListNode curr = head;curr!=null;curr = curr.next){
            st.push(curr);
        }

        head = st.pop();

        while(!st.empty()){
            ListNode curr = st.pop();

            if(curr.val>=head.val){
                ListNode temp = head;
                head = curr;
                head.next = temp;
            }


        }

        return head;
        
    }
}