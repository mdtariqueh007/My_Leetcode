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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        if(list1==NULL){
            return list2;
        }

        if(list2==NULL){
            return list1;
        }

        ListNode* curr = list1;
        ListNode* aNode = curr;
        ListNode* bNode = curr;

        int i = 1;

        while(curr!=NULL){
            if(i==a){
                aNode = curr;
            }
            else if(i==b+1){
                bNode = curr;
                break;
            }
            i++;
            curr = curr->next;
        }

        aNode->next = list2;
        curr = list2;

        while(curr->next!=NULL){
            curr = curr->next;
        }

        curr->next = bNode->next;
        bNode->next = NULL;

        return list1;
        
    }
};