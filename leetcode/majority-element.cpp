class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto it : nums){
            if(freq.contains(it))
                freq[it]++;
            else 
                freq[it] = 1;

            if(freq[it] > nums.size() / 2)
                return it;
        }

        return 0;
    }
};