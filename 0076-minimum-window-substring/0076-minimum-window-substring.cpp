class Solution {
public:
    string minWindow(string s, string t) {
        int map[128] = {}; // count each char in t string
        int cur=0, req = t.length();
        int l=0, head=0, curLen=0, minLen = INT_MAX;

        for (char &c : t){
            map[c]++;
        }

        for (int i=0; i<s.length(); i++){
            // 1. Update cur( what we have in the current WINDOW)
            // 2. Decrement each Char count in the MAP
            char c = s[i];
            if(map[c] > 0){
                cur++;                          
            }
            map[c]--; 
            // While met the requirement
            // 3. update the minimum length, save the left pointer

            // start removing unnecessary prefix
            // 4. check if the left pointer is the character in the T string
            // 5. update cur if it is
            // 6. increase each left character in the map as visit
            while (cur == req){             
               curLen = i-l  + 1;
               if(curLen < minLen){
                   minLen = curLen;
                   head = l;
               }
               if(map[s[l]] == 0){                  
                   cur--;                
               }
               map[s[l]]++;
               l++;               
            }
        }
        return minLen == INT_MAX? "" : s.substr(head, minLen);
    }
};


//"ADOBECODEBANC" t = "ABC"
