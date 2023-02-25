/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // BFS 67% 87%
//         if (!node) return NULL;
//         queue<Node*> q;
//         q.push(node);
                
//         unordered_map<Node*, Node*> copies;
//         copies[node] = new Node(node->val);
        
//         Node* current;
        
//         while(!q.empty()){
//             current = q.front();
//             q.pop();            
//             for(Node* neighbor : current->neighbors){               
//                 if(copies.count(neighbor)==0){
//                     copies[neighbor] = new Node(neighbor->val);
//                     q.push(neighbor);                    
//                 }
//                 copies[current]->neighbors.push_back(copies[neighbor]);
//             }            
//         }
//         return copies[node];
        
        // DFS: 67% 53%
        if (!node) return NULL;
        return dfs_clone(node);        
    }
private:
    unordered_map<Node*, Node*> copies;
    Node* dfs_clone(Node* node){       
        if (copies.count(node)==0){
            copies[node] = new Node(node->val);
            for(Node* neighbor : node->neighbors){
                copies[node]->neighbors.push_back(dfs_clone(neighbor));
            }
        }
        return copies[node];   
    }
};