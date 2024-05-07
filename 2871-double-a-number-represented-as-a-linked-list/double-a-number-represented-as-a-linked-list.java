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
    public ListNode reverseList(ListNode head){
        if(head==null || head.next==null){
            return head;
        }

        ListNode prev = null;
        ListNode curr = head;
        ListNode next = curr;

        while(curr!=null){
            next = curr.next;
            curr.next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;

        return head;
    }
    public ListNode doubleIt(ListNode head) {

        head = reverseList(head);

        ListNode ans = new ListNode(0);
        ListNode curr = ans;
        ListNode it = head;

        int carry = 0;

        while(it!=null){
            int val = 0;
            if(it!=null){
                val += it.val;
                val += it.val;
            }

            val += carry;

            curr.next = new ListNode(val%10);
            curr = curr.next;

            carry = val/10;

            it = it.next;
        }

        if(carry!=0){
            curr.next = new ListNode(carry);
        }

        ans = ans.next;

        ans = reverseList(ans);

        return ans;
        
        
    }
}