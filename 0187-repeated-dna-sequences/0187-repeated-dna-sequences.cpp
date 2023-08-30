class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector <string> res;
        unordered_map<string, int> map;

        for(int i=0; i<n-9; i++){
            string sub = s.substr(i, 10);
            map[sub]++;
            // if(map[sub]==2)
            //     res.push_back(sub);
        }

        // not included in the first for loop because it might have duplicate results
        for(auto it : map){
            if(it.second > 1)
                res.push_back(it.first);
        }

        return res;
    }
};
