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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        ListNode* temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        if(v.size()<3)return {-1,-1};
        vector<int>v1,v2;
        for(int i=1;i+1<v.size();i++){
            if(v[i]>v[i-1]&&v[i]>v[i+1])v1.push_back(i);
            else if(v[i]<v[i+1]&&v[i]<v[i-1])v1.push_back(i);
        }
        int mini=INT_MAX;
        if(v1.size()<2)return {-1,-1};
        for(int i=1;i<v1.size();i++){
            mini=min(mini,v1[i]-v1[i-1]);
        }
        return {mini,v1.back()-v1[0]};
    }
};