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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp;
        ListNode* temp=head;
        while(temp!=NULL){
            if(mp.find(temp)==mp.end()){
                mp[temp]=1;
            }else{
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
};