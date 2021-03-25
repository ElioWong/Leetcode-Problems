#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void Delete(ListNode* preNode, ListNode* currNode) {
    preNode->next = currNode->next;
    delete currNode;
    currNode = nullptr;
}
ListNode* deleteDuplicates(ListNode* head) {
     if (head == nullptr) return nullptr;
        ListNode* exHead = new ListNode(-200);
        exHead->next = head;
        vector<bool> record;
        record.resize(201, false);
        ListNode* curr, * pre;
        curr = head;
        pre = exHead;
        while (curr != nullptr) {
            if (curr->val == pre->val) 
                record[curr->val + 100] = true;
            pre = curr;
            curr = curr->next;
        }
        curr = head;
        pre = exHead;
        while (curr != nullptr) {
            if (record[curr->val + 100] == true) {
                Delete(pre, curr);
                curr = pre->next;
            }
            else {
                pre = curr;
                curr = pre->next;
            }
        }
        return exHead->next;
}

int main() {
    ListNode* p = new ListNode(1);
    ListNode* head, * curr;
    head = p;
    curr = head;
    p = new ListNode(2);
    curr->next = p;
    curr = curr->next;
    p = new ListNode(3);
    curr->next = p;
    curr = curr->next;
    p = new ListNode(3);
    curr->next = p;
    curr = curr->next;
    p = new ListNode(4);
    curr->next = p;
    curr = curr->next;
    p = new ListNode(4);
    curr->next = p;
    curr = curr->next;
    p = new ListNode(5);
    curr->next = p;
    curr = curr->next;
    head = deleteDuplicates(head);
    for (p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
}