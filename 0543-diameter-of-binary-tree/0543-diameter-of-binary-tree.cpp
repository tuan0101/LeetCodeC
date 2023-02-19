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
    int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        
        return d;
    }
    
    int getHeight(TreeNode* root){
        if(root==NULL) return 0;
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        d = max(d, left + right); // left+right is the diameter of the current node
        
        return max(left, right) + 1;
    }
};