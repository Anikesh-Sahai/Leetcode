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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL){return head;}
        int c=0;
        ListNode* t=head;
        while(t!=NULL){
            c++;
            t=t->next;
        }
        c=c/2;
        for(int i=0; i<c-1;i++){
            head=head->next;
        }
        return head->next;
    }
};