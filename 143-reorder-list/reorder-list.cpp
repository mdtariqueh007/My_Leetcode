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
    private:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode* rev = reverseList(slow);

        ListNode* curr = head;

        while(rev->next){
            ListNode* temp = curr->next;
            curr->next = rev;
            
            ListNode* temp2 = rev->next;
            rev->next = temp;

            curr = temp;
            rev = temp2;
        }

    
        
    }
};