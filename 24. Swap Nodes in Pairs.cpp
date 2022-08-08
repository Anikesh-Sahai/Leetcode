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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* t=head;
        ListNode* p=head->next;
        
        t->next=p->next;
        p->next=t;
        head=p;
        t=t->next;
        p=p->next;
        
        while(t!=NULL && t->next!=NULL){
            ListNode* k=t->next;
            t->next=k->next;
            k->next=t;
            p->next=k;
            t=t->next;
            p=p->next->next;
        }
        
       return head; 
    }
};