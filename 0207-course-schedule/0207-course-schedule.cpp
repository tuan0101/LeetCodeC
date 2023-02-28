class Solution {
public:
    // 20% 5%    
//     unordered_map<int, vector<int>> M;
    
     bool canFinish(int n, vector<vector<int>>& prerequisites) {
//         vector<bool> visited(numCourses);
        
//         for(vector<int> pre : prerequisites){
//             M[pre[0]].push_back(pre[1]);
//         }
        
//         // check if each course can be completed
//         for(int course=0; course<numCourses; course++){
//             if (!canComplete(course, visited))
//                 return false;
//         }
//         return true;
//     }
    
//     // DFS for each pre in a course
//     bool canComplete(int course, vector<bool> visited){
//         if(visited[course]) return false;
//         else visited[course] = true;  // from undefined to true
        
//         if(M[course].size() == 0) return true;
//         for(int &pre : M[course]){
//             if (!canComplete(pre, visited))
//                 return false;               
//         }
//         visited[course] = false;
//         M[course].clear(); // mark as canComplete
//         return true;
//     }
        vector<vector<int>> G(n);
        vector<int> degree(n, 0), bfs;
        for (auto& e : prerequisites)
            G[e[1]].push_back(e[0]), degree[e[0]]++;
        for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        return bfs.size() == n;
     }

};