class Solution {
public:
    int longestPalindrome(string s) {
        int longestPal=0;
        int myArray[58] = {}; // 'A'=65, 'z'=122, 122-65+1
        
        for (char &c : s){
            myArray[c-'A']++;
            if(myArray[c-'A']%2 == 0)
                longestPal += 2;
        }
        for (char &c : s){
            if(myArray[c-'A']%2 != 0){
                longestPal ++;
                break;
            }
                
            
        }
        return longestPal;
    }
};


// compare left and right
// == : increment
// reset to 0 and start again