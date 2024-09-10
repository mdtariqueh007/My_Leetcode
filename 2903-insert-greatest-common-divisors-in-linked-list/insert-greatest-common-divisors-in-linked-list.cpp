/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
       if(head->next==NULL) return head;
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=NULL){
            slow->next = new ListNode(__gcd(slow->val,fast->val));
            slow->next->next = fast;
            slow = fast;
            fast = fast->next;
        }
        
        return head;
        
    }
};