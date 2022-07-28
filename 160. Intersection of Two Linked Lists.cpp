/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA){
            ListNode* t = headB;
            while(t){
                if(headA==t){
                    return t;
                }
                else{
                    t=t->next;
                }
            }
            headA=headA->next;
        }
        return NULL;
    }
};