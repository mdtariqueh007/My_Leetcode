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
    void reorderList(ListNode* head) {

        if(head->next==NULL){
            return;
        }

        unordered_map<ListNode*, ListNode*> mp;
        unordered_map<ListNode*, int> ind;

        ListNode* curr = head;
        ListNode* front = head->next;
        ListNode* last = head->next;
        ListNode* prev = head;

        mp[head ] = NULL;
        int i = 0;
        ind[head] = i++;

        while(last->next!=NULL){
            mp[last] = prev;
            ind[last] = i++;
            prev = prev->next;
            last = last->next;

        }

        mp[last] = prev;
        ind[last]++;

        while(curr!=NULL && last!=NULL && ind[curr]<ind[last]){
            curr->next = last;
            last->next = front;
            last = mp[last];
            curr = front;
            front = curr->next;
        }

        curr->next = NULL;
        
    }
};