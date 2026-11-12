class Solution{
    const int MOD = 1e9 + 7;
	public:
	int perfectSum(vector<int>&arr, int K){
        int n= arr.size();
        vector<vector<int>> dp(n,vector<int>(K+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        if(arr[0]<=K) dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int sum=0;sum<=K;sum++){
                int nottake=dp[i-1][sum];
                int take=0;
                if(arr[i]<=sum)  take=dp[i-1][sum-arr[i]];
                dp[i][sum]=(take+nottake) % MOD;
            }
        }
        return dp[n-1][K];
	}
};