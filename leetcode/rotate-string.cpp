class Solution {
public:
    bool rotateString(string s, string goal) {
        string str = s;
        for(int i = 0; i < goal.size(); i++)
        {
            if(str == goal)
                return true;
            
            str = str.substr(1, str.size()) + str[0];
        }        

        return false;
    }
};