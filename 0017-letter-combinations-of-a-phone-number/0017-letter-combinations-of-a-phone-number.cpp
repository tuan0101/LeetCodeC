class Solution { 
public:
    vector<string> letterCombinations(string digits) {
        //
        if(digits.size()==0) return {};
        vector<string> letterMap = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        result.push_back("");
        for(char digit : digits){
            vector<string> tmp;
            for(char candidate : letterMap[digit - '0'])
                for(string s : result)
                    tmp.push_back(s + candidate);
            result.swap(tmp);
        }
        return result;
    }
};