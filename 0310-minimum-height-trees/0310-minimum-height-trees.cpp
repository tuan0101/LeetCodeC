class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        
        vector<vector<int>> adj(n);
        vector<int> degrees(n, 0);
        vector<int> result;
        
        // build adjacent list
        for(int i=0; i<n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }
        
        // get leaf nodes
        queue<int> q;
        for(int i=0; i<n; i++){
            if(degrees[i]==1)
                q.push(i);
        }
        
        // BFS
        while(!q.empty()){
            int qSize = q.size();
            result.clear();
            for(int i=0; i<qSize; i++){
                int node = q.front(); q.pop();
                result.push_back(node);
                
                for(auto& neighbor : adj[node]){
                    degrees[neighbor]--;
                                        
                    if(degrees[neighbor]==1)
                        q.push(neighbor);
                }                                
            }
        }
        return result;
    }
};
// root = 0;

// myMap        currHeigt=1; visited[1, 0], minHeight = 2
// 1 : [0,2,3]
// 0 : [1]
// 2 : [1]
// 3 : [1]

