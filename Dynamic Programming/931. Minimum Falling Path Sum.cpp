class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m,0));
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=matrix[i][j];
                else{
                    int up=matrix[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up+=1e9;
                    int upleft=matrix[i][j];
                    if(j>0) upleft+=dp[i-1][j-1];
                    else upleft+=1e9;
                    int upright=matrix[i][j];
                    if(j<m-1) upright+=dp[i-1][j+1];
                    else upright+=1e9;
                    dp[i][j]=min({up,upleft,upright});
                }
            }
        }
        int ans = 1e9;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};