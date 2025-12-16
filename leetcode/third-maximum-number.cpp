class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        if(s.size() < 3)
            return *--s.end();

        return *prev(s.end(),3);
    }
};