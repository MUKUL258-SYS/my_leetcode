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
     ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(!(head->next))return NULL;
        while(true){
            if(!slow||!fast||!(fast->next))break;
            slow=slow->next;
            fast=fast->next->next;
        }
      //  if(slow)cout<<(slow->val)<<endl;
        ListNode* temp=head;
        while(temp && (temp->next!=slow)){
            temp=temp->next;
        }
        if(temp->next){
            temp->next=temp->next->next;
        }
        else if(temp){
            temp->next=NULL;
        }
        return head;
      //  return slow;
    }
};