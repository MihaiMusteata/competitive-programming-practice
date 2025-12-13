class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanNumbers = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(romanNumbers[s[i]] < romanNumbers[s[i+1]])
            {
                result += romanNumbers[s[i+1]] - romanNumbers[s[i]];
                i++;
            }
            else
            {
                result += romanNumbers[s[i]];
            }
        }

        return result;
    }
};