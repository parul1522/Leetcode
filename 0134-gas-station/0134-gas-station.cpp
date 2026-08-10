class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int g = 0, c = 0, idx = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            g += gas[i];
            c += cost[i];
            res += gas[i] - cost[i];
            if (res < 0) {
                idx = i + 1;
                res = 0;
            }
        }
        return g < c ? -1 : idx;
    }
};