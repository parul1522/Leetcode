class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int a=nums[n-1]-nums[0];
        int l=nums[0]+k,r=nums[n-1]-k;
        for(int i=0;i<n-1;i++){
            int maxi=max(r,nums[i]+k);
            int mini=min(l,nums[i+1]-k);
            a=min(a,maxi-mini);
        }
        return a;
    }
};