class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_ind = 0;
        int t_ind = 0;
        
        while(s_ind < s.size() && t_ind < t.size())
        {
            if(s[s_ind] == t[t_ind])
                s_ind++;
            
            t_ind++;
        }

        return s_ind == s.size();
    }
};