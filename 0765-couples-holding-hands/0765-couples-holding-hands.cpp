class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        int cnt=0;
        for(int i=0;i<n;i+=2){
            int a=row[i]^1;
            if(row[i+1]!=a){
                for(int j=i+2;j<n;j++){
                    if(row[j]==a){
                        swap(row[i+1],row[j]);
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};