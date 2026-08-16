class Solution {
public:
    void backtrack(int start, vector<int>& ans, vector<vector<int>>& res, int n,
                   int k) {
        if (ans.size() == k)
            res.push_back(ans);
        if (start > n)
            return;
        for (int i = start; i <= n; i++) {
            ans.push_back(i);
            backtrack(i+1,ans,res,n,k);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ans;
        backtrack(1, ans, res, n, k);
        return res;
    }
};