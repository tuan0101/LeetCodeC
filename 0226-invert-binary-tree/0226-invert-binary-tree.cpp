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
    TreeNode* invertTree(TreeNode* root) {
        std::stack<TreeNode*> myStack;
        myStack.push(root);
        
        while(!myStack.empty()){
            TreeNode* node = myStack.top();
            myStack.pop();
            // left and right can be NULL
            // but they will be ignore by this IF condition in the next loop;
            if(node){                         
                myStack.push(node->left);
                myStack.push(node->right);
                std:swap(node->left, node->right);  
            }
        }
        
        return root;
        
        // may cause stack overflow, bc this can become a skewed tree - linked list
        
//         if (root == NULL) return root;
//         // TreeNode* left = root->left;
//         // root->left = root->right;
//         // root->right = left;
        
//         // => swap
//         std::swap(root->left, root->right);

//         invertTree(root->left);
//         invertTree(root->right);
//         return root;
        
    }
};

// if root is null, return root;
// root-> [left, right]