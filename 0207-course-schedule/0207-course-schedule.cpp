class Solution {
public:
    // 20% 5%    
       
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<bool> visited(numCourses);
//         vector<int> M[numCourses]; //same vector<vector<int>> M(numCourses);
        
//         for(vector<int> &pre : prerequisites){
//             M[pre[0]].push_back(pre[1]);
//         }
        
//         // check if each course can be completed
//         for(int course=0; course<numCourses; course++){
//             if (!canComplete(course, visited, M))
//                 return false;
//         }
//         return true;
//     }
    
    // DFS for each pre in a course
     // either pass vector<int> *M or vector<int> M[]
//     bool canComplete(int course, vector<bool> visited, vector<int> *M){
//         if(visited[course]) return false;
//         else visited[course] = true;  // from undefined to true
        
//         if(M[course].size() == 0) return true;
//         for(int &pre : M[course]){
//             if (!canComplete(pre, visited, M))
//                 return false;               
//         }
//         visited[course] = false;
//         M[course].clear(); // mark as canComplete
//         return true;
//     }
         
        //85% 82%
        // vector<vector<int>> G(n);
        // vector<int> degree(n, 0), bfs;
        // for (auto& e : prerequisites)
        //     G[e[1]].push_back(e[0]), degree[e[0]]++;
        // for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
        // for (int i = 0; i < bfs.size(); ++i)
        //     for (int j: G[bfs[i]])
        //         if (--degree[j] == 0) bfs.push_back(j);
        // return bfs.size() == n;
        vector<vector<int>> G(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> topo;
        queue<int> q;
        
        for(auto& pair : prerequisites){
            G[pair[0]].push_back(pair[1]);
            inDegree[pair[1]]++;
        }
        
        for(int i=0; i<numCourses; i++)
            if(inDegree[i]==0) q.push(i);
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            
            for(int course : G[node]){
                inDegree[course]--;
                if(inDegree[course]==0)
                    q.push(course);
            }
            topo.push_back(node);
        }
        return topo.size() == numCourses;
    }    
};