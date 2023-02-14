/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // we can ignore these first conditions because
        // these the only exist conditions if they are not on the same side;
        // if(p->val == root->val || q->val == root->val) return root;
        // // different side
        // if(p->val > root->val && q->val < root->val ||
        //   p->val < root->val && q->val > root->val)        
        //     return root;
        
        // same side
        // both right        
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        // both left
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // now either they are on the same side
        // or one is a parent of another => return root;
        return root;
    }
};

// NOT on the same side of root => return root
// if 2 nodes on the same branch of the root
// if one is the parent of another -> return itself
