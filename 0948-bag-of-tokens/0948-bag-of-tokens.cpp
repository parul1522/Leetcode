class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int score = 0, res = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l++];
                score = max(score, ++res);
            } else if (res > 0) {
                res--;
                power += tokens[r--];
            } else {
                break;
            }
        }
        return score;
    }
};