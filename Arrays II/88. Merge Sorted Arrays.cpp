class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1, rt=n-1, k=m+n-1;
        while(left>=0 && rt>=0){
            if(nums1[left]>nums2[rt]){
                nums1[k--] = nums1[left--];
                
            }else{ nums1[k--] = nums2[rt--]; }
        }
        while (rt >= 0) {
            nums1[k--] = nums2[rt--];
        }
    }
};