class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        int original_x = x;
        long long int reverse_x = 0;

        while(x)
        {
            reverse_x = (reverse_x * 10) + (x % 10);
            x /= 10;
        }

        return original_x == reverse_x;
    }
};