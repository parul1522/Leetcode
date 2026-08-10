class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int l = 0, r = 0, cnt = 0;
        while (l < n && r < m) {
            if (g[l] > s[r]) {
                r++;
            } else {
                cnt++;
                r++;
                l++;
            }
            
        }
        return cnt;
    }
};