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
        
        // add 0 degree to Q
        for(int i=0; i<numCourses; i++)
            if(inDegree[i]==0) topo.push_back(i);
        
        // for each current 0-degree node in TOPO
        // then for each node that connected by the current TOPO node
        // reduce its degree, then add to TOPO if reach 0-degree
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