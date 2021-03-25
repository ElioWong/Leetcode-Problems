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
     if(head == nullptr) return nullptr;
    ListNode* exHead = new ListNode(-200);
    int tmpVal;
    exHead->next = head;
    ListNode* curr = exHead;
    while(curr->next != nullptr && curr->next->next != nullptr){
        if(curr->next->val == curr->next->next->val){
            tmpVal = curr->next->val;
            for(curr = curr->next; curr->next->val != tmpVal; curr = curr->next){
                Delete(curr->next, curr->next->next);
                curr->next->next = 
            }
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

