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
        ListNode* i = head;
        ListNode* j = head;
        while (i && j && j->next) {
            i = i->next;
            j = j->next->next;
            if (j == i) return true;
        }
        return false;
    }
};

// Oh wait i, j can be widely apart
