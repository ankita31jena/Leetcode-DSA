class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;
        vector<int> arr;

        while (temp != NULL) {
            arr.push_back(temp->val);
            if (temp->next == NULL)
                break;
            temp = temp->next->next;
        }

        temp = head->next;
        while (temp != NULL) {
            arr.push_back(temp->val);
            if (temp->next == NULL)
                break;
            temp = temp->next->next;
        }

        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->val = arr[i];
            temp = temp->next;
        }

        return head;
    }
};