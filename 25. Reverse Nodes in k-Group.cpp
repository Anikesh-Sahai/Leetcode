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
    int Count(ListNode* head){
        int c=0;
        while(head!=NULL){
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length=Count(head);
        if(length<k){
            return head;
        }
        ListNode* c=head;
        ListNode* p=NULL;
        ListNode* n=NULL;
        int l=0;
        while(c!=NULL && l<k){
            l++;
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        head->next=reverseKGroup(c,k);
        
        return p;
    }
};