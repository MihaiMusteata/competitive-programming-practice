class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_indices;

        for(int i = 0; i < nums.size(); i++)
        {
            if(num_indices.contains(nums[i]) && abs(num_indices[nums[i]] - i) <= k)
                return true;
            
            num_indices[nums[i]] = i;
        }

        return false;
    }
};