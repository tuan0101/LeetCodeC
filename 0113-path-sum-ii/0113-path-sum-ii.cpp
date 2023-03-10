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
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        findPath(path, root, targetSum);
        return result;
    }

    void findPath(vector<int> &path, TreeNode* root, int sum){
        if(root==NULL) return;
        
        path.push_back(root->val);
        if(!(root->left) && !(root->right) && sum == root->val){
            result.push_back(path); 
        }

        findPath(path, root->left, sum - root->val);
        findPath(path, root->right, sum - root->val);
        path.pop_back();
    }
};