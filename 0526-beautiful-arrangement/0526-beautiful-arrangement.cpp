class Solution {
public:
    int count = 0;
    void calculate(vector<bool>& visited, int pos, int n) {
        if (pos > n)
            count++;
        else {
            for (int i = 1; i <= n; i++) {
                if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                    visited[i] = true;
                    calculate(visited, pos + 1, n);
                    visited[i] = false;
                }
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        calculate(visited, 1, n);
        return count;
    }
};