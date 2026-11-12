class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
    int total=0;
    int n=stones.size();
        for(int i=0;i<n;i++) total+=stones[i];
        int k=total;
        vector<bool> prev(k+1,0), curr(k+1,0);
        prev[0]=curr[0]=true;
        prev[stones[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int tar=1;tar<=k;tar++){
                bool nottake=prev[tar];
                bool take=false;
                if(tar>=stones[ind])
                    take=prev[tar-stones[ind]];
                curr[tar]=take|nottake;
            }
            prev=curr;
        }
        int mini=1e9;
        for(int s1=0;s1<=total/2;s1++){
            if(prev[s1]==true){
                mini=min(mini,abs((total-s1)-s1));
            }
        }
    return mini;
	}     
    
};