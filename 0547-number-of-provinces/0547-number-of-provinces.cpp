
// class DisjointSet{
// private:
//     vector<int> root;
//     vector<int> rank;
//     int count;
// public:
//     DisjointSet(int sz):root(sz), rank(sz), count(sz){
//         for(int i=0; i<sz; i++){
//             root[i] = i;
//             rank[i] = i;
//         }        
//     }
    
//     int find(int x){
//         if(root[x] == x)
//             return x;
//         return root[x] = find(root[x]);
//     }
    
//     void unionSet(int x, int y){
//         int xroot = find(x);
//         int yroot = find(y);
        
//         if(xroot == yroot) return;
        
//         if(rank[xroot] > rank[yroot]){
//             root[yroot] = xroot;
//         }else if(rank[xroot] < rank[yroot]){
//             root[xroot] = yroot;
//         }else{
//             root[yroot] = xroot;
//             rank[xroot]++;
//         }
//         count--;
//     }
    
//     int getCount(){
//         return count;
//     }
// };

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // 30-73% 60-77%
//         int n = isConnected.size();
//         DisjointSet ds(n);
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(isConnected[i][j]==1)
//                     ds.unionSet(i, j);
//             }
//         }
        
//         return ds.getCount();
        
        // 55% 90%
        int n = isConnected.size();
        int result=0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){           
            if(!visited[i]){
                dfs(isConnected, visited, i);
                result++;
            }
        }
        return result;
    }
    
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i){
        visited[i] = true;
        
        for(int j=0; j<M.size(); j++){
            if(M[i][j]==1 && !visited[j] && i!=j)
                dfs(M, visited, j);
        }
        
    }
};

