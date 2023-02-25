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
    vector<vector<int>> levelOrder(TreeNode* root) {        
        vector<vector<int>> result;
        if(root==NULL) return result;
        
        queue<TreeNode*> myQueue;
        
        myQueue.push(root);
        while(!myQueue.empty()){
            int currentSize = myQueue.size();
            vector<int> currentLevel;
            for(int i=0; i<currentSize; i++){
                TreeNode* node = myQueue.front();
                myQueue.pop();
                
                if(node->left) myQueue.push(node->left);
                if(node->right) myQueue.push(node->right);
                
                currentLevel.push_back(node->val);
            }
            result.push_back(currentLevel);                        
        }
        return result;      
    }
};

// Add current nodes to Queue
// for each level
// pop all nodes in queue
// save all childen nodes in queue (all nodes from next level)