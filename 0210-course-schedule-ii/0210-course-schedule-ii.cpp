class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> topo;
        //queue<int> q;
        
        // build graph
        for(auto& pair : prerequisites){
            // inDegree
            G[pair[1]].push_back(pair[0]); // reverse order G[pair[0]].push_back(pair[1]) -> outDegree
            inDegree[pair[0]]++;
        }
        
        for(int i=0; i<numCourses; i++)
            if(inDegree[i]==0) topo.push_back(i);
        
//         while(!q.empty()){
//             int node = q.front(); q.pop();
            
//             for(int course : G[node]){
//                 inDegree[course]--;
//                 if(inDegree[course]==0)
//                     q.push(course);
//             }
//             topo.push_back(node);
//         }
        
        //replace queue by topo
        for(int i=0; i<topo.size(); i++){
            for(int course : G[topo[i]]){
                inDegree[course]--;
                if(inDegree[course]==0)
                    topo.push_back(course);
            }
        }
        
        if (topo.size() == numCourses) 
            return topo;
        return {};
    }
};