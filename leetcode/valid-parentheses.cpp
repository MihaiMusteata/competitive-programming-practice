class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> open_close = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        stack<char> parentheses;

        for (int i = 0; i < s.length(); i++) {
            if (!parentheses.empty() && open_close[parentheses.top()] == s[i]) {
                parentheses.pop();
                continue;
            }
            parentheses.push(s[i]);
        }

        return parentheses.empty();
    }
};