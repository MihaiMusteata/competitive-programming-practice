class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueToIndex;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (valueToIndex.count(complement)) {
                return {valueToIndex[complement], i};
            }
            valueToIndex[nums[i]] = i;
        }
        
        return {};
    }
};
