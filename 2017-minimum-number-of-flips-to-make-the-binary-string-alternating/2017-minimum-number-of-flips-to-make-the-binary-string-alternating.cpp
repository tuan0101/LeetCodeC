class Solution {
public:
    int minFlips(string s) {
        // from O(N) - > O(1) space
        // int n = s.size();
        // int l=0, diff1=0, diff2=0;
        // int ans1, ans2, idx;
        // int res = n + 1;

        // for(int r=0; r<2*n; r++){
        //     if(r < n) s[r] -= '0'; // convert to integer 0 or 1
        //     ans1 = r % 2;
        //     ans2 = (r+1) % 2;
        //     idx = r % n;
        //     if(s[idx] != ans1) diff1++;
        //     if(s[idx] != ans2) diff2++;

        //     if(r >= n){
        //         if(l % 2 != s[l]) diff1--;
        //         if((l+1) % 2 != s[l]) diff2--;
        //         l++;
        //     }

        //     if(r-l+1 == n)
        //         res = min({res, diff1, diff2});
        // }
        // return res;
        // O(N) space
        int n = s.size();
        s += s;
        int len = s.size();       
        string alt1, alt2;
        int l=0, diff1=0, diff2=0, res=len;

        for(int i=0; i<len; i++){
            alt1 += i%2? '0' : '1';
            alt2 += i%2? '1' : '0';
        }

        for(int r=0; r<len; r++){
            if(s[r] != alt1[r])
                diff1++;
            if(s[r] != alt2[r])
                diff2++;

            if(r-l+1 > n){  // or r>=n
                if(s[l] != alt1[l])
                    diff1--;
                if(s[l] != alt2[l])
                    diff2--;                  
                l++;
            }

            if(r-l+1 == n){     // or r+1>=n
                res = min({res, diff1, diff2});  // add {} for more than 2 nums
            }

        }
        return res;
        
    }
};



// 111000111000
// 010101010101    alt1
// 101010101010    alt2