#include <iostream>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
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
    void TreeTranversal(TreeNode* root, vector<int> & res){
        if(root->left != nullptr) TreeTranversal(root->left, res);
        res.push_back(root->val);
        if(root->right != nullptr) TreeTranversal(root->right, res);
    }
    vector<int> build(TreeNode* root){
        vector<int> res;
        TreeTranversal(root, res);
        return res;
    }
public:
    BSTIterator(TreeNode* root):currIndex(0),nums(build(root)){}
    
    int next() {
        return nums[currIndex++];
    }
    
    bool hasNext() {
        return currIndex < nums.size() ? true : false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */