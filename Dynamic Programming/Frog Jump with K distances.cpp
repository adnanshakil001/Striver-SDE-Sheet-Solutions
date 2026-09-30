class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        vector<int> dp(n);
        int prev2=0, prev=0;
        for(int i=1;i<n;i++){
            int fs=prev+abs(stones[i]-stones[i-1]);
            int ss=INT_MAX;
            if(i>1) ss= prev2+abs(stones[i]-stones[i-2]);
            int curri=min(fs,ss);
            prev2=prev;
            prev=curri;
            
        }
        return prev;
    }
};