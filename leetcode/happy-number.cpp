class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cache;
        
        while(cache.count(n) == 0)
        {
            cache.insert(n);
            int sum = 0;

            while(n)
            {
                sum += pow(n % 10, 2);
                n/=10;
            }

            if(sum == 1)
                return true;

            n = sum;
        }

        return false;
    }
};