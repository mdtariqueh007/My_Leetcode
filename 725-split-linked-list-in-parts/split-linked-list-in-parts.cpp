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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> ans(k,NULL);
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        int n = len/k;
        int extras = len%k;

        temp = head;
        ListNode* prev = NULL;
        for(int i = 0;temp!=NULL && i<k;i++,extras--){
            ans[i] = temp;
            for(int j = 0;j<n + (extras>0);j++){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
        }

        return ans;
        
    }
};