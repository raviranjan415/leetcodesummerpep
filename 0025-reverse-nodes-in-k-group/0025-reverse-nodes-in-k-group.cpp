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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if there are at least k nodes left
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            if (!curr) return head; // Fewer than k nodes, return as is
            curr = curr->next;
        }

        // Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* tempHead = head;
        for (int i = 0; i < k; ++i) {
            next = tempHead->next;
            tempHead->next = prev;
            prev = tempHead;
            tempHead = next;
        }

        // Recursively call for the rest and connect
        if (next) head->next = reverseKGroup(next, k);

        return prev; // New head of this reversed group
    }
};