/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        stack<TreeNode*> myStack;
        
        TreeNode* pre = NULL;
        while(root || !myStack.empty()){
            while(root){
                myStack.push(root);
                root = root->left;
            }
            root = myStack.top(); myStack.pop();
            if(pre && pre->val >= root->val) return false;
            
            pre = root;
            root = root->right;
        }
        return true;
    }
};