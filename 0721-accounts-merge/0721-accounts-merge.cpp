class DisjoinSet{
private:
    vector<int> root;
    vector<int> rank;
public:
    DisjoinSet(int sz) : root(sz), rank(sz){
        for(int i=0; i<sz; i++){
            root[i] = i;
            rank[i] = 1;
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
        
        if(rank[xroot] == rank[yroot]){
            root[yroot] = xroot;
            rank[xroot]++;
        }else if(rank[xroot] < rank[yroot]){
            root[xroot] = yroot;
        }else
            root[yroot] = xroot;
    }
};
class Solution {
private:
//     unordered_set<string> visited;
//     unordered_map<string, vector<string>> graph;

//     void DFS(string& email, vector<string>& mergedAcc){
//         visited.insert(email);
//         mergedAcc.push_back(email);
//         // list of emails connected to this first email
//         for(string& neighbor : graph[email]){
//             if(visited.find(neighbor)==visited.end()){
//                 DFS(neighbor, mergedAcc);
//             }
//         }
//     }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {  
        //98% 95%
        int n = accounts.size();
        DisjoinSet ds(n);
        unordered_map<string, int> emailMap;
        
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(emailMap.find(email)==emailMap.end()){
                    emailMap[email] = i;
                }else{
                    ds.unionSet(i, emailMap[email]);
                }
            }
        }
        
        // unordered_map<int, vector<string>> mergedEmail
        // could use hash map
        vector<vector<string>> mergedEmail(n);
        for(auto& iter : emailMap){
            string email = iter.first;
            int group = ds.find(iter.second);
            if(mergedEmail[group].size() == 0){
                string name = accounts[group][0];
                mergedEmail[group].push_back(name);
            }
            mergedEmail[group].push_back(email);
        }
        
        vector<vector<string>> result;
        for(auto emailList : mergedEmail){
            if(emailList.size() == 0) continue;
            sort(emailList.begin()+1, emailList.end());
            result.push_back(emailList);
        }
        return result;
        // 40% 20%
        // build graph
//         for(auto& acc : accounts){
//             string firstEmail = acc[1];
//             for(int j=2; j<acc.size(); j++){
//                 string email = acc[j];
//                 graph[firstEmail].push_back(email);
//                 graph[email].push_back(firstEmail);
//             }
//         }
        
//         vector<vector<string>> result;
//         for(auto& acc : accounts){
//             string name = acc[0];
//             string firstEmail = acc[1];
                        
//             if(visited.find(firstEmail)!=visited.end()) // visited
//                 continue;
            
//             vector<string> mergedAcc;
//             mergedAcc.push_back(name);
//             DFS(firstEmail, mergedAcc);
//             sort(mergedAcc.begin()+1, mergedAcc.end());
//             result.push_back(mergedAcc);           
//         }
//         return result;
    }
};

// edge case example
// nameSet = {John, Mary, John}
// John: a, b, e, f
// John: c, d
// john: b, c
// => john: a, b, c, d

// graph[a] : b, e, f
// graph[b] : a, c
