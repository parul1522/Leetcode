class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int>diff;
        int ans=0;
        for(auto cost:costs){
            ans+=cost[0];
            diff.push_back(cost[1]-cost[0]);
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<costs.size()/2;i++){
            ans+=diff[i];
        }
        return ans;
    }
};