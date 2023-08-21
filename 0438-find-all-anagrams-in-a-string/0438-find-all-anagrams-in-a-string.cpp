class Solution {
public:
    unordered_map<char, int> myMap;
    vector<int> findAnagrams(string s, string p) {
        // O(N * 26)
        vector<int> result;
        vector<int> pCount(26,0);
        vector<int> window(26,0);     
        int pSize = p.size(), sSize = s.size(), start;

        if(pSize > sSize)
            return result;
        // first window
        for(int i=0; i<pSize; i++){
            pCount[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(pCount == window) 
            result.push_back(0);
        
        int left, right;
        for(int i=pSize; i<sSize; i++){
            start = i-pSize;
            left = s[start]-'a'; // s[i-p.size()] return left char
            window[left]--;           // window[left] : occurence for the left char
            
            right = s[i] - 'a';
            window[right]++;
            
            if(pCount == window) 
                result.push_back(start+1);
        }
        return result;
    }
    

};

// p =""cbaebabacd"" 123
// s = "cbcab" n*m
// bae