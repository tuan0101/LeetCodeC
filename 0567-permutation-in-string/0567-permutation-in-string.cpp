class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map1[26] = {};
        int map2[26] = {};
        int l=0, s1_size = s1.size(), s2_size = s2.size();
        int res, matches = 0;

        if(s1_size > s2_size) return false;
        
        // first window
        for(int i=0; i<s1_size; i++){
            map1[s1[i]-'a']++;
            map2[s2[i]-'a']++;
        }

        for(int i=0; i<26; i++){
            if(map1[i] == map2[i])
                matches++;
        }

        if(matches==26) return true;

        for(int r=s1_size; r<s2_size; r++){
            int cur = s2[l]-'a';
            map2[cur]--;
            if(map2[cur] == map1[cur])             
                matches++;
            else if(map2[cur]+1 == map1[cur])
                matches--;
            l++;

            cur = s2[r]-'a';
            map2[cur]++;
            if(map2[cur] == map1[cur])
                matches++;                
            else if(map2[cur]-1 == map1[cur])
                matches--;
            
            
            if(matches == 26) return true;

        }

        return false;

    }
};

// matches: 22
// s1 count            s2 count
// a: 1                e:1
// b: 1                i:1

// eidbaooo
//  l
//   r