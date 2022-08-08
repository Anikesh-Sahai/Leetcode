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
    ListNode* swapNodes(ListNode* head, int k) {
        int count=0;
        int a;
        ListNode* t=head;
        while(t!=NULL){
            count++;
            t=t->next;
        }
        a=count-(k-1);
       if(head==NULL || head->next==NULL){
           return head;
       }
       else{
           ListNode* f = head;
           ListNode* b = head;
           for(int i=0;i<k-1;i++){
               f=f->next;
           }
           for(int i=0;i<a-1;i++){
               b=b->next;
           }
           int t;
           t=f->val;
           f->val=b->val;
           b->val=t;
           return head;
       } 
    }
};