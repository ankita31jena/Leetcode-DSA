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
        if(head==NULL || head->next==NULL) return NULL;
        int count=0;
        ListNode* temp=head;

        while(temp!=NULL){
            count++;
            temp=temp->next;
        }

        int res=count/2;
        res--;
        temp=head;
        while(res!=0){
            res--;
            temp=temp->next;
        }

        ListNode* nextNode=temp->next;
        temp->next=temp->next->next;
        delete(nextNode);
        
        return head;      
    }
};