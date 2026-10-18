class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int cnt=INT_MAX;
        int l=0,r=0;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                cnt=min(cnt,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return cnt==INT_MAX?0:cnt;
    }
};