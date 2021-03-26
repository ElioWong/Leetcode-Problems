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
    void Delete(ListNode* prev, ListNode* curr){
        prev->next = curr->next;
        delete curr;
        curr = nullptr;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-200);
        dummy->next = head;
        for(ListNode* p = dummy, *q = p->next; q != nullptr;) {
            if(p->val == q->val) {
                Delete(p, q);
                q=p->next;
                continue;
            }
            p=p->next;
            q=q->next;
        }
        return dummy->next;
    }
};