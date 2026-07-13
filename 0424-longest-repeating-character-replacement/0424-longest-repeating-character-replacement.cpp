class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mapp;
        int l=0,r=0,cnt=0,freq=0;
        while(r<n){
            mapp[s[r]]++;
            freq=max(freq,mapp[s[r]]);
            if(r-l+1-freq>k){
                mapp[s[l]]--;
                l++;
            }
            cnt=max(cnt,r-l+1);
            r++;
        }
        return cnt;
    }
};