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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head;
        // If its empty
        if (!current) return head;
        ListNode *next = head->next;
        while (next) {
            if (current->val == next->val) {
                current->next = next->next;
            } else {
                current = current->next;
            }
            next = next->next;
        }
        return head;
    }
};

// We can do this one loop over each node and check for all of them
