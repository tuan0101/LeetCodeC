class DisjointSet{
private:
    vector<int> root;
    vector<int> rank;
    int count;
public:
    DisjointSet(int sz):root(sz), rank(sz), count(sz){
        for(int i=0; i<sz; i++){
            root[i] = i;
            rank[i] = i;
        }        
    }
    
    int find(int x){
        if(root[x] == x)
            return x;
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y){
        int xroot = find(x);
        int yroot = find(y);
        
        if(xroot == yroot) return;
        
        if(rank[xroot] > rank[yroot]){
            root[yroot] = xroot;
        }else if(rank[xroot] < rank[yroot]){
            root[xroot] = yroot;
        }else{
            root[yroot] = xroot;
            rank[xroot]++;
        }
        count--;
    }
    
    int getCount(){
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1)
                    ds.unionSet(i, j);
            }
        }
        
        return ds.getCount();
    }
};

