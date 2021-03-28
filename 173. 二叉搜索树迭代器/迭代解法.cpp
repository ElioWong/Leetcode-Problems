#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class BSTIterator {
private:
    vector<int> nums;
    int currIndex;
public:
    BSTIterator(TreeNode* root) {
        currIndex = 0;
        nums.push_back(0);
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
            if(p != nullptr){
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top();
                s.pop();
                nums.push_back(p->val);
                p = p->right;
            }
        }
        nums[0] = nums[1] - 1;
    }
    
    int next() {
        return nums[++currIndex];
    }
    
    bool hasNext() {
        return (currIndex + 1) < nums.size() ? true : false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */