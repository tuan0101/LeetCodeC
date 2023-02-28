class Solution {
public:
        
    unordered_map<int, vector<int>> M;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses);
        
        for(vector<int> pre : prerequisites){
            M[pre[0]].push_back(pre[1]);
        }
        
        // check if each course can be completed
        for(int course=0; course<numCourses; course++){
            if (!canComplete(course, visited))
                return false;
        }
        return true;
    }
    
    // DFS for each pre in a course
    bool canComplete(int course, vector<bool> visited){
        if(visited[course]) return false;
        else visited[course] = true;  // from undefined to true
        
        if(M[course].size() == 0) return true;
        for(int &pre : M[course]){
            if (!canComplete(pre, visited))
                return false;               
        }
        visited[course] = false;
        M[course].clear(); // mark as canComplete
        return true;
    }
};