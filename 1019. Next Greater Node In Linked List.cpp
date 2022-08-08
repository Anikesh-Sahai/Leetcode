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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> storell;
        if(head->next==NULL){
            storell={0};
            return storell;
        }
        while(head){
            storell.push_back(head->val);
            head=head->next;
        }
        vector<int> v;
        stack<int> s;
        for(int i=storell.size()-1;i>=0;i--){
            if(s.empty()){
                v.push_back(0);
                s.push(storell[i]);
            }
            else{
                if(s.top()>storell[i]){
                    v.push_back(s.top());
                    s.push(storell[i]);
                }
                else{
                    while(s.size()>0 && s.top()<=storell[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        v.push_back(0);
                        s.push(storell[i]);
                    }
                    else{
                        v.push_back(s.top());
                        s.push(storell[i]);
                    }
                }
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};