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
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode* p= head;
        while(p->next!=p && p->next!=NULL){
            ListNode* k=p;
            ListNode* t=p->next;
            ListNode* a=p->next;
            while(t->next!=NULL){
                t=t->next;
                k=k->next;
            }
            k->next=NULL;
            p->next=t;
            t->next=a;
            p=a;
        }
        p->next=NULL;
        
    }
};