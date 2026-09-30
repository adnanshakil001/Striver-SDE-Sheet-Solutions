class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> dp(n);
        int prev2=0, prev=0;
        for(int i=1;i<n;i++){
            int fs=prev+abs(height[i]-height[i-1]);
            int ss=INT_MAX;
            if(i>1) ss= prev2+abs(height[i]-height[i-2]);
            int curri=min(fs,ss);
            prev2=prev;
            prev=curri;
            
        }
        return prev;
        
    }
};