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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            // Find the last node and the node before the last node
            ListNode* prev = curr;
            ListNode* last = curr->next;

            while (last->next != nullptr) {
                prev = last;
                last = last->next;
            }

            // If last is already directly after curr, we are done
            if (last == curr->next) {
                break;
            }

            // Remove last node from the end
            prev->next = nullptr;

            // Insert last node after curr
            last->next = curr->next;
            curr->next = last;

            // Move curr to the next original front node
            curr = last->next;
        }
        
    }
};
