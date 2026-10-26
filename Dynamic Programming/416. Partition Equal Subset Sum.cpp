class Solution {
public:
     bool isSubsetSum(vector<int>arr, int target){
        int n= arr.size();
        vector<bool> prev(target+1,0), curr(target+1,0);
        prev[0]=curr[0]=true;
        if(arr[0]<=target)prev[arr[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int tar=1;tar<=target;tar++){
                bool nottake=prev[tar];
                bool take=false;
                if(tar>=arr[ind])
                    take=prev[tar-arr[ind]];
                curr[tar]=take|nottake;
            }
            prev=curr;
        }
        return prev[target];
     }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n= nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2) return false;
        int target=sum/2;
        return isSubsetSum(nums,target);
    }
};