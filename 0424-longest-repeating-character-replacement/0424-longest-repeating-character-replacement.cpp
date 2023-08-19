class Solution {
public:
    int characterReplacement(string s, int k) {
        int map[128] = {};
        int l = 0, window = 0, mostFreq = 0;
        int res = 0;
        for(int r=0; r<s.length(); r++){
            window++;
            char c = s[r];
            map[c]++;          // either use map[128] or map[32] with map[c-'A']
            mostFreq = max(mostFreq, map[c]);
            if(window-mostFreq <= k){
                res = max(res, window);
            }
            else{
                map[s[l]]--;
                l++;
                window--;
                // if we remove the leftmost char that happen to be the most frequency char
                // we do not need to update it, because we want the max window which will require the max freq
            }
        }
        return res;
    }
};

// "AABABBA"        window = 6; freq=3        res = 5;         MAP[ A: 2 B: 3 ]
//   l
//       r