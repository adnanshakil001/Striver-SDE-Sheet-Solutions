class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            long long a=1;
        vector<int> rrow;
        rrow.push_back(1);
        for(int j=1;j<i;j++){
            a=a*(i-j);
            a=a/j;
            rrow.push_back(a);
        } 
            ans.push_back(rrow);
        }
        return ans;
    }
};