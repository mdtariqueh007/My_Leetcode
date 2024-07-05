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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = head->next;

        vector<int> critical;

        int ind = 0;

        while(curr!=NULL){
            if(prev!=NULL && next!=NULL){
                if((curr->val<next->val && curr->val<prev->val) || (curr->val>next->val && curr->val>prev->val)){
                    critical.push_back(ind);
                }
            }

            ind++;
            prev = curr;
            curr = next;
            if(next!=NULL)
                next = next->next;
        }

        int maxi = 0, mini = 1e9;

        if(critical.size()<2){
            return {-1,-1};
        }

        maxi = critical.back() - critical[0];

        for(int i = 1;i<critical.size();i++){
            
            mini = min(mini, critical[i] - critical[i-1]);
        }

        return {mini,maxi};
    }
};