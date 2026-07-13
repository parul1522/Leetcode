class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>mapp(256,-1);
        int l=0,r=0,maxLen=0;
        while(r<n){
            if(mapp[s[r]]!=-1){
                l=max(mapp[s[r]]+1,l);
            }
            mapp[s[r]]=r;
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};