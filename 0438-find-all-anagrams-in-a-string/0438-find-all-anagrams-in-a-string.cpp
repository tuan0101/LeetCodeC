class Solution {
public:
    unordered_map<char, int> myMap;
    vector<int> findAnagrams(string s, string p) {
        // O(N * 26)
        vector<int> result;
        vector<int> pCount(26,0);
        vector<int> window(26,0);
        
        if(p.size() > s.size())
            return result;
        // first window
        for(int i=0; i<p.size(); i++){
            pCount[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(pCount == window) 
            result.push_back(0);
        
        int left, right;
        for(int i=p.size(); i<s.size(); i++){
            left = s[i-p.size()]-'a';
            window[left]--;
            
            right = s[i] - 'a';
            window[right]++;
            
            if(pCount == window) 
                result.push_back(i-p.size()+1);
        }
        return result;
    }
    

};

// p =""cbaebabacd"" 123
// s = "cbcab" n*m
// bae