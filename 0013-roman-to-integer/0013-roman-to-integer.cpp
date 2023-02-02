class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> myMap{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        char checker='a';
        int result = 0;
        for(int i=0; i <s.size(); i++){
            // check of exception
            if(myMap[s[i]] < myMap[s[i+1]]){
                result -= myMap[s[i]];
            }else{
                result += myMap[s[i]];
            }

        }
        return result;
    }
};

// important note: Roman are written largest to smallest from left to right
// => if left < right => falls into 6 instances exception

// IV
// 1, 5 => 5-1
// LIV => 50 + 4 = 50 + 5 - 1