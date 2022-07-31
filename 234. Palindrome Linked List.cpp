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
    ListNode* reverse(ListNode* head){
        if(head->next==NULL){
            return head;
        }
        else{
            ListNode* p=reverse(head->next);
            ListNode* q=head->next;
            q->next=head;
            head->next=NULL;
            return p;
        }
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* t=reverse(slow->next);
        slow->next=NULL;
        while(head && t){
        if(head->val==t->val){
            head=head->next;
            t=t->next;
        }
        else{return false;}
        }
        return true;
    }
};