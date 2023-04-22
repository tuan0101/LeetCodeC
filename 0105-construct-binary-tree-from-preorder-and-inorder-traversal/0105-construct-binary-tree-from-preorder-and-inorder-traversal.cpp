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
    unordered_map<int, int> inorderToIndex;
    int current;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Time: O(N)
        // build hash_map take O(N)
        // recursive build take O(1) on each node, there are N nodes -> O(N)
        // Space: O(N)
        // worst case: O(N) average: O(logN)
        current = 0; 
        
        for(int i=0; i<inorder.size(); i++){
            inorderToIndex[inorder[i]] = i; // value of inorder -> index
        }
        
        return build(preorder, inorder, 0, preorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if (left > right) return NULL;
        int rootValue = preorder[current++];
        TreeNode* root = new TreeNode(rootValue);
        
        int rootIndex = inorderToIndex[rootValue];
        root->left = build(preorder, inorder, left, rootIndex-1);
        root->right = build(preorder, inorder, rootIndex+1, right);
        return root;
    }
};
