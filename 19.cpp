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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        while (head) {
            v.push_back(head);
            head = head->next;
        }

        int s = v.size();
        int k = s - n;
        ListNode* nHead = v[0];
        ListNode* removed = v[k];
        ListNode* next = (k < s-1) ? v[k+1] : nullptr;

        if (k > 0) {
            ListNode* before =  v[k-1];
            before->next = next;
        } else {
            // Move nHead to next if removed is old head
            nHead = next;
        }
        return nHead;
    }
};

// This probably involve some sort of caching
