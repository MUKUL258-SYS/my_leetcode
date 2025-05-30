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
        unordered_map<ListNode*,int>mp;
        ListNode* temp=headA;
        while(temp){
            mp[temp]++;
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            if(mp[temp]>0)return temp;
            temp=temp->next;
        }
        return NULL;
    }
};