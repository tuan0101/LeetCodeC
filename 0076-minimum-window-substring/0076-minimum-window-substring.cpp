class Solution {
public:
    string minWindow(string s, string t) {
        int map[128] = {}; // count each char in t string
        int cur=0, req = t.length(), counter = t.length();
        int l = 0,head=0, curLen = 0, minLen = INT_MAX;

        for (char &c : t){
            map[c]++;
        }

        for (int i=0; i<s.length(); i++){
            char c = s[i];
            if(map[c] > 0){
                cur++;                          
            }
            map[c]--; 

            while (cur == req){             //. end : i, d : min, begin : l
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
        //  vector<int> map(128,0);
        // for (char c : t) {
        //     map[c]++;
        // }

        // int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        // while (end < s.size()){
        //     if (map[s[end++]]-- > 0) {
        //         counter--;
        //     }

        //     map[s[end]]--;
        //     end++;

        //     while (counter == 0) {
        //         if (end - begin < d) {
        //             head = begin;
        //             d = end - head;
        //         }
        //         if (map[s[begin++]]++ == 0) {
        //             counter++;
        //         }
        //     }  
        // }
        // return d == INT_MAX ? "" : s.substr(head, d);
    }
};


//"ADOBECODEBANC" t = "ABC"
