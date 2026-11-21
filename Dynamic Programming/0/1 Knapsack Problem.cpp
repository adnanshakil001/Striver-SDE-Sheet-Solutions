class Solution{
    public:
        int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
             //your code goes here
             vector<int> prev(W+1,0);
            for(int i=wt[0];i<=W;i++) prev[i]=val[0];
            for(int ind=1;ind<n;ind++){
                for(int i=W;i>=0;i--){
                    
                    int nottake=prev[i];
                    int take=INT_MIN;
                    if(wt[ind]<=i) take=val[ind]+prev[i-wt[ind]];
                     prev[i]=max(take,nottake);
                } 
            }
             return prev[W];
        }
};