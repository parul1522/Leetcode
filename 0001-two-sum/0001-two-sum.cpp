class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mapp;
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (mapp.count(complement)) {
                return {mapp[complement], i};
            }
            mapp[nums[i]] = i;
        }
        return {};
    }
};