class Solution {
public:
    string convertToBase7(int num) {
        int n = abs(num);
        string ans;
        while(n)
        {
            ans += n % 7 + '0';
            n /= 7;
        }

        if(num < 0)
            ans += '-';

        reverse(ans.begin(), ans.end());
        return ans.size() ? ans : "0";
    }
};