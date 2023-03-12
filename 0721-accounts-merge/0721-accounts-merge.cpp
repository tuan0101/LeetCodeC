class Solution {
private:
    unordered_map<string, vector<string>> graph;
    unordered_set<string> visited;
    
    // DFS to collect all emails belong to this account
    void DFS(vector<string>& mergedAcc, string& email){
        visited.insert(email);        
        mergedAcc.push_back(email);
        
        for(string& neighbor : graph[email]){
            if(visited.find(neighbor)==visited.end())
                DFS(mergedAcc, neighbor);
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) { 
        for(auto& acc : accounts){
            // build graph / adjacency list
            // connect first email to every other ones
            string firstEmail = acc[1];
            for(int j=2; j<acc.size(); j++){
                string email = acc[j];
                graph[firstEmail].push_back(email);
                graph[email].push_back(firstEmail);
            }
        }
        
        vector<vector<string>> result;
        for(auto& acc : accounts){
            string name = acc[0];
            string firstEmail = acc[1];
            
            // not in visited
            if (visited.find(firstEmail)==visited.end()){
                vector<string> mergedAcc;
                mergedAcc.push_back(name);
                DFS(mergedAcc, firstEmail);
                sort(mergedAcc.begin()+1, mergedAcc.end());
                result.push_back(mergedAcc);
            }
        }
        
        return result;
        
    }
};

// nameSet = {John, Mary, John}
// John: a, b, c
// Mary: d
// John: a, e, f

// graph            visited: [a, b, c, e, f, d] merge1: [john, a, b, c, e, f] merged2: [mary, d]
// g[a] = [b, c, e, f]
// g[b] = [a]
// g[c] = [a]
// g[d] = []
// g[e] = [a]
// g[f] = [a]