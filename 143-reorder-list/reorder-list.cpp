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

        stack<ListNode*> st;

        ListNode* curr = head;

        while(curr){
            st.push(curr);
            curr = curr->next;
        }

        int k = st.size()/2;
        curr = head;

        while(k--){
            ListNode* temp = curr->next;
            ListNode* topNode = st.top();
            st.pop();
            curr->next = topNode;
            topNode->next = temp;
            curr = temp;
        }

        curr->next = NULL;
        
    }
};