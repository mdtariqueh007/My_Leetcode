/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {

        if(head==null || head.next==null){
            return null;
        }

        ListNode fast = head;
        ListNode slow = head;
        ListNode entry = head;

        while(fast.next!=null && fast.next.next!=null){
            fast = fast.next.next;
            slow = slow.next;

            if(fast==slow){
                while(slow!=entry){
                    slow = slow.next;
                    entry = entry.next;
                }

                return slow;
            }
        }

        return null;
        
    }
}