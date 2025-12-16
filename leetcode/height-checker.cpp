class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> original = heights;
        sort(heights.begin(), heights.end());

        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] != original[i])
                ans++;
        }

        return ans;
    }
};