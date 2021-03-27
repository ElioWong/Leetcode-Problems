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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* newTail, * tail;
        ListNode* curr;
        int count = 0;
        int len;
        for(curr = dummy; curr->next != nullptr; curr = curr->next)
            count++;
        len = count;
        count = 0;
        if(k % len == 0) return head;
        for(curr = dummy; curr->next != nullptr; curr = curr->next){
            if(count == len - (k % len)) newTail = curr; 
            count++;
        }
        tail = curr;
        tail->next = head;
        dummy->next = newTail->next;
        newTail->next = nullptr;
        return dummy->next;
    }
};