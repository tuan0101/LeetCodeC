class Solution {
public:
    int characterReplacement(string s, int k) {
        int map[128] = {};
        int l = 0, window = 0, mostFreq = 0;
        int res = 0;
        for(int r=0; r<s.length(); r++){
            window++;
            char c = s[r];
            map[c]++;
            mostFreq = max(mostFreq, map[c]);
            if(window-mostFreq <= k){
                res = max(res, window);
                // cout<<" window: "<< window;
                // cout<<" mostFreq: "<< mostFreq;
            }
            else{
                map[s[l]]--;
                // if(s[l] == c)
                //     mostFreq--;
                l++;
                window--;
                
            }

        }
        return res;
    }
};

// "AABABBA"        window = 6; freq=3        res = 5;         MAP[ A: 2 B: 3 ]
//   l
//       r