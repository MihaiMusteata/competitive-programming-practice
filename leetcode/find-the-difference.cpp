class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map <char, int> freq;

        for(int i = 0; i < t.length(); i++) {
            if(!freq.contains(t[i]))
                freq[t[i]] = 0;
            
            freq[t[i]]++;
        }

        for(int i = 0; i < s.length(); i++) {
            if(freq.contains(s[i]))
                freq[s[i]]--;

            if(freq[s[i]] == 0)
                freq.erase(s[i]);
        }

        auto it = freq.begin();
        return it->first;
    }
};