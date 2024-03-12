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
    ListNode* removeZeroSumSublists(ListNode* head) {

        ListNode* dummy = new ListNode(0);

        dummy->next = head;

        unordered_map<int,ListNode*> mp;

        mp[0] = dummy;

        ListNode* curr = head;

        int pSum = 0;

        while(curr!=NULL){
            pSum += curr->val;

            if(mp.find(pSum)!=mp.end()){
                ListNode* start = mp[pSum];
                ListNode* temp = start;

                int p = pSum;

                while(temp!=curr){
                    temp = temp->next;
                    p += temp->val;

                    if(temp!=curr){
                        mp.erase(p);
                    }

                    
                }

                

                start->next = temp->next;
            }else{
                mp[pSum] = curr;
            }

            curr = curr->next;
        }


        return dummy->next;


        
    }
};