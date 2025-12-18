class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        unordered_map<char, string> pattern_map;
        unordered_set<string> visited;
        int index = 0;

        while (iss >> word) {
            words.push_back(word);
            char letter = pattern[index];
            if(pattern_map.contains(letter)) {
                if(pattern_map[letter] != word)
                    return false;
            } else {
                if(visited.count(word))
                    return false;
                pattern_map[letter] = word;
                visited.insert(word);
            }
            index++;
        }

        return words.size() == pattern.size();
    }
};