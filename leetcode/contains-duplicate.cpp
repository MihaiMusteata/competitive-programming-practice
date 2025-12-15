class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> distinct;

        for(auto num : nums) {
            if(distinct.find(num) != distinct.end())
                return true;
            
            distinct.insert(num);
        }

        return false;
    }
};