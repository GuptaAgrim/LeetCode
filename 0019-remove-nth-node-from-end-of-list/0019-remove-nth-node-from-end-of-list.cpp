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
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move fast n steps ahead
        for(int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        
        // If fast is nullptr, the head needs to be removed
        if (fast == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        // Move both fast and slow until fast reaches the end
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the nth node from the end
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        
        return head;
    }
};
