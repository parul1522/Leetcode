class Solution {
public:
    bool isMatch(string s, string p) {
        int a = s.size();
        int b = p.size();
        int star = -1, match = 0;
        int l = 0, r = 0;
        while (l < a) {
            if (r < b && (s[l] == p[r] || p[r] == '?')) {
                l++;
                r++;
            } else if (r < b && p[r] == '*') {
                star = r;
                match = l;
                r++;
            } else if (star != -1) {
                r = star + 1;
                match++;
                l = match;
            } else {
                return false;
            }
        }
        while(r<b&&p[r]=='*'){
            r++;
        }
        return r==b;
    }
};