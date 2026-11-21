class Solution {
  public:
  const int MOD = 1e9 + 7;
  int f(int ind, int sum, vector<int>&arr, vector<vector<int>>& dp ){
        if (ind == 0) {
            if (sum == 0 && arr[0] == 0) return 2; // take or not take
            if (sum == 0 || arr[0] == sum) return 1; // either empty subset or taking arr[0]
            return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int nottake=f(ind-1,sum,arr,dp);
        int take=0;
        if(arr[ind]<=sum)  take=f(ind-1,sum-arr[ind],arr, dp);
        return dp[ind][sum]=(take+nottake) % MOD;
    }
	int perfectSum(vector<int>&arr, int K){
        int n= arr.size();
        vector<vector<int>> dp(n,vector<int>(K+1,-1));
        return f(n-1,K,arr,dp);
	}
   int countPartitions(int n, int diff, vector<int>& arr) {
        int total=0;
        for(auto &it:arr) total+=it;
        if(total-diff<0 || (total-diff)%2) return false;
        return perfectSum(arr,(total-diff)/2);
    }
};