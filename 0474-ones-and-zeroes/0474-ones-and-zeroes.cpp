class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(auto& str:strs){
            int zero=0,ones=0;
            for(char c:str){
                if(c=='0')zero++;
                else ones++;
            }
            for(int i=m;i>=zero;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j]=max(dp[i][j],dp[i-zero][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};