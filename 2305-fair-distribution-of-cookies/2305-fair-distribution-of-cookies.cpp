class Solution {
public:
    int dfs(int i, vector<int>& distribute, vector<int>& cookies, int k,
            int zero) {
        if (cookies.size() - i < zero) {
            return INT_MAX;
        }
        if (i == cookies.size()) {
            return *max_element(distribute.begin(), distribute.end());
        }
        int ans = INT_MAX;
        for (int j = 0; j < k; ++j) {
            zero -= distribute[j] == 0 ? 1 : 0;
            distribute[j] += cookies[i];
            ans = min(ans, dfs(i + 1, distribute, cookies, k, zero));
            distribute[j] -= cookies[i];
            zero += distribute[j] == 0 ? 1 : 0;
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribute(k, 0);
        return dfs(0, distribute, cookies, k, k);
    }
};