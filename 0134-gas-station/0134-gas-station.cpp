class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int idx = 0;
        int g = 0, c = 0;
        int ges = 0;
        for (int i = 0; i < n; i++) {
            g += gas[i];
            c += cost[i];
            ges += gas[i] - cost[i];
            if (ges < 0) {
                idx=i+1;
                ges = 0;
            }
        }

        return g < c ? -1 : idx;
    }
};