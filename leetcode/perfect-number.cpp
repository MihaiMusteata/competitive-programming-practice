class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int d = 1; d * d <= num; d++) {
            if(num % d == 0) {
                sum += d;

                if(d * d < num)
                    sum += num / d;
            }
        }

        return (sum - num) == num;
    }
};