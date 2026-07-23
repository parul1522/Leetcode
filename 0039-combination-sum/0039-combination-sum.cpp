class Solution {
public:
    void comb(vector<int>& candidates, int target, int idx,
              vector<vector<int>>& ans, int tot, vector<int>& res) {
        if (tot == target) {
            ans.push_back(res);
            return;
        }
        if (tot > target || idx >= candidates.size()) {
            return;
        }
        res.push_back(candidates[idx]);
        comb(candidates, target, idx , ans, tot + candidates[idx], res);
        res.pop_back();
        comb(candidates, target, idx + 1, ans, tot, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        comb(candidates, target, 0, ans, 0, res);
        return ans;
    }
};