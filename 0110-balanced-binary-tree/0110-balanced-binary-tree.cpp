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
    bool isBalanced(TreeNode* root) {
        if (root==NULL) return true;
        
        return (GetHeight(root) != -1); //O(N)

        // this cost O(N^2) bc isBalanced() is called on every node
        //return (abs(left-right) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
    
    int GetHeight(TreeNode* root){
        if (root==NULL) return 0;
        
        int left = GetHeight(root->left);
        if (left==-1) return -1;
        int right =  GetHeight(root->right);
        if (right==-1) return -1;
        
        if(abs(left-right)>1)
             return -1;        
        return max(left, right) + 1;
    }
};

// left Height, right Height
// gap > 1 => not a balanced tree